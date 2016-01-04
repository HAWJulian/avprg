#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QAudioInput>
#include <QAudioDecoder>
#include <QAudioFormat>
#include <math.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , audioPlayer(this)

{
    // Setup UI
    ui->setupUi(this);
    initializeAudio();

    // Fenster nicht vergößerbar:
    this->setWindowFlags(this->windowFlags() | Qt::MSWindowsFixedSizeDialogHint);

    // Waveform Plot - Hintergrund färben & Achsen ausblenden
    ui->plot->setBackground(QColor(40, 40, 40));
    ui->plot->xAxis->setVisible(false);
    ui->plot->yAxis->setVisible(false);

    // Position durch klicken in die Waveform wählbar...
    connect(ui->plot, SIGNAL(mousePress(QMouseEvent*)), this, SLOT(mouseRelease(QMouseEvent*)));

}

// Destruktor
MainWindow::~MainWindow()
{
    delete ui;
}

// Audio initialisieren
void MainWindow::initializeAudio(){

    // Startwert Frequenzslider Filter
    on_frequencySlider_valueChanged(ui->frequencySlider->value());

    // Startwert Hüllkurve -> Attack
    on_dialAttack_valueChanged(ui->dialAttack->value());
    // Labelwert setzen
    ui->labelAttack->setNum(ui->dialAttack->value()/100.f);

    // Startwert Hüllkurve -> Hold
    on_dialHold_valueChanged(ui->dialHold->value());
    // Labelwert setzen
    ui->labelHold->setNum(ui->dialHold->value()/100.f);

    // Startwert Hüllkurve -> Release
    on_dialRelease_valueChanged(ui->dialRelease->value());
    // Labelwert setzen
    ui->labelRelease->setNum(ui->dialRelease->value()/100.f);

    // Audioquelle auf GranularSynthesis setzen
    audioPlayer.setAudioSource(&granularSynthesis);
    // Start audio
    audioPlayer.start();

}


/*
 *
 *
 *  WAVEFORM PLOT
 *  Waveform zeichnen & Cursor zeichnen
 *
*/

// Methode, um Waveform zu zeichnen
void MainWindow::drawWaveform() {

    // Zwei Graphen erstellen
    ui->plot->addGraph();
    ui->plot->addGraph();

    // Beide Graphen: selbe Farbe zeichnen und Füllen
    ui->plot->graph(0)->setPen(QPen(QColor(60, 220, 170, 255)));
    ui->plot->graph(1)->setPen(QPen(QColor(60, 220, 170, 255)));
    ui->plot->graph(0)->setBrush(QBrush(QColor(60, 220, 170, 255)));
    ui->plot->graph(1)->setBrush(QBrush(QColor(60, 220, 170, 255)));

    // Es werden 5000 Werte der Waveform gezeichnet
    int values = 5000;
    // damit wird nur jeder x. Wert gezeichnet (x=samplesstep)
    int samplesstep = (granularSynthesis.file.data.size() / values);

    // Über ein Intervall dieser Größe wird ein Wert integriert,
    // der dann gezeichnet werden soll
    int sumupinterval = samplesstep/2;

    // Vektoren für die X und Y Daten anlegen
    QVector<double> x(values), y(values), y2(values);

    // Alle zu zeichnenden Werte durchgehen
    for (int i=0; i<values; i++)
    {
        // x-Wert zuweisen
        x[i] = i;

        // Von wo (Startsample) bis (Endsampple) integriert werden soll.
        // linke Grenze: (& Randproblem)
        int von = i*samplesstep-sumupinterval;
        if (von < 0) { von = 0; }

        // rechte Grenze: (& Randproblem)
        int bis = i*samplesstep+sumupinterval;
        if (bis >= granularSynthesis.file.data.size()) { bis = granularSynthesis.file.data.size()-1; }

        // Samples durchlaufen und Absolutwert für den y-Wert aufaddieren
        for (int k = von; k < bis; k++) {
            y[i] += ((double) std::abs(granularSynthesis.file.data[k]));
        }

        // Durch das Intervall teilen:
        y[i] /= sumupinterval;
        // Der zweite Graph zeigt den gleichen Wert in negativ unterhalb der x-Achse
        // ("schöne Waveform")
        y2[i] = -y[i];
    }

    // Daten setzen
    ui->plot->graph(0)->setData(x, y);
    ui->plot->graph(1)->setData(x, y2);

    // Achsendimensionen anpassen
    ui->plot->rescaleAxes();

    // Plot zeichnen
    ui->plot->replot();

}


void MainWindow::drawCursor(QCustomPlot *customPlot, QCPCursor *cursor, double x, QPen pen)
{

    // Wenn schon eine vertikale Linie (Waveform-Cursor) gesetzt ist, diesen löschen
    if(cursor->vLine) customPlot->removeItem(cursor->vLine);

    // Neue vertikale Linie (Waveform-Cursor) setzen
    cursor->vLine = new QCPItemLine(customPlot);
    customPlot->addItem(cursor->vLine);

    // Neue vertikale Linie (Waveform-Cursor) in die Waveform zeichnen
    cursor->vLine->setPen(pen);
    cursor->vLine->start->setCoords( x, QCPRange::minRange);
    cursor->vLine->end->setCoords( x, QCPRange::maxRange);

    // Waveform/Plot zeichnen
    customPlot->replot();

}

// Wenn die Maus in der Waveform-Darstellung gedrückt wird:
void MainWindow::mouseRelease(QMouseEvent* event)
{
    // Plot zuweisen
    QCustomPlot *customPlot=ui->plot;

    // x-Koordinate der Mausposition im Plotfenster
    double x = customPlot->xAxis->pixelToCoord(event->pos().x());

    // Skalierung auf den Positionsslider
    int index = (int) ((x/5000.)*10000);
    // Positionsslider setzen
    ui->posSlider->setValue(index);
}

/*
 *
 *
 *  OPEN WAV
 *  Neue Wav-Datei laden
 *
*/
void MainWindow::on_openWAVButton_clicked()
{
    // Neue Wave-Datei: GranularSynthesis sperren
    granularSynthesis.lock();
    // Position in der Wavedatei auf 0 setzen
    ui->posSlider->setValue(0);

    // Open-Dialog
    QString fileURL = QFileDialog::getOpenFileName(this, tr("Open WAV File"), "", tr("WAV (*.wav)"));
    std::string fileURL_str = fileURL.toUtf8().constData();

    // Wenn eine Datei ausgewählt wurde
    if (fileURL_str == "") {
        qDebug() << "no file";
    } else {
        // ... dann setze die Datei im GranularSynthesis
        granularSynthesis.setFile(fileURL_str);
        // und zeichne die neue Waveform
        this->drawWaveform();
    }
}

/*
 *
 *
 *  GRAIN POSITION
 *  Position in der Wavedatei
 *
*/
void MainWindow::on_posSlider_valueChanged(int value)
{
    // Positionsslider Wert in float 0...1 umwandeln
    float value_f = value/100.;

    // In x-Koordinate umwandeln für den Waveform-Cursor
    double x = (value_f / 100.) * 5000;

    // Plot zuweisen
    QCustomPlot *customPlot=ui->plot;
    // Neuen Cursor an der neuen Position zeichnen
    drawCursor(customPlot, &cursor, x, QPen(Qt::white, 2, Qt::SolidLine, Qt::SquareCap, Qt::RoundJoin));

    // Position im Granularsynthesizer setzen
    granularSynthesis.setPosition(value_f);
}
void MainWindow::on_posRandSlider_valueChanged(int value)
{
    // Neuen Zufallsparameter für die Position im GranularSynthesis setzen
    granularSynthesis.setPositionRandom(value);
}

/*
 *
 *
 *  FILTER
 *
 *
*/
void MainWindow::on_filtertypeCombobox_activated(int index)
{
    // Neuen Filtertyp im GranularSynthesis setzen
    granularSynthesis.setFilterType(index);
}
void MainWindow::on_frequencySlider_valueChanged(int value)
{
    // Wert "value" in Frequenz wandeln
    // 0 ... 100% --> 20Hz ... 20000Hz
    float scaledValue = 3 * value / 100.f + 1;
    float frequency = 2*pow(10, scaledValue);

    // Neuen Frequenzwert als Label setzen
    ui->frequencyLabel->setText(QString::number((int)frequency));

    // Frequenzwert im GranularSynthesis setzen
    granularSynthesis.setFrequency(frequency);
}
void MainWindow::on_qSlider_valueChanged(int value)
{
    // Neue Filtergüte im GranularSynthesis setzen
    granularSynthesis.setFilterQ(value);
}


/*
 *
 *
 *  HÜLLKURVE
 *
 *
*/
void MainWindow::on_dialAttack_valueChanged(int value)
{
    // Neues Hüllkurvenintervall (ATTACK) im GranularSynthesis setzen
    granularSynthesis.setAttackSeconds(value/100.f);
    // Neuen Wert als Label setzen
    ui->labelAttack->setNum(ui->dialAttack->value()/100.f);
}

void MainWindow::on_dialHold_valueChanged(int value)
{
    // Neues Hüllkurvenintervall (HOLD) im GranularSynthesis setzen
    granularSynthesis.setHoldSeconds(value/100.f);
    // Neuen Wert als Label setzen
    ui->labelHold->setNum(ui->dialHold->value()/100.f);
}


void MainWindow::on_dialRelease_valueChanged(int value)
{
    // Neues Hüllkurvenintervall (RELEASE) im GranularSynthesis setzen
    granularSynthesis.setReleaseSeconds(value/100.f);
    // Neuen Wert als Label setzen
    ui->labelRelease->setNum(ui->dialRelease->value()/100.f);
}

/*
 *
 *
 *  GRAIN RATE
 *  Wie oft pro Sekunde entsteht ein neuer Grain?
 *
*/
void MainWindow::on_rateSlider_valueChanged(int value)
{
    // Neue Rate im GranularSynthesis setzen
    granularSynthesis.setRate(value);
}


/*
 *
 *
 *  SPREAD
 *  Stereobreite
 *
*/
void MainWindow::on_spreadSlider_valueChanged(int value)
{
    // Neuen Spread-Wert im GranularSynthesis setzen
    granularSynthesis.setSpread(value);
}

/*
 *
 *
 *  VOLUME
 *
 *
*/
void MainWindow::on_volRandSlider_valueChanged(int value)
{
    float value_f = value/100.;
    granularSynthesis.setGrainGainRandom(value_f);
}

void MainWindow::on_volumeSlider_valueChanged(int value)
{
    granularSynthesis.setGrainGain(value);
}

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
    ui->setupUi(this);
    initializeAudio();
    initializeMidi();

    // Fenster nicht vergößerbar:
    this->setWindowFlags(this->windowFlags() | Qt::MSWindowsFixedSizeDialogHint);

    // Waveform Plot - Hintergrund färben & Achsen ausblenden
    ui->plot->setBackground(QColor(40, 40, 40));
    ui->plot->xAxis->setVisible(false);
    ui->plot->yAxis->setVisible(false);


    // Position durch klicken in die Waveform wählbar...
    connect(ui->plot, SIGNAL(mousePress(QMouseEvent*)), this, SLOT(mouseRelease(QMouseEvent*)));

}

void MainWindow::drawWaveform() {

    ui->plot->addGraph();
    ui->plot->addGraph();
    ui->plot->graph(0)->setPen(QPen(QColor(60, 220, 170, 255)));
    ui->plot->graph(1)->setPen(QPen(QColor(60, 220, 170, 255)));
    ui->plot->graph(0)->setBrush(QBrush(QColor(60, 220, 170, 255)));
    ui->plot->graph(1)->setBrush(QBrush(QColor(60, 220, 170, 255)));

    int values = 5000;
    int samplesstep = (granularSynthesis.file.data.size() / values);
    int sumupinterval = samplesstep/2;

    QVector<double> x(values), y(values), y2(values);
    for (int i=0; i<values; i++)
    {
        x[i] = i;

        int von = i*samplesstep-sumupinterval;
        if (von < 0) { von = 0; }
        int bis = i*samplesstep+sumupinterval;
        if (bis >= granularSynthesis.file.data.size()) { bis = granularSynthesis.file.data.size()-1; }

        for (int k = von; k < bis; k++) {
            y[i] += ((double) std::abs(granularSynthesis.file.data[k]));
        }

        y[i] /= sumupinterval;
        y2[i] = -y[i];
    }

    ui->plot->graph(0)->setData(x, y);
    ui->plot->graph(1)->setData(x, y2);

    ui->plot->rescaleAxes();

    ui->plot->replot();

}

void MainWindow::onControllerMidi(int channel, int data1, int data2) {

    int index = (int) ((data2/127.)*10000);
    ui->posSlider->setValue(index);

}


void MainWindow::ManageCursor(QCustomPlot *customPlot, QCPCursor *cursor, double x, QPen pen)
{

        if(cursor->vLine) customPlot->removeItem(cursor->vLine);
        cursor->vLine = new QCPItemLine(customPlot);
        customPlot->addItem(cursor->vLine);
        cursor->vLine->setPen(pen);
        cursor->vLine->start->setCoords( x, QCPRange::minRange);
        cursor->vLine->end->setCoords( x, QCPRange::maxRange);

}

void MainWindow::mouseRelease(QMouseEvent* event)
{
    QCustomPlot *customPlot=ui->plot;
    double x=customPlot->xAxis->pixelToCoord(event->pos().x());
    int index = (int) ((x/5000.)*10000);
    ui->posSlider->setValue(index);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::initializeAudio(){

    on_frequencySlider_valueChanged(ui->frequencySlider->value());

    on_gainSlider_valueChanged(ui->gainSlider->value());

    on_dialAttack_valueChanged(ui->dialAttack->value());
    ui->labelAttack->setNum(ui->dialAttack->value()/100.f);

    on_dialHold_valueChanged(ui->dialHold->value());
    ui->labelHold->setNum(ui->dialHold->value()/100.f);

    on_dialRelease_valueChanged(ui->dialRelease->value());
    ui->labelRelease->setNum(ui->dialRelease->value()/100.f);

    audioPlayer.setAudioSource(&granularSynthesis);
    audioPlayer.start();

}

void MainWindow::initializeMidi(){

    QStringList connections = midiInput.connections(true);
    ui->comboMidiInputBox->addItems(connections);
    if (connections.size() > 0){
        on_comboMidiInputBox_activated(ui->comboMidiInputBox->currentText());
    }

    connect(&midiInput, SIGNAL(midiController(int,int,int)), this, SLOT(onControllerMidi(int,int,int)));

}

void MainWindow::on_frequencySlider_valueChanged(int value)
{
    // 0 ... 100% --> 20Hz ... 20000Hz
    float scaledValue = 3 * value / 100.f + 1;
    float frequency = 2*pow(10, scaledValue);

    ui->frequencyLabel->setText(QString::number((int)frequency));
    granularSynthesis.setFrequency(frequency);
}

void MainWindow::on_filtertypeCombobox_activated(int index)
{
    granularSynthesis.setFilterType(index);
}

void MainWindow::on_qSlider_valueChanged(int value)
{
    granularSynthesis.setFilterQ(value);
}


void MainWindow::on_gainSlider_valueChanged(int value)
{
    granularSynthesis.setFilterGain(value);
    ui->GainLabel->setNum(ui->gainSlider->value());
}

void MainWindow::on_dialAttack_valueChanged(int value)
{
    granularSynthesis.setAttackSeconds(value/100.f);
    ui->labelAttack->setNum(ui->dialAttack->value()/100.f);
}

void MainWindow::on_dialHold_valueChanged(int value)
{
    granularSynthesis.setHoldSeconds(value/100.f);
    ui->labelHold->setNum(ui->dialHold->value()/100.f);
}


void MainWindow::on_dialRelease_valueChanged(int value)
{
    granularSynthesis.setReleaseSeconds(value/100.f);
    ui->labelRelease->setNum(ui->dialRelease->value()/100.f);
}

void MainWindow::on_comboMidiInputBox_activated(const QString &string)
{
    midiInput.open(string);
}

void MainWindow::on_rateSlider_valueChanged(int value)
{
    granularSynthesis.setRate(value);
}

void MainWindow::on_posSlider_valueChanged(int value)
{
    float value_f = value/100.;

    double x = (value_f / 100.) * 5000;

    QCustomPlot *customPlot=ui->plot;

    ManageCursor(customPlot, &cursor, x, QPen(Qt::white, 2, Qt::SolidLine, Qt::SquareCap, Qt::RoundJoin));
    customPlot->replot();

    granularSynthesis.setPosition(value_f);
}

void MainWindow::on_openWAVButton_clicked()
{
    granularSynthesis.lock();
    ui->posSlider->setValue(0);
    QString fileURL = QFileDialog::getOpenFileName(this, tr("Open WAV File"), "D:\avprgprojekt\avprg\Anwendung", tr("WAV (*.wav)"));
    std::string fileURL_str = fileURL.toUtf8().constData();

    if (fileURL_str == "") {
        qDebug() << "no file";
    } else {
        granularSynthesis.setFile(fileURL_str);
        this->drawWaveform();
    }
}


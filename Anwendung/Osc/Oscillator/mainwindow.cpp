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


    // The following plot setup is mostly taken from the plot demos:
    ui->plot->addGraph();
    ui->plot->addGraph();
    ui->plot->graph(0)->setPen(QPen(QColor(60, 220, 170, 255)));
    ui->plot->graph(1)->setPen(QPen(QColor(60, 220, 170, 255)));
    ui->plot->graph(0)->setBrush(QBrush(QColor(60, 220, 170, 255)));
    ui->plot->graph(1)->setBrush(QBrush(QColor(60, 220, 170, 255)));

    int values = 1000;
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

    ui->plot->setBackground(QColor(40, 40, 40));

    ui->plot->xAxis->setVisible(false);
    ui->plot->yAxis->setVisible(false);

    ui->plot->rescaleAxes();
    ui->plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

    ui->horizontalScrollBar->setRange(0, values);

    connect(ui->horizontalScrollBar, SIGNAL(valueChanged(int)), this, SLOT(horzScrollBarChanged(int)));


}

void MainWindow::horzScrollBarChanged(int value)
{
  if (qAbs(ui->plot->xAxis->range().center()-value/100.0) > 0.01) // if user is dragging plot, we don't want to replot twice
  {
    ui->plot->xAxis->setRange(value/100.0, ui->plot->xAxis->range().size(), Qt::AlignCenter);
    ui->plot->replot();
  }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::initializeAudio(){
    on_frequencySlider_valueChanged(ui->frequencySlider->value());
    on_gainSlider_valueChanged(ui->gainSlider->value());
    on_dialAttack_valueChanged(ui->dialAttack->value());
    ui->labelAttack->setNum(ui->dialAttack->value());
    on_dialDecay_valueChanged(ui->dialDecay->value());
    ui->labelDecay->setNum(ui->dialDecay->value());
    on_dialSustain_valueChanged(ui->dialSustain->value());
    ui->labelSustain->setNum(ui->dialSustain->value());
    on_dialRelease_valueChanged(ui->dialRelease->value());
    ui->labelRelease->setNum(ui->dialRelease->value());

    audioPlayer.setAudioSource(&granularSynthesis);
    audioPlayer.start();
}

void MainWindow::initializeMidi(){

    QStringList connections = midiInput.connections(true);
    ui->comboMidiInputBox->addItems(connections);
    if (connections.size() > 0){
        on_comboMidiInputBox_activated(ui->comboMidiInputBox->currentText());
    }

    connect(&midiInput, SIGNAL(midiNoteOn(const int, const int, const int)), this, SLOT(onMidiNoteOn(const int, const int, const int)));
    connect(&midiInput, SIGNAL(midiNoteOff(const int, const int, const int)), this, SLOT(onMidiNoteOff(const int, const int, const int)));

}

void MainWindow::onMidiNoteOff(const int chan, const int note, const int vel){
    //prependMessage(QString("note off: ch=%1 note=%2 vel=%3\n").arg(chan).arg(note).arg(vel));
}

void MainWindow::onMidiNoteOn(const int chan, const int note, const int vel){
    if (vel == 0){
        onMidiNoteOff(chan, note, vel);
    }
    //prependMessage(QString("note on:  ch=%1 note=%2 vel=%3\n").arg(chan).arg(note).arg(vel));
}


void MainWindow::on_frequencySlider_valueChanged(int value)
{
    // 0 ... 100% --> 100Hz ... 10000Hz
    float scaledValue = 2 * value / 100.f + 2;
    float frequency = pow(10, scaledValue);

    ui->frequencyLabel->setText(QString::number((int)frequency));
    granularSynthesis.setFrequency(frequency);
}

void MainWindow::on_waveformCombobox_activated(int index)
{
    granularSynthesis.setSelectedOscillator(index);
}

void MainWindow::on_gainSlider_valueChanged(int value)
{
    granularSynthesis.setGain(value);
}


void MainWindow::on_note_1_clicked(bool checked)
{
    qDebug() << "note 1";

    if (checked){
        granularSynthesis.setNote(60);
        granularSynthesis.noteOn();
    }
    else{
        granularSynthesis.noteOff();
    }
}
void MainWindow::on_note_2_clicked(bool checked)
{
    if (checked){
        granularSynthesis.setNote(61);
        granularSynthesis.noteOn();
    }
    else{
        granularSynthesis.noteOff();
    }
}
void MainWindow::on_note_3_clicked(bool checked)
{
    if (checked){
        granularSynthesis.setNote(62);
        granularSynthesis.noteOn();
    }
    else{
        granularSynthesis.noteOff();
    }
}
void MainWindow::on_note_4_clicked(bool checked)
{
    if (checked){
        granularSynthesis.setNote(63);
        granularSynthesis.noteOn();
    }
    else{
        granularSynthesis.noteOff();
    }
}
void MainWindow::on_note_5_clicked(bool checked)
{
    if (checked){
        granularSynthesis.setNote(64);
        granularSynthesis.noteOn();
    }
    else{
        granularSynthesis.noteOff();
    }
}
void MainWindow::on_note_6_clicked(bool checked)
{
    if (checked){
        granularSynthesis.setNote(65);
        granularSynthesis.noteOn();
    }
    else{
        granularSynthesis.noteOff();
    }
}
void MainWindow::on_note_7_clicked(bool checked)
{
    if (checked){
        granularSynthesis.setNote(66);
        granularSynthesis.noteOn();
    }
    else{
        granularSynthesis.noteOff();
    }
}
void MainWindow::on_note_8_clicked(bool checked)
{
    if (checked){
        granularSynthesis.setNote(67);
        granularSynthesis.noteOn();
    }
    else{
        granularSynthesis.noteOff();
    }
}
void MainWindow::on_note_9_clicked(bool checked)
{
    if (checked){
        granularSynthesis.setNote(68);
        granularSynthesis.noteOn();
    }
    else{
        granularSynthesis.noteOff();
    }
}
void MainWindow::on_note_10_clicked(bool checked)
{
    if (checked){
        granularSynthesis.setNote(69);
        granularSynthesis.noteOn();
    }
    else{
        granularSynthesis.noteOff();
    }
}
void MainWindow::on_note_11_clicked(bool checked)
{
    if (checked){
        granularSynthesis.setNote(70);
        granularSynthesis.noteOn();
    }
    else{
        granularSynthesis.noteOff();
    }
}
void MainWindow::on_note_12_clicked(bool checked)
{
    if (checked){
        granularSynthesis.setNote(71);
        granularSynthesis.noteOn();
    }
    else{
        granularSynthesis.noteOff();
    }
}

void MainWindow::on_dialAttack_valueChanged(int value)
{
    granularSynthesis.setAttackSeconds(value/100.f);
}

void MainWindow::on_dialDecay_valueChanged(int value)
{
    granularSynthesis.setDecaySeconds(value/100.f);
}

void MainWindow::on_dialSustain_valueChanged(int value)
{
    granularSynthesis.setSustain_dB(value - 100);
}

void MainWindow::on_dialRelease_valueChanged(int value)
{
    granularSynthesis.setReleaseSeconds(value/100.f);
}

void MainWindow::on_comboMidiInputBox_activated(const QString &arg1)
{

}

void MainWindow::on_rateSlider_valueChanged(int value)
{
    granularSynthesis.setRate(value);
}

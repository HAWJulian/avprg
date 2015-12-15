#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QAudioOutput>
#include "audioplayer.h"
#include "granularsynthesis.h"
#include "midiinput.h"

#include "qcustomplot/qcustomplot.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_frequencySlider_valueChanged(int value);

    void on_filtertypeCombobox_activated(int index);

    void on_gainSlider_valueChanged(int value);

    void on_dialAttack_valueChanged(int value);

    void on_dialHold_valueChanged(int value);

    void on_dialRelease_valueChanged(int value);

    void on_comboMidiInputBox_activated(const QString &string);

    void onControllerMidi(int channel, int data1, int data2);

    void on_rateSlider_valueChanged(int value);

    void mouseRelease(QMouseEvent* event);

    void on_posSlider_valueChanged(int value);

    void on_openWAVButton_clicked();


    void on_qSlider_valueChanged(int value);

private:
    typedef struct {
        QCPItemLine *vLine;
    } QCPCursor;
    void initializeAudio();
    void initializeMidi();
    void ManageCursor(QCustomPlot *customPlot, QCPCursor *cursor, double x, QPen pen);
    void drawWaveform();
    Ui::MainWindow *ui;
    GranularSynthesis granularSynthesis;
    AudioPlayer audioPlayer;
    drumstick::rt::MIDIInput midiInput;
    QCPCursor cursor;

};

#endif // MAINWINDOW_H

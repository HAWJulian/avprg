
#ifndef ASDF_H
#define ASDF_H

#include <QMainWindow>
#include <QFile>
#include <QtMultimedia/QAudioOutput>
#include "audioplayer.h"
#include "granularsynthesis.h"

#include "qcustomplot/qcustomplot.h"
#include "cvmattoqimage.h"
namespace Ui {
class asdf;
}

class asdf : public QMainWindow
{
    Q_OBJECT

public:
    explicit asdf(QWidget *parent = 0);
    ~asdf();
    void getData(int y);
private slots:
    // Waveform Mausklick -> Cursor zeichnen
    void mouseRelease(QMouseEvent* event);


    /*
     *  OPEN WAV
    */
    void on_openWAVButton_clicked();


    /*
     *  GRAIN POSITION
     *  Position in der Wavedatei
    */
    void on_posSlider_valueChanged(int value);
    void on_posRandSlider_valueChanged(int value);


    /*
     *  FILTER
    */
    void on_filtertypeCombobox_activated(int index);
    void on_frequencySlider_valueChanged(int value);
    void on_qSlider_valueChanged(int value);


    /*
     *  HÜLLKURVE
    */
    void on_dialAttack_valueChanged(int value);
    void on_dialHold_valueChanged(int value);
    void on_dialRelease_valueChanged(int value);


    /*
     *  GRAIN RATE
     *  Wie oft pro Sekunde entsteht ein neuer Grain?
    */
    void on_rateSlider_valueChanged(int value);

    /*
     *  SPREAD
     *  Stereobreite
    */
    void on_spreadSlider_valueChanged(int value);

    /*
     *  VOLUME
    */
    void on_volumeSlider_valueChanged(int value);
    void on_volRandSlider_valueChanged(int value);

private:


    /*
     *  WAVEFORM PLOT
     *  Waveform zeichnen & Cursor zeichnen
    */
    // Waveform zeichnen
    void drawWaveform();
    // Waveform-Cursor
    typedef struct {
        QCPItemLine *vLine;
    } QCPCursor;
    QCPCursor cursor;
    // Waveform Cursor zeichnen
    void drawCursor(QCustomPlot *customPlot, QCPCursor *cursor, double x, QPen pen);


    // UI-Hauptfenster
    Ui::asdf *ui;

    // GranularSynthesis (Synthesizer)
    GranularSynthesis granularSynthesis;

    // Audioplayer
    AudioPlayer audioPlayer;

    // Audio initialisieren
    void initializeAudio();

};

#endif // ASDF_H

#ifndef GRANULARSYNTHESIS_H
#define GRANULARSYNTHESIS_H

#include <QVector>
#include <string>

#include "audiosource.h"
#include "grain.h"

#include "filter.h"

// Strukturelement für ein WAV-File
struct Wav
{
    bool okay; // Gültiges WAV?
    int fs; // Abtastfrequenz
    int bits; //  Auflösung (16 Bit, ...)
    int channel; // Anzahl der Kanäle
    int length; // Länge der Sounddaten in Samples
    QVector<float> data; // Sounddaten als Sample-Vector
};

// Strukturelement für ein Sample-Paket (links & rechts)
struct sampleLR {
    float sampleL;
    float sampleR;
};

class GranularSynthesis: public AudioSource
{
public:
    GranularSynthesis();

    // Audioformat zurückgeben
    virtual const QAudioFormat& format() const;

    // Auslesen des Buffers, hier werden die Samples an die Soundkarte übergeben
    virtual qint64 read(float** buffer, qint64 numFrames);

    virtual void start();
    virtual void stop();

    // Filterparameter ändern
    void setFilterType(int index);
    void setFilterQ(float value);
    void setFilterGain(float value);
    void setFrequency(float frequency);
    // Alle Filtereinstellungen am Filter ändern
    void setNewFilterValues();

    // Grain-Global
    void setPosition(float position);
    void setPositionRandom(int positionrandom);

    // Grain gain setzen
    void setGrainGain(float value);
    void setGrainGainRandom(float value);

    // Grain Erstellungsrate setzen
    void setRate(int value);

    // Spread
    void setSpread(int value);

    // Envelope
    void setAttackSeconds(float value);
    void setHoldSeconds(float value);
    void setReleaseSeconds(float value);

    // Neues WAV File setzen
    void setFile(std::string fileURL);
    // Beim Öffnen eines neuen WAV-Files soll der
    // Synthesizer gesperrt werden:
    void lock();

    // Funktion, um WAV Datei-Samples einzulesen
    Wav wavread(std::string wavPath);

public:
    // WAV-Datei
    // public, da Plot aus Samples erstellt wird
    Wav file;
private:
    // Neue Samples für Links und Rechts erstellen
    sampleLR createSample();
private:
    // Audioformat
    QAudioFormat audioFormat;

    // Hilfszeiger für die Erstellung neuer Grains
    int rateIndex;

    // Vector, der alle Grains beinhaltet
    std::vector<Grain> allgrains;

    // Globale Parameter
    // Wie oft wird ein neues Grain erstellt?
    int rate;
    // Wo beginnen die neuen Grains?
    int positionIndex;
    // Position randomize
    int positionRandom;
    // Spread (Stereobreite)
    int spreadValue;
    // Grain gain
    float grainGain;
    // Randomize Gain
    float randomizeGain;

    // Hüllkurve
    float attackSeconds;
    float holdSeconds;
    float releaseSeconds;

    // Ist eine WAV Datei geladen?
    bool fileSet;

    // Filter
    FilterType filter_type;
    double filter_freq;
    double filter_q;
    double filter_gain;

    // Filter für beide Kanäle (links und rechts)
    Filter filter_l;
    Filter filter_r;

};

#endif // GRANULARSYNTHESIS_H

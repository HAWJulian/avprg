#ifndef GRANULARSYNTHESIS_H
#define GRANULARSYNTHESIS_H

#include <QVector>
#include <string>

#include "audiosource.h"
#include "grain.h"
#include "envelope.h"

struct Wav // basic WAVE file structure
{
    int fs; // Samples per Second
    int bits; //  Bits per Sample
    int channel; // Sound Data Channels
    int length; // Sound Data Length
    QVector<float> data; // Sound Samples
};

class GranularSynthesis: public AudioSource
{
public:
    GranularSynthesis();
    virtual const QAudioFormat& format() const;
    virtual qint64 read(float** buffer, qint64 numFrames);
    virtual void start();
    virtual void stop();
    void setSelectedOscillator(int index);
    void setFrequency(float frequency);
    void setNote(int noteNumber);
    void setGain(float decibel);
    void noteOn();
    void noteOff();
    void setAttackSeconds(float value);
    void setDecaySeconds(float value);
    void setReleaseSeconds(float value);
    void setSustain_dB(float value);
    void setRate(int value);

    void outputInfo(QVector<float> data);
    Wav wavread(std::string wavPath);
    Wav file;
    int iter;
private:
    float createSample();
private:
    QAudioFormat audioFormat;
    std::vector<Grain> allgrains;
    int rate;
    Envelope envelope;
};

#endif // GRANULARSYNTHESIS_H

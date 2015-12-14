#ifndef GRANULARSYNTHESIS_H
#define GRANULARSYNTHESIS_H

#include <QVector>
#include <string>

#include "audiosource.h"
#include "grain.h"

#include "filter.h"


struct Wav // basic WAVE file structure
{
    bool okay; // Valid WAV?
    int fs; // Samples per Second
    int bits; //  Bits per Sample
    int channel; // Sound Data Channels
    int length; // Sound Data Length
    QVector<float> data; // Sound Samples
};

struct sampleLR {
    float sampleL;
    float sampleR;
};

class GranularSynthesis: public AudioSource
{
public:
    GranularSynthesis();
    virtual const QAudioFormat& format() const;
    virtual qint64 read(float** buffer, qint64 numFrames);
    virtual void start();
    virtual void stop();

    // Filter
    void setFilterType(int index);
    void setFilterQ(float value);
    void setFilterGain(float value);
    void setFrequency(float frequency);

    // Grain-Global
    void setPosition(float position);
    void setGain(float decibel);

    // Envelope
    void setAttackSeconds(float value);
    void setHoldSeconds(float value);
    void setReleaseSeconds(float value);

    void setRate(int value);

    void setFile(std::string fileURL);
    void lock();

    void outputInfo(QVector<float> data);
    Wav wavread(std::string wavPath);
public:
    Wav file;

private:
    sampleLR createSample();
private:
    QAudioFormat audioFormat;

    int iter;

    std::vector<Grain> allgrains;

    int rate;
    int positionIndex;

    float attackSeconds;
    float holdSeconds;
    float releaseSeconds;

    bool fileSet;

    // Filter
    FilterType filter_type;
    double filter_freq;
    double filter_q;
    double filter_gain;

    Filter filter_l;
    Filter filter_r;


};

#endif // GRANULARSYNTHESIS_H

#ifndef GRAIN
#define GRAIN

#include <QVector>

class Grain{
public:
    enum State {OFF, ATTACK, HOLD, RELEASE};
    Grain(float* grainData, int sampleRate, float releaseSeconds, float attackSeconds, float holdSeconds);
    float getValue();
    float getLeft();
    float getRight();
public:
    bool alive;
private:
    void setState(State state);
    float process(float input);
private:
    float leftv;
    float rightv;
    float* grainData;
    float gain;
    int index;
    float sampleRate;
    State state;
    float gainChange;
    float releaseSeconds;
    float attackSeconds;
    float holdSeconds;
    int holdSamples;
    int totalSamples;
    float sustain_dB;
    float sustainGain;
    float minGain_dB;
    float minGain;
    float overallgain;
};

#endif // GRAIN


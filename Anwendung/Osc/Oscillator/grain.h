#ifndef GRAIN
#define GRAIN

#include <QVector>

class Grain{
public:
    Grain(QVector<float> grainData);
    enum Type {SINE, TRIANGLE, SQUARE, SAW, NOISE};
    void initialize(float sampleRate);
    void setFrequency(float frequency);
    void setType(Type type);
    void setGain(float gain);
    float getValue();
public:
    bool alive;
private:
    float sine();
    float saw();
    float triangle();
    float square();
    float noise();
private:
    QVector<float> grainData;
    int index;
    float sampleRate;
    float frequency;
    float gain;
    Type type;
};

#endif // GRAIN


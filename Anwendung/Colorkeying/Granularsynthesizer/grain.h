#ifndef GRAIN
#define GRAIN

#include <QVector>

class Grain{
public:
    // Hüllkurven-Abschnitte
    enum State {OFF, ATTACK, HOLD, RELEASE};
    // Konstruktor
    Grain(float* grainData, int sampleRate, int spread, float randomizeGain, float gainValue,
          float releaseSeconds, float attackSeconds, float holdSeconds);
    // Aktuellen Grain-Sample-Wert abfragen
    float getValue();
    // Gain für den linken Kanal abfragen
    float getLeft();
    // Gain für den rechten Kanal abfragen
    float getRight();
public:
    // Ist das Grain noch nicht vollständig ausgespielt?
    bool alive;
private:
    // Neuen Hüllkurvenabschnitt setzen
    void setState(State state);
    // Hüllkurve auf ein Sample anwenden
    float process(float input);
private:

    // Gain für linken und rechten Kanal
    float leftv;
    float rightv;

    // Grain-Data-Array (WAV-Samples)
    float* grainData;
    // Index (Zeiger innerhalb der grainData-Array)
    int index;

    // Abtastfrequenz
    float sampleRate;

    // HÜLLKURVE:
    // Hüllkurven-Gain
    float gain;
    // Hüllkurven Gain-Änderung (für jedes Sample)
    float gainChange;
    // Hüllkurven Abschnitt
    State state;
    // Zeitintervalle der Hüllkurvenabschnitte
    float releaseSeconds;
    float attackSeconds;
    float holdSeconds;
    // ... in Samples
    int holdSamples;
    // Gesamtdauer in Samples
    int totalSamples;
    // Gains der Hüllkurvenabschnitte
    float sustain_dB;
    float sustainGain;
    float minGain_dB;
    float minGain;

    // Gesamtgain
    float overallgain;
};

#endif // GRAIN


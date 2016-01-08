#ifndef FILTER_H
#define FILTER_H
#include <string>


const double MINFREQ = 10;
const double MAXQ = 24;
const double MAXGAIN = 24;

enum FilterType{
    LOWPASS,
    HIGHPASS,
    BANDPASS
};

class Filter{
public:
    Filter();
    // Filter initialisieren (Samplerate setzen)
    void initialize(double sampleRate);
    // Filtereinstellungen ändern -> neue Koeffizienten berechnen
    void set(FilterType type, double frequency, double Q, double gain);
    // Filtereinstellungen ändern -> neue Koeffizienten setzen
    void set(double a0, double a1, double a2, double b0, double b1, double b2);
    // Filter auf ein Sample anwenden
    float processOneSample(float input);
private:
    double sampleRate;
    double a, b, c, d, e;
    double x1, x2, y1, y2;
};

#endif

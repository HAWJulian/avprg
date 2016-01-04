#include <math.h>
#include <stdlib.h>
#include "grain.h"
#include <QDebug>

const float MIN_GAIN_DB = -100;

inline float dB2gain(float dB){
    return pow(10, dB/20);
}
inline float gain2dB(float gain){
    return 20*log(gain);
}

Grain::Grain(float* grainData, int sampleRate, int spread, float randomizeGain, float gainValue,
             float releaseSeconds, float attackSeconds, float holdSeconds) {

    // Zeiger auf Position in der WAV-Daten-Array:
    // Zeigt auf den Startwert für diesen Grain:
    this->grainData = grainData;

    // Hüllkurven Gains
    sustainGain = dB2gain(0);
    sustain_dB = 0;
    minGain_dB = MIN_GAIN_DB;
    minGain = dB2gain(MIN_GAIN_DB);

    // Grain wird bei der Erstellung aktiv geschaltet.
    this->alive = true;

    // Samplerate
    this->sampleRate = sampleRate;

    // Envelope
    this->releaseSeconds = releaseSeconds;
    this->attackSeconds = attackSeconds;
    this->holdSeconds = holdSeconds;

    // Berechne die Anzahl an Samples, für die eingestellte Hold-Zeit
    holdSamples = this->attackSeconds*this->sampleRate + this->sampleRate*this->holdSeconds;
    // Berechne die Anzahl an Samples für die gesamte Grain-Dauer
    totalSamples = this->releaseSeconds*this->sampleRate + holdSamples;

    // Start Envelope-Status:
    setState(ATTACK);

    // Zeiger innerhalb des Grains
    index = 0;

    // Spread
    float channeldelta = (spread/100.)*((float) rand()/ RAND_MAX - 0.5);
    leftv = 0.5+channeldelta;
    rightv = 0.5-channeldelta;

    // Randomize Grain gain
    float gainrandom = randomizeGain*((float) rand()/ RAND_MAX);
    overallgain = gainValue*(1-gainrandom);

}

float Grain::getLeft() {
    // Gibt den Gain für den linken Lautsprecher zurück
    return leftv;
}
float Grain::getRight() {
    // Gibt den Gain für den rechten Lautsprecher zurück
    return rightv;
}

float Grain::getValue(){

    // Sofern das Grain noch nicht komplett ausgespielt wurde...
    if (this->alive) {

        // nächstes Sample wählen
        index = index+1;

        // Wenn das Grain entsprechend der Hold-Dauer gespielt wurde,
        // dann beginnt der Release-Abschnitt der Hüllkurve
        if (index == holdSamples) {
            setState(RELEASE);
        }

        // Wenn keine Samples mehr für dieses Grain ausgespielt werden
        // können, dann "stirbt" es.
        if (index == totalSamples) {
            index = 0;
            this->alive = false;
        }

        // Gesamt-Gain für das Grain anwenden und mit "process()" die Hüllkurve anwenden
        return overallgain*process(grainData[index]);

    } else {

        // Wenn dieses Grain schon komplett ausgespielt wurde,
        // dann gibt es keine weiteren Samples mehr zur Ausgabe
        return 0;

    }
}


void Grain::setState(State state){

    // Neuen Envelope-Status setzen:
    this->state = state;

    // Wenn der aktuelle Hüllkurven-Abschnitt "ATTACK" auszuwählen ist,
    // aber keine Attack-Zeit eingestellt wurde, dann springe direkt zum HOLD-State
    if (state == ATTACK && attackSeconds == 0){
        setState(HOLD);
    }
    // Wenn der aktuelle Hüllkurven-Abschnitt "HOLD" auszuwählen ist,
    // aber keine HOLD-Zeit eingestellt wurde, dann springe direkt zum RELEASE-State
    else if (state == HOLD && holdSeconds == 0){
        gain = sustainGain;
        setState(RELEASE);
    }
    // Wenn der aktuelle Hüllkurven-Abschnitt "RELEASE" auszuwählen ist,
    // aber keine RELEASE-Zeit eingestellt wurde, dann springe direkt zum OFF-State
    else if (state == RELEASE && releaseSeconds == 0){
        setState(OFF);
    }
    else {
        // Gain für die Hüllkurve berechnen:

        // OFF-State, Gain = 0
        if (state == OFF){
            gain = 0;
        }
        // ATTACK-State, delta dB = positiv, konst. => gainChange > 1 (als Faktor)
        if (state == ATTACK){
            float gainChange_dB = fabs(MIN_GAIN_DB) / (attackSeconds * sampleRate);
            gainChange = dB2gain(gainChange_dB);
            gain = minGain;
        }
        // HOLD-State, gain ist konstant => gainChange 1 (als Faktor)
        if (state == HOLD){
            gain = sustainGain;
            gainChange = 1;
        }
        // RELEASE-State, delta dB = negativ, konst. => gainChange < 1 (als Faktor)
        if (state == RELEASE){
            float gainChange_dB = fabs(sustain_dB - MIN_GAIN_DB)/(sampleRate * releaseSeconds);
            gainChange =  1/dB2gain(gainChange_dB);
        }
    }
}


float Grain::process(float input){
    // Hiermit wird die Hüllkurve angewendet

    // ATTACK-State, aber gain ist schon auf 1 angewachsen,
    // dann wechsel zum HOLD-State
    if (state == ATTACK && gain >= 1){
        setState(HOLD);
    }

    // RELEASE-State, aber gain ist schon ausreichend abgesunken (minGain),
    // dann wechsel zum OFF-State
    if (state == RELEASE && gain < minGain){
        setState(OFF);
    }

    // Gain entsprechend der Hüllkurve erhöhen/erniedrigen
    gain *= gainChange;

    // Angewandte Hüllkurve auf das Sample zurückgeben:
    return gain * input;
}


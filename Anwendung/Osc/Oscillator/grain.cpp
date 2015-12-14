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

Grain::Grain(float* grainData, int sampleRate, float releaseSeconds, float attackSeconds, float holdSeconds) {

    // Zeiger auf Position in der WAV-Daten-Array:
    // Zeigt auf den Startwert für diesen Grain:
    this->grainData = grainData;

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

    holdSamples = this->attackSeconds*this->sampleRate + this->sampleRate*this->holdSeconds;
    totalSamples = this->releaseSeconds*this->sampleRate + holdSamples;

    // Start Envelope-Status:
    setState(ATTACK);

    // Zeiger innerhalb des Grains
    index = 0;

    leftv = ((float) rand()/ RAND_MAX);
    overallgain = 0.5*((float) rand()/ RAND_MAX) + 0.5;
    rightv = 1-leftv;

}

float Grain::getLeft() {
    return leftv;
}
float Grain::getRight() {
    return rightv;
}

float Grain::getValue(){

    if (this->alive) {

        index = index+1;

        if (index == holdSamples) {
            setState(RELEASE);
        }

        if (index == totalSamples) {
            index = 0;
            this->alive = false;
        }

        return overallgain*process(grainData[index]);

    } else {

        return 0;

    }
}


void Grain::setState(State state){

    // Neuen Envelope-Status setzen:
    this->state = state;

    if (state == ATTACK && attackSeconds == 0){
        setState(HOLD);
    }
    else if (state == HOLD && holdSeconds == 0){
        gain = sustainGain;
        setState(RELEASE);
    }
    else if (state == RELEASE && releaseSeconds == 0){
        setState(OFF);
    }
    else {
        if (state == OFF){
            gain = 0;
        }
        if (state == ATTACK){
            float gainChange_dB = fabs(MIN_GAIN_DB) / (attackSeconds * sampleRate);
            gainChange = dB2gain(gainChange_dB);
            gain = minGain;
        }
        if (state == HOLD){
            gain = sustainGain;
            gainChange = 1;
        }
        if (state == RELEASE){
            float gainChange_dB = fabs(sustain_dB - MIN_GAIN_DB)/(sampleRate * releaseSeconds);
            gainChange =  1/dB2gain(gainChange_dB);
        }
    }
}


float Grain::process(float input){

    if (state == ATTACK && gain >= 1){
        setState(HOLD);
    }
    if (state == RELEASE && gain < minGain){
        setState(OFF);
    }
    gain *= gainChange;

    return gain * input;
}


#include <math.h>
#include <stdlib.h>
#include "grain.h"

const float pi = 3.1415926f;

Grain::Grain(QVector<float> grainData)
: sampleRate(0), index(0), frequency(0), type(SINE), gain(1)
{
    this->grainData = grainData;
    this->alive = true;

}

void Grain::initialize(float sampleRate){
    this->sampleRate = sampleRate;
}
void Grain::setFrequency(float setFrequency){
    frequency = setFrequency;
}
void Grain::setType(Type type){
    this->type = type;
}
void Grain::setGain(float gain){
    this->gain = gain;
}

float Grain::getValue(){

    index = index+1;

    if (index == grainData.size()) {
        index = 0;
        this->alive = false;
    }

    return grainData[index];
}

float Grain::sine(){
    float value = sin(2 * pi * index * frequency / sampleRate);
    index++;
    return gain * value;
}
float Grain::saw(){
    float period = sampleRate / frequency;
    float modulo = fmod(index, period);
    index++;
    float value = (modulo / period) * 2 - 1;
    return gain * value;
}
float Grain::square(){
    float value = sin(2 * pi * index * frequency / sampleRate);
    index++;
    return (value > 0)? gain : -gain;
}
float Grain::triangle(){
    float period = sampleRate / frequency;
    float modulo = fmod(index, period);
    index++;

    float value = (modulo / period) * 4;
    if (value < 2){
        return gain * (value - 1);
    }
    else{
        return gain * (1 + 2 - value);
    }
}
float Grain::noise()
{
    float random = rand();
    return gain * 2 * random / RAND_MAX - 1;
}



#include <math.h>
#include "granularsynthesis.h"
#include <QDebug>
#include <string>
#include <iostream>

#include <fstream>
#include <iterator>

GranularSynthesis::GranularSynthesis()
{
    audioFormat.setCodec("audio/pcm");
    audioFormat.setByteOrder(QAudioFormat::LittleEndian);
    audioFormat.setChannelCount(2);
    audioFormat.setSampleSize(16);
    audioFormat.setSampleType(QAudioFormat::Float);
    audioFormat.setSampleRate(44100);

    // Rate initialisieren (slowest first)
    setRate(1000);

    iter = 0;

    file = wavread("D:\\avprgprojekt\\avprg\\Anwendung\\Osc\\trasure.wav");

    qDebug() << "Anzahl Samples: " << file.data.size();

    //outputInfo(file.data);

    qDebug() << "Anz. Grains: " << allgrains.size();
//    qDebug() << "Anz. Grains: " << allgrains.size();

}

void GranularSynthesis::setRate(int value) {
    this->rate = (value/1000.)*audioFormat.sampleRate();
}

void GranularSynthesis::outputInfo(QVector<float> data)
{
    /*
     * Funktion zum Testen, speichert vector-Werte in Zeilen einer txt Datei
    */

    std::ofstream outputFile;
    outputFile.open("D:\\avprgprojekt\\avprg\\Anwendung\\Osc\\example.txt");

    for (int count = 0; count < 1000000; count++)
    {
        outputFile << data[count] << "\n";
    }

    outputFile.close();
}


void GranularSynthesis::setSelectedOscillator(int index){
   // oscillator.setType((Oscillator::Type)index);
}
void GranularSynthesis::setFrequency(float frequency){
   // oscillator.setFrequency(frequency);
}
void GranularSynthesis::setNote(int noteNumber){
    float frequency = 440.0 * pow(2.0, (noteNumber - 69.0)/12.0);
    setFrequency(frequency);
}

void GranularSynthesis::setGain(float decibel){
    float gain = pow(10, decibel/20.f);
    //oscillator.setGain(gain);
}

void GranularSynthesis::noteOn(){
    envelope.setState(Envelope::ATTACK);
}
void GranularSynthesis::noteOff(){
    envelope.setState(Envelope::RELEASE);
}
void GranularSynthesis::setAttackSeconds(float value){
    envelope.setAttackSeconds(value);
}

void GranularSynthesis::setDecaySeconds(float value){
    envelope.setDecaySeconds(value);
}

void GranularSynthesis::setReleaseSeconds(float value){
    envelope.setReleaseSeconds(value);
}

void GranularSynthesis::setSustain_dB(float value){
    envelope.setSustain_dB(value);
}

void GranularSynthesis::start(){
    //oscillator.initialize(audioFormat.sampleRate());
    envelope.setSampleRate(audioFormat.sampleRate());
}
const QAudioFormat& GranularSynthesis::format() const{
    return audioFormat;
}

float GranularSynthesis::createSample(){
    //float sample = oscillator.getValue();
    //sample = envelope.process(sample);


    if (iter%rate == 0) {
        QVector<float> graindata;
        for (int i = 220000; i<250000; i++) {
            graindata.push_back(file.data[i]);
        }

        Grain newgrain = Grain(graindata);
        allgrains.push_back(newgrain);
    }

    iter++;
    if (iter == 441000) {
        iter = 0;
    }

    float sample = 0.f;


    for(int i=0; i < allgrains.size(); i++){

       if (allgrains[i].alive) {
            sample += allgrains[i].getValue();
       } else {
            allgrains.erase(allgrains.begin()+i);
       }

    }

    return sample;
}

qint64 GranularSynthesis::read(float** buffer, qint64 numFrames){
    // get audio data for left channel
    for(int i = 0; i < numFrames; i++){
        buffer[0][i] = createSample();

    }
    // copy to other channels
    for(int c = 0; c < audioFormat.channelCount(); c++){
        for(int i = 0; i < numFrames; i++){
            buffer[c][i] = buffer[0][i];
        }
    }
    return numFrames;
}
void GranularSynthesis::stop(){}


Wav GranularSynthesis::wavread(std::string wavPath) {

    // input : WAVE file absolute path
    // output : Wav struct

    const char *wavPath_c = wavPath.c_str();
    Wav output;

    FILE *fp;
    errno_t error;
    int n, m;

    char riff_chunkID[4];
    long riff_chunkSize;
    char riff_formType[4];
    char fmt_chunkID[4];
    long fmt_chunkSize;
    short fmt_waveFormatType;
    short fmt_channel;
    long fmt_samplesPerSec;
    long fmt_bytesPerSec;
    short fmt_blockSize;
    short fmt_bitsPerSample;
    char data_chunkID[4];
    long data_chunkSize;
    short data;

    long fmt_extend;
    char find_data_char[2]; // To find "data"
    char find_data_char_old[2]; // To find "data"
    int dataBlockSize; // data size per sample

    if (error = fopen_s(&fp, wavPath_c, "rb") != 0){
        qDebug() << "ERROR : Cannot read wave file. Check file path.";
        output.bits = -1;
        output.channel = -1;
        output.fs = -1;
        output.length = -1;
        return output;
    }

    // RIFF
    fread(riff_chunkID, 1, 4, fp);
    fread(&riff_chunkSize, 4, 1, fp);
    fread(riff_formType, 1, 4, fp);

    // fmt chunk
    fread(fmt_chunkID, 1, 4, fp);
    fread(&fmt_chunkSize, 4, 1, fp); // Linear PCM = 16
    fread(&fmt_waveFormatType, 2, 1, fp);
    fread(&fmt_channel, 2, 1, fp);
    fread(&fmt_samplesPerSec, 4, 1, fp);
    fread(&fmt_bytesPerSec, 4, 1, fp);
    fread(&fmt_blockSize, 2, 1, fp);
    fread(&fmt_bitsPerSample, 2, 1, fp);
    if (fmt_chunkSize != 16){ // if WAVE file is not linear PCM
        qDebug() << "WARNING : This file is not linear PCM";
        qDebug() << "There is a possibility to be malfunctioning.";
        fread(&fmt_extend, fmt_chunkSize -16, 1, fp);
    }

    // data chunk
    fread(data_chunkID, 1, 4, fp);
    if (memcmp(data_chunkID,"data", sizeof(data_chunkID))!=0){// find "data" in the binary data
        fread(find_data_char_old, 1, 2, fp);
        while (1){
            fread(find_data_char, 1, 2, fp);
            if (memcmp(find_data_char_old,"da", sizeof(find_data_char_old))==0 && memcmp(find_data_char,"ta", sizeof(find_data_char))==0) // find "data"
                break;
            find_data_char_old[0] = find_data_char[0];
            find_data_char_old[1] = find_data_char[1];
        }
    }
    fread(&data_chunkSize, 4, 1, fp);

    output.fs = fmt_samplesPerSec;
    output.bits = fmt_bitsPerSample;
    output.length = data_chunkSize / (fmt_bitsPerSample / 8) / fmt_channel;
    output.channel = fmt_channel;

    // read wave data
    dataBlockSize = fmt_blockSize / fmt_channel;
    //if (fmt_channel == 1){
        for (n = 0; n < output.length; n++){
            fread(&data, dataBlockSize, 2, fp);
            float cur_data_sample = (float) data / 32768.0; // normalize in range from -1 to 1
            output.data.push_back(cur_data_sample);
        }
    //}else if(fmt_channel == 2){
        //for (n = 0; n < output.length; n++){
        //    for (m=0; m<2; m++){
        //        fread(&data, dataBlockSize, 1, fp);
        //        output.data(n,m) = (double) data / 32768.0; // normalize in range from -1 to 1
         //   }
        //}
    //}

    fclose(fp);
    return output;
}

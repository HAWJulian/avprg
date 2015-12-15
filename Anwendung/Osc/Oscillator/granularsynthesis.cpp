#include <math.h>
#include "granularsynthesis.h"
#include <QDebug>
#include <string>
#include <iostream>

#include <fstream>
#include <iterator>

GranularSynthesis::GranularSynthesis()
{

    // Audioformat
    audioFormat.setCodec("audio/pcm");
    audioFormat.setByteOrder(QAudioFormat::LittleEndian);
    audioFormat.setChannelCount(2);
    audioFormat.setSampleSize(16);
    audioFormat.setSampleType(QAudioFormat::Float);
    audioFormat.setSampleRate(44100);

    // Default: keine Datei:
    fileSet = false;

    // Rate initialisieren (1 s)
    setRate(1000);

    // Position initialisieren (an den Anfang)
    positionIndex = 0;

    // Envelope
    attackSeconds = 0;
    holdSeconds = 0;
    releaseSeconds = 0;

    // Filter
    filter_type = LOWPASS;
    filter_freq = 500;
    filter_q = 1;
    filter_gain = 0;

    iter = 0;

}

void GranularSynthesis::setFile(std::string fileURL) {
    file = wavread(fileURL);
    fileSet = true;
}

void GranularSynthesis::lock() {
    fileSet = false;
    allgrains.clear();
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
    outputFile.open("D:\\avprgprojekt\\Anwendung\\Osc\\example.txt");

    for (int count = 0; count < 1000000; count++)
    {
        outputFile << data[count] << "\n";
    }

    outputFile.close();
}


void GranularSynthesis::setFilterType(int index) {
    filter_type = (FilterType)index;

    filter_l.set(filter_type, filter_freq, filter_q, filter_gain);
    filter_r.set(filter_type, filter_freq, filter_q, filter_gain);
}

void GranularSynthesis::setFilterQ(float value) {
    this->filter_q = value;

    filter_l.set(filter_type, filter_freq, filter_q, filter_gain);
    filter_r.set(filter_type, filter_freq, filter_q, filter_gain);
}

void GranularSynthesis::setFilterGain(float value) {
    this->filter_gain = value;

    filter_l.set(filter_type, filter_freq, filter_q, filter_gain);
    filter_r.set(filter_type, filter_freq, filter_q, filter_gain);
}

void GranularSynthesis::setFrequency(float frequency){

    this->filter_freq = frequency;

    filter_l.set(filter_type, filter_freq, filter_q, filter_gain);
    filter_r.set(filter_type, filter_freq, filter_q, filter_gain);

}

void GranularSynthesis::setPosition(float position){
    this->positionIndex = (position/100.) * file.data.size();
    //qDebug() << positionIndex;
}

void GranularSynthesis::setAttackSeconds(float value){
    //float gain = pow(10, decibel/20.f);
    //oscillator.setGain(gain);
    this->attackSeconds = value;
}
void GranularSynthesis::setHoldSeconds(float value){
    this->holdSeconds = value;
}
void GranularSynthesis::setReleaseSeconds(float value){
    this->releaseSeconds = value;
}

void GranularSynthesis::start(){
    // Initialize Filter
    filter_l.initialize(audioFormat.sampleRate());
    filter_r.initialize(audioFormat.sampleRate());

    filter_l.set(filter_type, filter_freq, filter_q, filter_gain);
    filter_r.set(filter_type, filter_freq, filter_q, filter_gain);
}

const QAudioFormat& GranularSynthesis::format() const{
    return audioFormat;
}

sampleLR GranularSynthesis::createSample(){

    // Grainberechnung nur, wenn eine WAV-Datei erfolgreich
    // geladen und gesetzt ist...
    if (fileSet) {

        if (iter%rate == 0) {
            //QVector<float> graindata;

            int bigrand = (rand()<<15)|rand();
            //int start = bigrand % file.data.size();
            int start_versatz = bigrand % 2000;
            int start = positionIndex + start_versatz;
            //for (int i = start; i<start+120000; i++) {
            //    graindata.push_back(file.data[i]);
            //}

            Grain newgrain = Grain(&file.data[start], audioFormat.sampleRate(), releaseSeconds, attackSeconds, holdSeconds);
            allgrains.push_back(newgrain);
        }

        iter++;
        if (iter == 4410000) {
            iter = 0;
        }

        float samplel = 0.f;
        float sampler = 0.f;

        for(int i=0; i < allgrains.size(); i++){

           if (allgrains[i].alive) {
                float man = allgrains[i].getValue();
                samplel += allgrains[i].getLeft() * man;
                sampler += allgrains[i].getRight() * man;
           } else {
                allgrains.erase(allgrains.begin()+i);
           }

        }

        sampleLR newLRSamples;

        newLRSamples.sampleL = filter_l.processOneSample(samplel);
        newLRSamples.sampleR = filter_r.processOneSample(sampler);

        return newLRSamples;

    } else {

        // Keine WAV Datei geladen, also kein Audio ausgeben:
        sampleLR newLRSamples;
        newLRSamples.sampleL = 0.0;
        newLRSamples.sampleR = 0.0;

        return newLRSamples;

    }
}

qint64 GranularSynthesis::read(float** buffer, qint64 numFrames){
    // get audio data for left channel
    for(int i = 0; i < numFrames; i++){

        sampleLR nextLRSamples = createSample();

        buffer[0][i] = nextLRSamples.sampleL;

        for(int c = 1; c < audioFormat.channelCount(); c++){
            buffer[c][i] = nextLRSamples.sampleR;
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
        output.okay = false;
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
    output.okay = true;
    return output;
}

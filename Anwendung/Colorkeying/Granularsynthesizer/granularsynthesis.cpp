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
    positionRandom = 1;
    spreadValue = 0;

    // Grain gain (Faktor)
    grainGain = 1;
    // Randomize Grain Gain
    randomizeGain = 0;

    // Envelope
    attackSeconds = 0;
    holdSeconds = 0;
    releaseSeconds = 0;

    // Filter initialisieren
    filter_type = LOWPASS;
    filter_freq = 20000;
    filter_q = 1;
    filter_gain = 0;

    // Hilfszeiger um neue Grains zu erstellen
    rateIndex = 0;

}

// WAV-File setzen
void GranularSynthesis::setFile(std::string fileURL) {
    file = wavread(fileURL);
    fileSet = true;
}

// Beim Öffnen eines neuen WAV-Files soll der
// Synthesizer gesperrt werden:
void GranularSynthesis::lock() {
    // Es ist keine Datei gesetzt:
    fileSet = false;
    // Alle Grains löschen
    allgrains.clear();
}

// Rate setzen
void GranularSynthesis::setRate(int value) {
    this->rate = (value/1000.)*audioFormat.sampleRate();
}

// Alle neuen Filtereinstellungen anwenden/setzen
void GranularSynthesis::setNewFilterValues() {
    filter_l.set(filter_type, filter_freq, filter_q, filter_gain);
    filter_r.set(filter_type, filter_freq, filter_q, filter_gain);
}

// Filter-Typ auswählen
void GranularSynthesis::setFilterType(int index) {
    filter_type = (FilterType)index;
    setNewFilterValues();
}

// Filter-Güte setzen
void GranularSynthesis::setFilterQ(float value) {
    this->filter_q = value;
    setNewFilterValues();
}

// Filterfrequenz setzen
void GranularSynthesis::setFrequency(float frequency){
    this->filter_freq = frequency;
    setNewFilterValues();
}

// Position setzen
void GranularSynthesis::setPosition(float position){
    this->positionIndex = (position/100.) * file.data.size();
}
// Positionsvariation (randomize)
void GranularSynthesis::setPositionRandom(int posrandom){
    if (fileSet) {
        this->positionRandom = (int) (posrandom/100. * audioFormat.sampleRate()/10 + 1);
    } else {
        this->positionRandom = 1;
    }
}

// Spread (Stereobreite) setzen
void GranularSynthesis::setSpread(int value){
    this->spreadValue = value;
}

// Grain gain setzen
void GranularSynthesis::setGrainGain(float value){
    float gain = pow(10, value/20.f);
    this->grainGain = gain;
}
// Grain gain Randomize setzen
void GranularSynthesis::setGrainGainRandom(float value){
    this->randomizeGain = value;
}

// Hüllkurven Setter:
void GranularSynthesis::setAttackSeconds(float value){
    this->attackSeconds = value;
}
void GranularSynthesis::setHoldSeconds(float value){
    this->holdSeconds = value;
}
void GranularSynthesis::setReleaseSeconds(float value){
    this->releaseSeconds = value;
}

// Initialisieren
void GranularSynthesis::start(){
    // Filter initialisieren
    filter_l.initialize(audioFormat.sampleRate());
    filter_r.initialize(audioFormat.sampleRate());

    // Filtereinstellungen setzen
    setNewFilterValues();
}

// Audioformat zurückgeben
const QAudioFormat& GranularSynthesis::format() const{
    return audioFormat;
}

// Neue Samples für Links und Rechts erstellen
sampleLR GranularSynthesis::createSample(){

    // Grainberechnung nur, wenn eine WAV-Datei erfolgreich
    // geladen und gesetzt ist...
    if (fileSet) {

        // Wenn ein neues Grain erstellt werden soll
        if (rateIndex%rate == 0) {

            // Große Zufallszahl
            int bigrand = (rand()<<15)|rand();

            // Randomize
            int start_versatz = bigrand % positionRandom - positionRandom/2;

            // Neuen Start mit randomize berechnen:
            int start = positionIndex + start_versatz;

            // Gesamt Grain Länge
            int totalGrainLength = (int) audioFormat.sampleRate() * (attackSeconds+holdSeconds+releaseSeconds);

            // Achtung: Randprobleme der Audiodatei
            // linke Grenze
            if (start < 0) {
                start = 0;
            }
            // rechte Grenze
            if (start >= file.data.length()-totalGrainLength) {
                start = file.data.length()-totalGrainLength-1;
            }

            // Neues Grain erstellen
            Grain newgrain = Grain(&file.data[start], audioFormat.sampleRate(), spreadValue, randomizeGain, grainGain,
                                   releaseSeconds, attackSeconds, holdSeconds);

            // Grain im Vektor abspeichern
            allgrains.push_back(newgrain);
        }

        // Hilfszeiger einen weiter setzen
        rateIndex++;

        // Nach genügend langer Zeit, beginnt rate von 0 an zu zählen
        if (rateIndex == 4410000) {
            rateIndex = 0;
        }

        // neue Samplewerte für links und rechts
        float samplel = 0.f;
        float sampler = 0.f;

        // Jedes Grain durchgehen
        for(int i=0; i < allgrains.size(); i++){

            // Sofern das aktuelle Grain noch nicht vollständig
            // ausgespielt wurde
            if (allgrains[i].alive) {

                // Grain-Sample Wert abfragen:
                float GrainValue = allgrains[i].getValue();

                // Mit den Gains für links und rechts multiplizieren
                samplel += allgrains[i].getLeft() * GrainValue;
                sampler += allgrains[i].getRight() * GrainValue;

            } else {
                // Grain wurde vollständig ausgespielt, kann also
                // gelöscht werden
                allgrains.erase(allgrains.begin()+i);
            }

        }

        // Strukturelement für neues Samplepaar anlegen
        sampleLR newLRSamples;

        // Filter auf die Samples anwenden.
        newLRSamples.sampleL = filter_l.processOneSample(samplel);
        newLRSamples.sampleR = filter_r.processOneSample(sampler);

        // Sample-Paar (für links und rechts) zurückgeben
        return newLRSamples;

    } else {

        // Keine WAV Datei geladen, also kein Audio ausgeben:
        sampleLR newLRSamples;
        newLRSamples.sampleL = 0.0;
        newLRSamples.sampleR = 0.0;

        return newLRSamples;

    }
}

// Auslesen des Buffers, hier werden die Samples an die Soundkarte übergeben
qint64 GranularSynthesis::read(float** buffer, qint64 numFrames){

    // Für alle geforderten Samples
    for(int i = 0; i < numFrames; i++){

        // Nächstes Sample für links und rechts errechnen
        sampleLR nextLRSamples = createSample();

        // Dem ersten Kanal das linke Sample zuweisen
        buffer[0][i] = nextLRSamples.sampleL;

        for(int c = 1; c < audioFormat.channelCount(); c++){
            // Allen anderen Kanälen das rechte Sample zuweisen
            buffer[c][i] = nextLRSamples.sampleR;
        }

    }

    return numFrames;

}
void GranularSynthesis::stop(){}

// Methode zum Einlesen einer WAV-Datei
Wav GranularSynthesis::wavread(std::string wavPath) {

    // input : WAVE File Dateipfad als String
    // output : WAV Struktur Element

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
    for (n = 0; n < output.length; n++){
        fread(&data, dataBlockSize, 2, fp);
        float cur_data_sample = (float) data / 32768.0; // normalize in range from -1 to 1
        output.data.push_back(cur_data_sample);
    }

    fclose(fp);
    output.okay = true;
    return output;
}

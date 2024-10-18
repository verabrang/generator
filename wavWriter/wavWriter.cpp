
#include <iostream>
#include <fstream>
#include "wavWriter.h"
#include <cmath>

const int bitDepth = 16;

std::vector<int> wavWriter::fromFloatToInt(std::vector<float> signal)
{
    auto maxAmplitude = pow(2, bitDepth - 1) - 1;
    std::vector<int> intSignal(signal.size());

    for(int i = 0; i < signal.size(); i++)
        intSignal[i] = static_cast<int>(signal[i] * maxAmplitude);
    return intSignal;
}


void wavWriter::writeToWav(std::vector<int> signal)
{
    std::ofstream audioFile;
    audioFile.open("waveform.wav", std::ios::binary);


    for(int i = 0; i < signal.size(); i++)
        audioFile.write(reinterpret_cast<char*>(&signal[i]), 2);

}

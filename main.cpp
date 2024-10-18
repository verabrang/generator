
#include "sineOscillator/sineOscillator.h"
#include "noiseMC/noiseMC.h"
#include "signalSummator/signalSummator.h"
#include "wavWriter/wavWriter.h"

#include <iostream>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

int main()
{


    //check niseMC
//    noiseMC noise(0, 1);
//    uint32_t number = 50;
//    std::vector <float> signal1(number);
//    signal1 = noise.genSamples(number);

//    for(int i =0; i < number; i++)
//        std::cout << signal1[i] << std::endl;



    //check signalSummator

    signalInfo signal1;
    signal1.amplitude = 1;
    signal1.freq = 440;
    signal1.timeStart = 5;
    signal1.timeFinish = 10;

    signalInfo signal2;
    signal2.amplitude = 1;
    signal2.freq = 330;
    signal2.timeStart = 3;
    signal2.timeFinish = 10;

    signalInfo signal3;
    signal3.amplitude = 1;
    signal3.freq = 261;
    signal3.timeStart = 0;
    signal3.timeFinish = 10;

    signalSummator sigsumm;
    sigsumm.addSignal(signal1);
    sigsumm.addSignal(signal2);
    sigsumm.addSignal(signal3);
    //sigsumm.turnOnNoise();

    float signalDur = 10;
    std::vector<float> result(sampleRate*signalDur + 1);
    result = sigsumm.makeSummSignalSamples(sampleRate*signalDur);

    auto maxEl = *std::max_element(result.begin(), result.end()); //нормировка
    for(size_t i = 0; i < result.size(); i++)
        result[i] /= maxEl;

    std::vector<int> wavResult;
    wavWriter wav;
    wavResult = wav.fromFloatToInt(result);

    wav.writeToWav(wavResult);

//    for(int i =0; i < result.size(); i++)
//        std::cout<< result[i] << std::endl;
//    for(int i =0; i < wavResult.size(); i++)
//        std::cout<< wavResult[i] << std::endl;

    return 0;
}


#include "sineOscillator/sineOscillator.h"
#include "noiseMC/noiseMC.h"
#include "signalSummator/signalSummator.h"

#include <iostream>
#include <vector>

int main()
{
    //check sine oscillator
//    sineInfo sin1;
//    sin1.amplitude = 1;
//    sin1.duration = 1;
//    sin1.freq = 440;
//    sin1.sampleRate = 44100;

//    sineOscillator oscillator1(sin1);

//    std::vector <float> signal1(sin1.duration*sin1.sampleRate + 1);
//    for(int i =0; i < sin1.duration*sin1.sampleRate; i++)
//        signal1[i] = oscillator1.genSample();

//    for(int i =0; i < sin1.duration*sin1.sampleRate; i++)
//        std::cout << signal1[i] << std::endl;
//    return 0;



    //check niseMC
//    noiseMC noise(0, 1);
//    uint32_t number = 50;
//    std::vector <float> signal1(number);
//    signal1 = noise.genSamples(number);

//    for(int i =0; i < number; i++)
//        std::cout << signal1[i] << std::endl;



    //check signalSummator

    signalInfo signal1;
    signal1.amplitude = 10;
    signal1.freq = 440;
    signal1.timeStart = 0;
    signal1.timeFinish = 1;

//    signalInfo signal2;
//    signal2.amplitude = 100;
//    signal2.freq = 440;
//    signal2.timeStart = 1.1;
//    signal2.timeFinish = 2;

    signalSummator sigsumm;
    sigsumm.addSignal(signal1);
//    sigsumm.addSignal(signal2);
//    //sigsumm.turnOnNoise();

    std::vector<float> result(44000*2 + 1);
    result = sigsumm.makeSummSignalSamples(44000*2);

    for(int i =0; i < result.size(); i++)
        std::cout<< result[i] << std::endl;


//    std::cout <<sizeof (float)<< std::endl;
//    std::cout <<sizeof (int)<< std::endl;
    return 0;
}

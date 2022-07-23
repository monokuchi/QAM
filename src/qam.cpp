
#include <iostream>
#include "qam.h"

int main()
{
    // Set the Waveform class variables
    std::string name = "Wave_1"; 
    int freq = 5001;
    std::vector<float> points = {23, .42, 232.2, 2.4};

    // Make the Waveform object
    Waveform wave(name, freq, points);

    std::cout<<"Waveform Name: " + wave.getName()<<std::endl;
    std::cout<<"Waveform Frequency: " + wave.getFreq()<<std::endl;
    std::cout<<"Waveform Points: ";
    // Print out all the points that make up the wave
    for (auto i = wave.getPoints().begin(); i != wave.getPoints().end(); ++i)
    {
        std::cout<<*i<<" ";
    }

}





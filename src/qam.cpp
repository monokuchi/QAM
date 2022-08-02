
#include <iostream>
#include "qam.h"

int main()
{
    // Set the Signal class variables
    std::string name = "Input Signal"; 
    float freq = 100; // Frequency of carrier signal in Hz
    float sample_rate = 1000; // Sample rate in Hz
    float symbol_rate = 2; // Symbol rate in symbols/sec
    int num_bits = 16; // Make sure this is divisible by 2
    int mod_order = 4; // mod_order of 4 means we are implementing QPSK for this particular example

    // Make the Signal object
    Signal signal(name, num_bits, mod_order);

    // Print the signal's name
    std::cout<<"Signal Name: "<<signal.getName()<<std::endl;

    // Generate our bit vector
    signal.generateBits();
    std::vector<int> bit_vector = signal.getBitVector();
    // Print out all the bits that make up the signal
    printOutVector(bit_vector, "Bit Vector");

    // Generate our carrier signals
    std::vector<float> I_carrier_signal = generateSin(freq, 500, sample_rate);
    std::vector<float> Q_carrier_signal = generateCos(freq, 500, sample_rate);

    // Modulate the signal using QAM
    std::vector<float> output = modulateQAM(bit_vector, I_carrier_signal, Q_carrier_signal);
    printOutVector(output, "Output Signal: ");
    
    
}



#include <iostream>
#include "qam.h"

int main()
{
    // Set the Signal class variables
    std::string name = "Input Signal"; 
    float freq = 900; // Frequency of carrier signal in Hz
    int num_bits = 16; // Make sure this is divisible by 2
    int mod_order = 4; // mod_order of 4 means we are implementing QPSK for this particular example

    // Make the Signal object
    Signal signal(name, freq, num_bits, mod_order);

    // Print the signal's name
    std::cout<<"Signal Name: "<<signal.getName()<<std::endl;

    // Generate our bit vector
    signal.generateBits();
    std::vector<int> bit_vector = signal.getBitVector();
    // Print out all the bits that make up the signal
    std::cout<<"Bit Vector: ";
    printOutVector(bit_vector);

    // Generate our carrier signal
    signal.generateCarrier(300);
    std::vector<std::complex<float>> carrier_signal = signal.getCarrierSignal();

    // Modulate the signal using QAM
    modulateQAM(bit_vector, carrier_signal);
    
    
}


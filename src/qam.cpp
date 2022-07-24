
#include <iostream>
#include "qam.h"

int main()
{
    // Set the Signal class variables
    std::string name = "Input Signal"; 
    int num_bits = 16;
    int mod_order = 4;

    // Make the Signal object
    Signal signal(name, num_bits, mod_order);

    // Print the signal's name
    std::cout<<"Signal Name: "<<signal.getName()<<std::endl;

    // Generate our bit vector
    signal.generateBits();
    std::vector<int> bit_vector = signal.getBitVector();
    // Print out all the bits that make up the signal
    std::cout<<"Bit Vector: ";
    for (auto i = bit_vector.begin(); i != bit_vector.end(); ++i)
    {
        if (i != bit_vector.begin()) std::cout<<", ";
        std::cout<<*i;
    }
    std::cout<<"\n";
}


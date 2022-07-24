
#ifndef QAM_H
#define QAM_H

#include <vector>
#include <random>
#include <complex>
// #include <cmath>


class Signal
{
    private:
        // Private variables
        std::string name;
        std::vector<int> bit_vector; // Bit vector that makes up the signal
        int num_bits; // Total number of bits we want to send
        int modulation_order; // Modulation order which is the number of symbols on constellation diagram
        int symbol_bits; // Number of bits for each symbol
        
    public:
        // Constructor
        Signal(std::string Name, int NumBits, int ModOrder)
        {
            name = Name;
            num_bits = NumBits;
            modulation_order = ModOrder;
            symbol_bits = log2(modulation_order);
        }

        // Public functions
        std::string getName()
        {
            return name;
        }

        std::vector<int> getBitVector()
        {
            return bit_vector;
        }
        
        void generateBits()
        {
            std::random_device seed;
            std::uniform_int_distribution<int> uniform(0, 1); // Generates random 0 or 1
            for (int i=0; i<num_bits; i++)
            {
                bit_vector.push_back(uniform(seed));
            }
        }



};


#endif // QAM_H
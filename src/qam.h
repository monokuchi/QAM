
#ifndef QAM_H
#define QAM_H

#include <vector>
#include <random>
#include "sigproc.h"



class Signal
{
    private:
        std::string name; // Name of the signal
        std::vector<int> bit_vector; // Bit vector that makes up the signal

        int num_bits; // Total number of bits we want to send
        int modulation_order; // Modulation order which is the number of symbols on constellation diagram
        int symbol_bits; // Number of bits for each symbol
        
    public:
        Signal(std::string Name, int NumBits, int ModOrder)
        {
            name = Name;
            num_bits = NumBits;
            modulation_order = ModOrder;
            symbol_bits = log2(modulation_order);
        }

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


template <typename T>
void printOutVector(std::vector<T> &vec, std::string Name)
{
    std::cout<<Name<<": ";
    for (auto i = vec.begin(); i != vec.end(); ++i)
    {
        if (i != vec.begin()) std::cout<<", ";
        std::cout<<*i;
    }
    std::cout<<"\n";
}


std::vector<float> generateCos(float frequency, int sample_size, float sample_rate)
{
    std::vector<float> cos_signal;
    float step_size = 1/sample_rate;
    for (float t=0; t<sample_size; t++)
    {
        float cos_point = cos(2 * M_PI * frequency * t * step_size);
        cos_signal.push_back(cos_point);
    }
    return cos_signal;
}


std::vector<float> generateSin(float frequency, int sample_size, float sample_rate)
{
    std::vector<float> sin_signal;
    float step_size = 1/sample_rate;
    for (float t=0; t<sample_size; t++)
    {
        float sin_point = sin(2 * M_PI * frequency * t * step_size);
        sin_signal.push_back(sin_point);
    }
    return sin_signal;
}


std::vector<float> modulateQAM(std::vector<int> &data, std::vector<float> &I_carrier, std::vector<float> &Q_carrier)
{
    std::cout<<"Modulating Signal..."<<std::endl;

    std::vector<float> output_signal, I_signal, Q_signal;

    // Split the input bit vector in half and route it into the I and Q branches
    for (int i=0; i<(data.size() / 2); i++)
    {
        I_signal.push_back(data[i]);
        Q_signal.push_back(data[(data.size() / 2) + i]);
    }

    // Map the 0's and 1's of the I and Q signals into +-voltages
    float voltage = 5;
    for (int j=0; j<(data.size()/2); j++)
    {
        I_signal[j] = voltage*((2*I_signal[j]) - 1);
        Q_signal[j] = voltage*((2*Q_signal[j]) - 1);
    }

    // Upsample and then interpolate our I and Q signals to match our carrier vector's size
    float upsample_rate = 2;
    I_signal = interpolate(upsample(I_signal, upsample_rate));
    Q_signal = interpolate(upsample(Q_signal, upsample_rate));

    printOutVector(I_signal, "In-Phase Signal");
    printOutVector(Q_signal, "Quadrature Signal");

    // Mix our signals with our carrier signals
    // printOutVector(I_carrier, "In-Phase Carrier");
    // printOutVector(Q_carrier, "Quadrature Carrier");

    
    
    return output_signal;

}


#endif // QAM_H
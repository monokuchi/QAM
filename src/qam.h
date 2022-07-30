
#ifndef QAM_H
#define QAM_H

#include <vector>
#include <random>
#include <complex>



template <typename T>
void printOutVector(std::vector<T> &vec)
{
    for (auto i = vec.begin(); i != vec.end(); ++i)
    {
        if (i != vec.begin()) std::cout<<", ";
        std::cout<<*i;
    }
    std::cout<<"\n";
}


class Signal
{
    private:
        // Private variables
        std::string name; // Name of the signal
        std::vector<int> bit_vector; // Bit vector that makes up the signal
        std::vector<std::complex<float>> carrier_signal; // Carrier signal that we mix our I and Q signals with

        float frequency; // Frequency of the carrier signal in Hz
        int num_bits; // Total number of bits we want to send
        int modulation_order; // Modulation order which is the number of symbols on constellation diagram
        int symbol_bits; // Number of bits for each symbol
        
    public:
        // Constructor
        Signal(std::string Name, float Frequency, int NumBits, int ModOrder)
        {
            name = Name;
            frequency = Frequency;
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

        std::vector<std::complex<float>> getCarrierSignal()
        {
            return carrier_signal;
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

        void generateCarrier(int sample_size)
        {   
            for (int t=0; t<sample_size; t++)
            {
                float sin_point = sin(2 * M_PI * frequency * t);
                carrier_signal.push_back(sin_point);
            }
        }

};


std::vector<std::complex<float>> modulateQAM(std::vector<int> &data, std::vector<std::complex<float>> &carrier)
{
    std::cout<<"Modulating Signal..."<<std::endl;

    std::vector<std::complex<float>> complex_output_signal;
    std::vector<int> I_signal;
    std::vector<int> Q_signal;

    // Split the input bit vector in half and route it into the I and Q branches
    for (int i=0; i<(data.size() / 2); i++)
    {
        I_signal.push_back(data[i]);
        Q_signal.push_back(data[(data.size() / 2) + i]);
    }

    std::cout<<"In-Phase Signal: ";
    printOutVector(I_signal);
    std::cout<<"Quadrature Signal: ";
    printOutVector(Q_signal);

    // Mix our signals with our carrier
    std::cout<<"Carrier Signal: ";
    printOutVector(carrier);
    
    return complex_output_signal;

}


#endif // QAM_H
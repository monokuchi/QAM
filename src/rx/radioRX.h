
#ifndef RADIORX_H
#define RADIORX_H

#include <iostream>
#include <vector>
#include <complex>



class RadioRX
{
    public:
        // RadioRX constructor
        RadioRX(float Sample_Rate);
        RadioRX() = delete;

        // RadioRX destructor
        virtual ~RadioRX() {};

        // Receive the complex IQ samples from the SDR
        std::vector<std::complex<float>> receiveSamples();

    private:
        float sample_rate;

};


#endif // RADIORX_H

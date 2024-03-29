
#ifndef RADIOTX_H
#define RADIOTX_H

#include <iostream>
#include <vector>
#include <complex>
#include <tx/TX.h>



class RadioTX
{
    public:
        // RadioTX constructor
        RadioTX(RadioTXConfig* radio_tx_config);
        RadioTX() = delete;

        // RadioTX destructor
        virtual ~RadioTX() {};

        // Send the complex IQ samples to the SDR
        void sendSamples(std::vector<std::complex<float>> samples);

    private:
        float sample_rate;

};


#endif // RADIOTX_H


#ifndef RADIORX_H
#define RADIORX_H

#include <iostream>
#include <vector>
#include <complex>
#include <rx/RX.h>



class RadioRX
{
    public:
        // RadioRX constructor
        RadioRX(RadioRXConfig* radio_rx_config);
        RadioRX() = delete;

        // RadioRX destructor
        virtual ~RadioRX() {};

        // Receive the complex IQ samples from the SDR
        std::vector<std::complex<float>> receiveSamples();

    private:
        float sample_rate;

};


#endif // RADIORX_H

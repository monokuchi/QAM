
#ifndef QAMRX_H
#define QAMRX_H

#include <vector>
#include <algorithm>
#include <complex>
#include <tools/sigproc.h>
#include <rx/RX.h>



class RX
{   
    public:
        // RX constructor
        RX(RXConfig* rx_config);
        RX() = delete;

        // RX destructor
        virtual ~RX() {};

        // Synchronizes the incoming TX signal with regards to time, frequency, and phase
        std::vector<std::complex<float>> sync(const std::vector<std::complex<float>> &tx_signal);

        // Decodes the complex signal into bits
        std::vector<int8_t> decode(std::vector<std::complex<float>> complex_signal);
        
        // Starts the RX processing
        void startRX(std::vector<std::complex<float>> TX_signal);

    private:
        // RRC filter and parameters
        float beta;
        int num_periods;
        int oversample_rate;
        std::vector<std::complex<float>> rrc;

        // Pilot signal (Barker Code)
        std::vector<int8_t> pilot_signal = {1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0};

        // Modulation order (# of symbols)
        int modulation_order;

};


#endif // QAMRX_H

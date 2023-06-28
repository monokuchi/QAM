
#ifndef QAMTX_H
#define QAMTX_H

#include <vector>
#include <algorithm>
#include <complex>
#include <sigproc.h>



class TX
{   
    public:
        // TX constructor
        TX(float Beta, int T, int Oversample_Rate, int Modulation_Order);
        TX() = delete;

        // TX destructor
        virtual ~TX() {};

        // Turn binary bit vector into IQ samples
        std::vector<std::complex<float>> toSamples(std::string str);

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


#endif // QAMTX_H

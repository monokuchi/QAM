
#ifndef QAM_H
#define QAM_H

#include <vector>
#include <algorithm>
#include <complex>
#include <random>
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
        std::vector<float> rrc;

        int modulation_order; // Modulation order (# of symbols)

};


#endif // QAM_H

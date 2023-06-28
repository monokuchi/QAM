
#include <tx/radioTX.h>



/* ----------RadioTX Member Function's Definitions---------- */
RadioTX::RadioTX(float Sample_Rate)
{
    sample_rate = Sample_Rate;
}


void RadioTX::sendSamples(std::vector<std::complex<float>> samples)
{
    // Use the SDR's API to send the samples we generated in TX to RX
    std::cout << "Sending IQ samples to RX..." << std::endl;
}

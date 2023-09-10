
#include <tx/radioTX.h>
#include <tx/TX.h>


/* ----------RadioTX Member Function's Definitions---------- */
RadioTX::RadioTX(RadioTXConfig* radio_tx_config)
{
    sample_rate = radio_tx_config->sample_rate;
}


void RadioTX::sendSamples(std::vector<std::complex<float>> samples)
{
    // Use the SDR's API to send the samples we generated in TX to RX
    std::cout << "Sending IQ samples to RX..." << std::endl;
    
    // TODO: Implement the SDR API calls here...
}


#include <iostream>
#include <string.h>
#include <complex>
#include <bitset>
#include <qamRX.h>
#include <qamUtil.h>



/* ----------RX Member Function's Definitions---------- */
RX::RX(float Beta, int T, int Oversample_Rate, int Modulation_Order)
{
    beta = Beta;
    num_periods = T;
    oversample_rate = Oversample_Rate;
    modulation_order = Modulation_Order;
    rrc = rootRaisedCosine(Beta, T, Oversample_Rate);
}


std::vector<std::complex<float>> RX::sync(std::vector<std::complex<float>> tx_signal)
{
    std::vector<std::complex<float>> synchronized_signal;
    std::vector<std::complex<float>> pilot_symbols = bitMapper(pilot_signal, modulation_order);
    std::vector<std::complex<float>> upsampled_pilot_symbols = upsample(pilot_symbols, oversample_rate);
    std::vector<std::complex<float>> filtered_upsampled_pilot_symbols = filter(upsampled_pilot_symbols, rrc);

    std::vector<std::complex<float>> correlated_signal = crossCorrelate(tx_signal, filtered_upsampled_pilot_symbols);

    std::vector<float> mag_correlated_signal;
    mag_correlated_signal.reserve(correlated_signal.size());
    for (auto &itr : correlated_signal)
    {
        mag_correlated_signal.push_back(abs(itr));
    }

    int max_value = *std::max_element(mag_correlated_signal.begin(), mag_correlated_signal.end());
    int max_index = 0;
    for (size_t i=0; i<mag_correlated_signal.size(); i++)
    {
        if (mag_correlated_signal[i] > max_value)
        {
            max_value = mag_correlated_signal[i];
            max_index = i;
        }
    }

    // This method of trimming off the tx_signal is assuming RX has got the entire block at once (we have to change this later on to frame based processing)
    synchronized_signal.reserve(mag_correlated_signal.size() - max_index);
    std::vector<std::complex<float>>::iterator max_value_itr = std::find(tx_signal.begin(), tx_signal.end(), tx_signal[max_index]);
    std::copy(max_value_itr, tx_signal.end(), synchronized_signal.begin());
    // memcpy(synchronized_signal.data(), tx_signal.data(), synchronized_signal.size());
    
    return synchronized_signal;
}


std::vector<int8_t> RX::decode(std::vector<std::complex<float>> complex_signal)
{
    std::vector<int8_t> bit_vector;

    // Downsample our signal
    std::vector<std::complex<float>> downsampled_signal = downsample(complex_signal, oversample_rate);
    // Use nearest neighbor to map the noisy symbols to our constellation symbols
    std::vector<std::complex<float>> symbol_map = {{1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
    std::vector<std::complex<float>> symbols = nearestNeighbor(downsampled_signal, symbol_map);
    // Map our complex symbols back into their respective bits
    bit_vector = 

    return bit_vector;
}


void RX::startRX(std::vector<std::complex<float>> TX_signal)
{
    // Sync our signal
    std::vector<std::complex<float>> synced_signal = sync(filter(TX_signal, rrc));

    // Decode the complex signal into bits
    std::vector<int8_t> message_bits = decode(synced_signal);

    printOutVector(message_bits, "Decoded Message Bits");
}

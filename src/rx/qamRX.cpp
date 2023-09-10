
#include <iostream>
#include <string.h>
#include <complex>
#include <bitset>
#include <rx/qamRX.h>
#include <tools/qamUtil.h>
#include <rx/RX.h>



/* ----------RX Member Function's Definitions---------- */
RX::RX(RXConfig* rx_config)
{
    beta = rx_config->b;
    num_periods = rx_config->T;
    oversample_rate = rx_config->oversample_rate;
    modulation_order = rx_config->mod_order;
    rrc = rootRaisedCosine(beta, num_periods, oversample_rate);
}


// Converts a bit vector to a string using the ASCII convention
std::string convertToStringAscii(const std::vector<int8_t> &input_bit_vector)
{
    std::string output_string;
    std::bitset<8> character;
    char c;

    size_t j = 1;
    for (size_t i=0; i<input_bit_vector.size(); i++)
    {
        character.set(i%8, input_bit_vector[((8*j)-1)-(i%8)]);
        if ((i+1)%8 == 0)
        {
            c = char(character.to_ulong());
            output_string += c;
            // character.reset();
            j++;
        }
    }

    return output_string;
}


std::vector<std::complex<float>> RX::sync(const std::vector<std::complex<float>> &tx_signal)
{
    std::vector<std::complex<float>> pilot_symbols = bitMapper(pilot_signal, modulation_order);
    std::vector<std::complex<float>> upsampled_pilot_symbols = upsample(pilot_symbols, oversample_rate);
    // Overall Channel Transfer Function has to be a Raised Cosine Filter
    std::vector<std::complex<float>> filtered_upsampled_pilot_symbols = filter(filter(upsampled_pilot_symbols, rrc), rrc);
    // Chop off the transients at the beginning and end of the signal
    std::copy(filtered_upsampled_pilot_symbols.begin()+(rrc.size()-1), filtered_upsampled_pilot_symbols.end()-(rrc.size()-1), filtered_upsampled_pilot_symbols.begin());
    filtered_upsampled_pilot_symbols.resize(filtered_upsampled_pilot_symbols.size() - (2*(rrc.size()-1)));

    std::vector<std::complex<float>> correlated_signal = crossCorrelate(tx_signal, filtered_upsampled_pilot_symbols);

    std::vector<float> mag_correlated_signal;
    mag_correlated_signal.reserve(correlated_signal.size());
    for (auto &itr : correlated_signal)
    {
        mag_correlated_signal.push_back(abs(itr));
    }

    int max_index = std::max_element(mag_correlated_signal.begin(), mag_correlated_signal.end()) - mag_correlated_signal.begin();

    int start_index = max_index - (filtered_upsampled_pilot_symbols.size() - 1);
    // This method of trimming off the tx_signal is assuming RX has got the entire block at once (we have to change this later to frame based processing)
    std::vector<std::complex<float>> synchronized_signal(tx_signal.begin()+start_index, tx_signal.end());

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
    bit_vector = symbolMapper(symbols, modulation_order);
    
    return bit_vector;
}


void RX::startRX(std::vector<std::complex<float>> TX_signal)
{
    // Sync our signal
    std::vector<std::complex<float>> synced_signal = sync(filter(TX_signal, rrc));
    
    // Decode the complex signal into bits
    std::vector<int8_t> message_bits = decode(synced_signal);

    printOutVector(message_bits, "Decoded Message Bits");

    // Extract the data bits from the message bit vector
    std::vector<int8_t> data_bits(message_bits.begin()+10, message_bits.begin()+26); // <----- ???? arbitary slicing
    // Bits 11-27 = 16 bits ---> for message "hi"
    printOutVector(data_bits, "Decoded Text Bits");

    // Convert the data bits to string using ASCII
    std::string data_string = convertToStringAscii(data_bits);

    std::cout << "Decoded Data String: " << data_string << "\n" << std::endl;
}

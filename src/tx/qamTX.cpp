
#include <iostream>
#include <complex>
#include <bitset>
#include <tx/qamTX.h>
#include <tools/qamUtil.h>



/* ----------TX Member Function's Definitions---------- */
TX::TX(TXConfig* tx_config)
{
    beta = tx_config->b;
    num_periods = tx_config->T;
    oversample_rate = tx_config->oversample_rate;
    modulation_order = tx_config->mod_order;
    rrc = rootRaisedCosine(beta, num_periods, oversample_rate);
}


// Converts the input string to a bit vector using the ASCII convention
std::vector<int8_t> convertToBinaryAscii(const std::string &input_string)
{
    std::vector<int8_t> bit_vector;
    std::bitset<8> letter;
    std::cout << "ASCII Binary Message: ";
    for (size_t i=0; i<input_string.size(); i++)
    {
        letter = input_string[i];
        std::cout << letter;
        for (int j=0; j<8; j++)
        {
            bit_vector.push_back(letter[7-j]);
        }
    }
    std::cout << "\n";

    return bit_vector;
}


std::vector<int8_t> addMessageHeader(const std::vector<int8_t> &pilot, const std::vector<int8_t> &data_payload)
{
    /*
                ---------------Message Packet Structure---------------
    [Pilot Symbols (2 Bytes) | Message Length (1 Byte) | Data Payload (0 to 255 Bytes)]
    */

    std::vector<int8_t> msg_packet, msg_length;
    std::bitset<8> msg_length_bits = data_payload.size();
    for (int i=0; i<8; i++)
    {
        msg_length.push_back(msg_length_bits[7-i]);
    }
    
    msg_packet.insert(msg_packet.end(), pilot.begin(), pilot.end());
    msg_packet.insert(msg_packet.end(), msg_length.begin(), msg_length.end());
    msg_packet.insert(msg_packet.end(), data_payload.begin(), data_payload.end());

    return msg_packet;
}


std::vector<std::complex<float>> TX::toSamples(std::string str)
{
    std::vector<std::complex<float>> samples;
    std::vector<std::complex<float>> symbols = bitMapper(addMessageHeader(pilot_signal, convertToBinaryAscii(str)), modulation_order);

    printOutVector(symbols, "Symbols");

    samples = filter(upsample(symbols, oversample_rate), rrc);

    printOutVector(samples, "Samples");
    

    return samples;
}

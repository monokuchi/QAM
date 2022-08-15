
#include <iostream>
#include <complex>
#include <bitset>
#include <qamTX.h>



template <typename T>
void printOutVector(const std::vector<T> &vec, std::string Name)
{
    std::cout << Name << ": ";
    for (auto i = vec.begin(); i != vec.end(); ++i)
    {
        if (i != vec.begin()) std::cout<<", ";
        std::cout<<*i;
    }
    std::cout<<"\n";
}

template <>
void printOutVector(const std::vector<int8_t> &vec, std::string Name)
{
    std::cout << Name << ": ";
    for (auto i = vec.begin(); i != vec.end(); ++i)
    {
        if (i != vec.begin()) std::cout<<", ";
        std::cout<<(int) *i;
    }
    std::cout<<"\n";
}


/* ----------TX Member Function's Definitions---------- */
TX::TX(float Beta, int T, int Oversample_Rate, int Modulation_Order)
{
    beta = Beta;
    num_periods = T;
    oversample_rate = Oversample_Rate;
    modulation_order = Modulation_Order;
    rrc = rootRaisedCosine(Beta, T, Oversample_Rate);
}


// Converts the input string to a bit vector using the ASCII convention
std::vector<int8_t> convertToBinaryAscii(std::string input_string)
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


std::vector<std::complex<float>> bitMapper(std::vector<int8_t> bits, int mod_order)
{
    std::vector<std::complex<float>> symbols;
    int bits_per_symbol = log2(mod_order);
    // Hardcoded symbol_map for now, meant for QPSK
    std::vector<std::complex<float>> symbol_map = {{1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
    
    for(size_t i=0; i<bits.size(); i+=bits_per_symbol)
    {
        symbols.push_back(symbol_map[(bits[i]*1) + (bits[i+1]*2)]);
    }

    return symbols;
}


std::vector<int8_t> addMessageHeader(std::vector<int8_t> data_payload)
{
    /*
                ---------------Message Packet Structure---------------
    [Pilot Symbols (2 Bytes) | Message Length (1 Byte) | Data Payload (0 to 255 Bytes)]
    */

    std::vector<int8_t> msg_packet, msg_length;
    std::vector<int8_t> pilot = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
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
    std::vector<std::complex<float>> symbols = bitMapper(addMessageHeader(convertToBinaryAscii(str)), modulation_order);

    printOutVector(symbols, "Symbols");

    // Make our rrc filter complex
    std::vector<std::complex<float>> rrc_complex;
    for (auto &itr : rrc)
    {
        rrc_complex.push_back(std::complex<float> (itr, 0.0));
    }
    samples = interpolate(symbols, rrc_complex, oversample_rate);
    
    printOutVector(samples, "Samples");
    

    return samples;
}

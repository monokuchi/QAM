
#include <qamUtil.h>



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


std::vector<int8_t> symbolMapper(std::vector<std::complex<float>> symbols, int mod_order)
{
    std::vector<int8_t> bits;
    int bits_per_symbol = log2(mod_order);
    // Hardcoded symbol_map for now, meant for QPSK
    std::vector<std::complex<float>> symbol_map = {{1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
    
    int idx = 0;
    for (int i=0; i<symbols.size(); i++)
    {
        idx = std::find(symbol_map.begin(), symbol_map.end(), symbols[i]);
    }

    return bits;
}

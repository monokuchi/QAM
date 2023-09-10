
#include <tools/qamUtil.h>



void printOutVector(const std::vector<int8_t> &vec, std::string Name)
{
    std::cout << Name << ": ";
    for (auto i = vec.begin(); i != vec.end(); ++i)
    {
        if (i != vec.begin()) std::cout << ", ";
        std::cout << (int) *i;
    }
    std::cout << "\n";
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


std::vector<int8_t> symbolMapper(std::vector<std::complex<float>> symbols, int mod_order)
{
    std::vector<int8_t> bits;
    int bits_per_symbol = log2(mod_order);
    bits.reserve(bits_per_symbol * symbols.size());
    // Hardcoded symbol_map for now, meant for QPSK
    std::vector<std::complex<float>> symbol_map = {{1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
    
    int idx;
    // std::vector<int8_t> idx_binary;
    // idx_binary.reserve(bits_per_symbol);
    for (int i=0; i<symbols.size(); i++)
    {
        auto itr = find(symbol_map.begin(), symbol_map.end(), symbols[i]);
        idx = itr - symbol_map.begin();
        // The bitset size needs to be bits_per_symbol not hardcoded to be 8...
        //std::bitset<8> idx_binary = idx;
        boost::dynamic_bitset<> idx_binary(bits_per_symbol, idx);
        for (int j=0; j<bits_per_symbol; j++)
        {
            // bits.push_back(idx_binary[bits_per_symbol-1-j]);
            bits.push_back(idx_binary[j]);
        }
    }

    return bits;
}


std::vector<std::complex<float>> nearestNeighbor(const std::vector<std::complex<float>> &noisy_symbols, const std::vector<std::complex<float>> &reference_symbols)
{
    std::vector<std::complex<float>> estimated_symbols;
    estimated_symbols.reserve(noisy_symbols.size());
    std::vector<float> sq_distances;
    sq_distances.reserve(reference_symbols.size());
    int idx;

    for (auto &itr_noisy : noisy_symbols)
    {
        for (auto &itr_reference : reference_symbols)
        {
            sq_distances.push_back(pow((itr_reference.real()-itr_noisy.real()), 2) + pow((itr_reference.imag()-itr_noisy.imag()), 2));
        }
        idx = min_element(sq_distances.begin(), sq_distances.end()) - sq_distances.begin();
        estimated_symbols.push_back(reference_symbols[idx]);
        sq_distances.clear();
    }

    return estimated_symbols;
}


#ifndef QAMUTIL_H
#define QAMUTIL_H

#include <iostream>
#include <vector>
#include <complex>
#include <algorithm>
#include <boost/dynamic_bitset.hpp>



template <typename T>
void printOutVector(const std::vector<T> &vec, std::string Name)
{
    std::cout << Name << ":: ";
    for (auto i = vec.begin(); i != vec.end(); ++i)
    {
        if (i != vec.begin()) std::cout << ", ";
        std::cout << *i;
    }
    std::cout << "\n";
}

void printOutVector(const std::vector<int8_t> &vec, std::string Name);
// template <>
// void printOutVector(const std::vector<int8_t> &vec, std::string Name)
// {
//     std::cout << Name << ": ";
//     for (auto i = vec.begin(); i != vec.end(); ++i)
//     {
//         if (i != vec.begin()) std::cout << ", ";
//         std::cout << (int) *i;
//     }
//     std::cout << "\n";
// }


std::vector<std::complex<float>> bitMapper(std::vector<int8_t> bits, int mod_order);


std::vector<int8_t> symbolMapper(std::vector<std::complex<float>> symbols, int mod_order);


std::vector<std::complex<float>> nearestNeighbor(const std::vector<std::complex<float>> &noisy_symbols, const std::vector<std::complex<float>> &reference_symbols);


#endif // QAMUTIL_H

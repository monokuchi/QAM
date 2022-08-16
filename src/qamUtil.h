
#ifndef QAMUTIL_H
#define QAMUTIL_H

#include <iostream>
#include <vector>
#include <complex>



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

template <typename>
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


std::vector<std::complex<float>> bitMapper(std::vector<int8_t> bits, int mod_order);


#endif // QAMUTIL_H

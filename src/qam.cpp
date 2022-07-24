
#include <iostream>
#include <random>
#include "qam.h"

int main()
{
    // Set the Signal class variables
    std::string name = "Input Signal"; 
    std::vector<std::complex<double>> points;
    std::complex<double> complex_point;
    while (std::cin >> complex_point)
    {
        points.push_back(complex_point);
    }

    // Make the Signal object
    Signal signal(name);

    std::cout<<"Signal Name: " + signal.getName()<<std::endl;

    signal.setSignalPoints(points);
    std::cout<<"Signal Points: ";
    // Print out all the points that make up the signal
    for (auto i = signal.getSignalPoints().begin(); i != signal.getSignalPoints().end(); ++i)
    {
        std::cout<<*i<<" ";
    }

}





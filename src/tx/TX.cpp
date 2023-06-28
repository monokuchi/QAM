
#include <iostream>
#include <tx/radioTX.h>
#include <tx/qamTX.h>
#include <complex>



// Gets the message string from the user
std::string getMessage()
{
    std::string message;
    std::cout << "Enter your message: ";
    std::getline(std::cin, message);
    return message;
}


int main()
{
    // Set the RadioTX class variables
    float sample_rate = 10000;
    // Set the TX class variables
    float b = .3;
    int T = 8;
    int oversample_rate = 4;
    int mod_order = 4; // mod_order of 4 means we are implementing QPSK for this particular example

    // Make our RadioTX object
    RadioTX radio_tx(sample_rate);
    // Make our TX object
    TX signal_tx(b, T, oversample_rate, mod_order);
    
    while(true)
    {
        // Get our message from user that we want to send over
        std::string message = getMessage();

        // Generate and then send our complex IQ signals to the SDR
        radio_tx.sendSamples(signal_tx.toSamples(message));
    }
    
}

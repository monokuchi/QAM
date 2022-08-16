
#include <iostream>
#include <qamTX.h>
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
    // Set the TX class variables
    float b = .3;
    int T = 8;
    int oversample_rate = 4;
    int mod_order = 4; // mod_order of 4 means we are implementing QPSK for this particular example

    // Say 100 bits at 2 bits/sym at 10x oversample rate
    // = 50 symbols out, oversampled at 10x => 500 samples out
    // bits => QAM (I+jQ) => upsample 10x => RRC filter (at 10x)

    // Make our TX object
    TX signal_tx(b, T, oversample_rate, mod_order);
    
    while(true)
    {
        // Get our message from user that we want to send over
        std::string message = getMessage();

        // Generate our complex IQ signal to give to our SDR
        signal_tx.toSamples(message);
    }
    
}

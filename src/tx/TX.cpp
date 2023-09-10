
#include <iostream>
#include <tx/TX.h>
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
    RadioTXConfig radio_tx_config = {10000};
    // Set the TX class variables
    TXConfig tx_config = {.3, 8, 4, 4};

    // Make our RadioTX object
    RadioTX radio_tx(&radio_tx_config);
    // Make our TX object
    TX signal_tx(&tx_config);
    
    while(true)
    {
        // Get our message from user that we want to send over
        std::string message = getMessage();

        // Generate and then send our complex IQ signals to the SDR
        radio_tx.sendSamples(signal_tx.toSamples(message));
    }
    
}

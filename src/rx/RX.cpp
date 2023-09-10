
#include <iostream>
#include <rx/RX.h>
#include <rx/radioRX.h>
#include <rx/qamRX.h>
#include <complex>



int main()
{
    // Set the RadioRX class variables
    RadioRXConfig radio_rx_config = {10000};
    // Set the RX class variables
    RXConfig rx_config = {.3, 8, 4, 4};

    // Make our RadioRX object
    RadioRX radio_rx(&radio_rx_config);
    // Make our RX object
    RX signal_rx(&rx_config);

    while(true)
    {
        // Start the RX processing
        signal_rx.startRX(radio_rx.receiveSamples());
    }
    
}

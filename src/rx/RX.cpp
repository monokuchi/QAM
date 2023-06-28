
#include <iostream>
#include <rx/radioRX.h>
#include <rx/qamRX.h>
#include <complex>



int main()
{
    // Set the RadioRX class variables
    float sample_rate = 10000;
    // Set the RX class variables
    float b = .3;
    int T = 8;
    int oversample_rate = 4;
    int mod_order = 4; // mod_order of 4 means we are implementing QPSK for this particular example

    // Make our RadioRX object
    RadioRX radio_rx(sample_rate);
    // Make our RX object
    RX signal_rx(b, T, oversample_rate, mod_order);

    while(true)
    {
        // Start the RX processing
        signal_rx.startRX(radio_rx.receiveSamples());
    }
    
}

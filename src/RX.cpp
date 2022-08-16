
#include <iostream>
#include <qamRX.h>
#include <complex>



int main()
{
    // Set the RX class variables
    float b = .3;
    int T = 8;
    int oversample_rate = 4;
    int mod_order = 4; // mod_order of 4 means we are implementing QPSK for this particular example

    // Make our TX object
    RX signal_rx(b, T, oversample_rate, mod_order);
    // The signal that comes in from the TX side
    std::vector<std::complex<float>> received_signal;

    while(true)
    {
        // Right now for testing received_signal is hardcoded but this will later be replaced by a SDR API call.
        received_signal = {(1, 2)};

        // Start the RX processing
        signal_rx.startRX(received_signal);
    }
    
}

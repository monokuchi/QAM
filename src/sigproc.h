
#ifndef SIGPROC_H
#define SIGPROC_H

#include <vector>
#include <complex>
#include <math.h>



std::vector<float> rootRaisedCosine(float B, int T, int OversampleRate);


template <typename T>
std::vector<T> convolve(const std::vector<T> &signal_1, const std::vector<T> &signal_2)
{
    int l1 = signal_1.size();
    int l2 = signal_2.size();
    int N = l1 + l2 - 1;
    std::vector<T> convolved_signal(N);

    for (int n=0; n<N; n++)
    {
        convolved_signal[n] = 0.0;
        for(int k=0; k<=std::min(std::max(l1, l2), n); k++)
        {
            if ((k < l1) && (n-k < l2))
            {
                convolved_signal[n] += signal_1[k] * signal_2[n-k];
            }
        }
    }

    return convolved_signal;
}


template <typename T>
std::vector<T> upsample(std::vector<T> signal, float N)
{
    std::vector<std::complex<float>> upsampled_signal(N*signal.size());
    // Zero stuff the signal
    for (int i=0; i<signal.size(); i++)
    {
        upsampled_signal[N*i] = signal[i];
    }
    // Get rid of the trailing zeros
    upsampled_signal.erase(upsampled_signal.end()-N+1, upsampled_signal.end());

    return upsampled_signal;
}


template <typename T>
std::vector<T> interpolate(std::vector<T> signal, std::vector<T> lowpass_filter, int oversample)
{
    // Lowpass filter our upsampled signal
    std::vector<T> interpolated_signal = convolve(upsample(signal, oversample), lowpass_filter);

    return interpolated_signal;
}


#endif // SIGPROC_H

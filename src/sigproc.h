
#ifndef SIGPROC_H
#define SIGPROC_H

#include <vector>
#include <complex>
#include <algorithm>



std::vector<std::complex<float>> rootRaisedCosine(float B, int T, int OversampleRate);


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
std::vector<T> upsample(const std::vector<T> &signal, float N)
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
std::vector<T> downsample(const std::vector<T> &signal, float N)
{
    std::vector<T> downsampled_signal;
    downsampled_signal.reserve((int) std::floor(signal.size() / N));
    // Keep every N'th sample
    for (int i=1; i<signal.size()+1; i++)
    {
        if (!(i % (int) N))
        {
            downsampled_signal.push_back(signal[i-1]);
        }
    }
    
    return downsampled_signal;
}


template <typename T>
std::vector<T> filter(std::vector<T> signal, std::vector<T> filter_taps)
{
    // Lowpass filter our upsampled signal
    std::vector<T> interpolated_signal = convolve(signal, filter_taps);

    return interpolated_signal;
}


template <typename T>
std::vector<T> crossCorrelate(const std::vector<T> &signal_1, const std::vector<T> &signal_2)
{
    // Cross correlating signal_1 with signal_2 i.e. R(signal_1, signal_2)
    std::vector<T> result;
    std::vector<T> reversed_signal_2(signal_2);
    std::reverse(reversed_signal_2.begin(), reversed_signal_2.end());
    result = convolve(signal_1, reversed_signal_2);

    return result;
}


#endif // SIGPROC_H

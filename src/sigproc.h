
#ifndef SIGPROC_H
#define SIGPROC_H

#include <vector>
#include <math.h>



std::vector<float> rootRaisedCosine(float B, int T, int OversampleRate)
{
    std::vector<float> filter_coeff;

    int filter_order = T*OversampleRate;
    if (filter_order%2 != 0)
    {
        std::__throw_invalid_argument("Filter Order must be even!");
    }

    // Make the root raised cosine filter
    for (int t=-(T*OversampleRate)/2; t<=(T*OversampleRate)/2; t++)
    {
        float new_t = t*(1.0/OversampleRate);

        if (new_t == 0.0)
        {
            // Midpoint (t=0)
            filter_coeff.push_back(1.0 + (B * ((4.0/M_PI) - 1.0)));
        }
        else if (new_t == 1.0/(4.0*B) || new_t == -1.0/(4.0*B))
        {
            // Zero-Crossings (t=+-T/4B)
            filter_coeff.push_back((B/(sqrt(2))) * (((1.0+(2.0/M_PI))*sin(M_PI/(4.0*B))) + ((1.0-(2.0/M_1_PI))*cos(M_PI/(4.0*B)))));
        }
        else
        {
            // Other Points
            filter_coeff.push_back((sin((M_PI*new_t)*(1.0-B)) + ((4.0*B*new_t)*cos((M_PI*new_t)*(1.0+B)))) / ((M_PI*new_t) * (1.0-(pow(4.0*B*new_t, 2.0)))));
        }
    }

    return filter_coeff;
}


template <typename T>
std::vector<T> convolve(std::vector<T> &signal_1, std::vector<T> &signal_2)
{
    int j = signal_1.size();
    int m = signal_2.size();
    std::vector<T> convolved_signal(j+m-1);

    for (int n=0; n<(j+m-1); n++)
    {
        float sum = 0.0;
        for(int k=std::max(1, n+1-m); k<std::min(n, j); k++)
        {
            sum += signal_1[k] * signal_2[n-k+1];
        }
        convolved_signal[n] = sum;
    }

    return convolved_signal;
}


template <typename T>
std::vector<T> upsample(std::vector<T> signal, float N)
{
    std::vector<float> upsampled_signal(N*signal.size(), 0.0);
    // Zero stuff the signal
    for (int i=0; i<signal.size(); i++)
    {
        upsampled_signal[N*i] = signal[i];
    }

    return upsampled_signal;
}


template <typename T>
std::vector<T> interpolate(std::vector<T> signal)
{
    std::vector<float> rrc = rootRaisedCosine(2, 2, 8);

    // Lowpass filter our signal with the root raised cosine filter
    std::vector<T> interpolated_signal = convolve(signal, rrc);

    return interpolated_signal;
}


#endif // SIGPROC_H
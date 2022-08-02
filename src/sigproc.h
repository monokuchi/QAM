
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
std::vector<T> convolve(std::vector<T> const &signal_1, std::vector<T> const &signal_2)
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
    std::vector<float> upsampled_signal(N*signal.size(), 0.0);
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
std::vector<T> interpolate(std::vector<T> signal)
{
    std::vector<float> rrc = rootRaisedCosine(2, 2, 4);

    // Lowpass filter our signal with the root raised cosine filter
    std::vector<T> interpolated_signal = convolve(signal, rrc);

    return interpolated_signal;
}


#endif // SIGPROC_H
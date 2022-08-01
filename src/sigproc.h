
#ifndef SAMPLER_H
#define SAMPLER_H

#include <vector>
#include <math.h>



std::vector<float> rootRaisedCosine(float B, int T, int OversampleRate)
{
    int filter_order = T*OversampleRate;
    std::vector<float> filter_coeff(filter_order+1, 0.0);
    if (filter_order%2 != 0)
    {
        std::__throw_invalid_argument("Filter Order must be even!");
    }

    // Make the root raised cosine filter
    for (float t=-T/2; t<T/2; t+=(1/OversampleRate))
    {
        if (t == 0)
        {
            // Midpoint (t=0)
            filter_coeff.push_back(1 + (B * ((4/M_PI) - 1)));
        }
        else if (t == 1/(4*B) || t == -1/(4*B))
        {
            // Zero-Crossings (t=+-T/4B)
            filter_coeff.push_back((B/(sqrt(2))) * (((1+(2/M_PI))*sin(M_PI/(4*B))) + ((1-(2/M_1_PI))*cos(M_PI/(4*B)))));
        }
        else
        {
            // Other Points
            filter_coeff.push_back((sin((M_PI*t)*(1-B)) + ((4*B*t)*cos((M_PI*t)*(1+B)))) / ((M_PI*t) * (1-(pow(4*B*t, 2)))));
        }
    }

    return filter_coeff;
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
    std::vector<T> interpolated_signal;
    std::vector<T> rrc = rootRaisedCosine(4, 2, 6);
    interpolated_signal = rrc;

    return interpolated_signal;
}


#endif // SAMPLER_H
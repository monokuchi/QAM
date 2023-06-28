
#include <sigproc.h>



std::vector<std::complex<float>> rootRaisedCosine(float B, int T, int OversampleRate)
{
    std::vector<std::complex<float>> filter_coeff;

    int filter_order = T * OversampleRate;
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

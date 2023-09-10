
#ifndef RX_H
#define RX_H



typedef struct RadioRXConfig
{
    float sample_rate;
} RadioRXConfig;


typedef struct RXConfig
{
    float b;
    int T;
    int oversample_rate;
    int mod_order;
} RXConfig;


#endif // RX_H


#ifndef TX_H
#define TX_H



typedef struct RadioTXConfig
{
    float sample_rate;
} RadioTXConfig;


typedef struct TXConfig
{
    float b;
    int T;
    int oversample_rate;
    int mod_order;
} TXConfig;


#endif // TX_H

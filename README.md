# ***QAM***

## *Implementation of an digital QAM modulation scheme :signal_strength:*

### Scenario
```
1. Starting with mod_order = 4 which corresponds to a 4-QAM implementation, A.K.A QPSK
2. Feed in input data binary stream into QAM block which splits the data into half assigning each half to an In-Phase and a Quadrature signal
3. Add a 90 degree phase shift to the Quadrature signal
4. Mix the amplitudes of the In-Phase and Quadrature signals with the carrier wave
5. Add the resulting complex signals together at the end, this is your resulting QAM modulated signal
```

### Block Diagram
```mermaid
flowchart LR
    bit(Input Bitstream)
    bit_A(First Half of Bitstream)
    bit_B(Second Half of Bitstream)
    bit --> bit_A & bit_B
    bit_A --> sig_I
    bit_B --> sig_Q

    subgraph QAM Modulator
        direction TB
        sig_I(In-Phase Signal)
        sig_Q(Quadrature Signal)
        quadrature{{90 Degrees Phase Shift}}
        mixer_1(((Mixer)))
        mixer_2(((Mixer)))
        carrier((Carrier)) 
        adder{Adder}
    end

    sig_I --> mixer_1
    sig_Q --> mixer_2
    quadrature --> mixer_2
    carrier --> mixer_1 & quadrature
    mixer_1 & mixer_2 --> adder
    
    adder --> result(RF Out)
```

### Build and Run Instructions
```
1. cd ~/git/QAM/scripts
2. ./runQAM.sh
```

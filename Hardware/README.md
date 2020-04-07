# Hardware Design :hammer_and_wrench:

As a result of the COVID-19 outbreak and associated facility closures, testing of hardware components described here remains incomplete.

Important features of the design:

1. The differential amplifiers (INA126) are used to obtain differential EMG signals.
   1. These input to the ADCs (ADS1115).
   1. The ADCs utilise the I2C bus protocol.
2. A reference voltage circuit is used to provide a 1.67V reference to the amplifiers so as to offset the EMG signals and retain the negative component.
4. A voltage devider and buffering amplifer (TL071) are used to generate the reference voltage.
5. Standard decoupling capacitors are used for the ADC protection and clamping diodes are placed at the EMG inputs to short any large static volatages and protect the amplifiers. 

**The ADS1115 has the potential to read 4 input channels. However, only two of these channels are utilised per components to maintain a high rate of sampling of each channel.**

**Any static charge build-up from the user is dissipated through ground using upstream diodes to preserve the amplifiers.**

# Hardware Design :hammer_and_wrench:

As a result of the Covid-19 outbreak and associated facility closures, testing of hardware components described here remains incomplete

Important features of the design:

1. The differential amplifiers (INA126) are used to obtain differential EMG signals 
   1. These input to the ADCs (ADS1115).
   1. The ADCs utilise the I2C bus protocol
2. A reference voltage circuit is used to provide a 1.67V reference to the amplifiers
4. A buffer amplifier (TL071) is employed as reference. 
5. Standard decoupling and protective measures are in place

**The ADS1115 has the potential to read 4 input channels. However, only two of these channels are utilised per components to maintain a high rate of sampling of each channel**

**Any static charge build-up from the user is dissipated through ground using upstream diodes to preserve the amplifiers**

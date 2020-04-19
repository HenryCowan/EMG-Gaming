# Hardware Design :hammer_and_wrench:

As a result of the COVID-19 outbreak and associated facility closures, testing of hardware components described here remains incomplete.

Important features of the design:

* The differential amplifiers (INA126) are used to obtain differential EMG signals.
   * These input to the ADCs (ADS1115).
   * The ADCs utilise the I2C bus protocol.
* A reference voltage circuit is used to provide a 1.67V reference to the amplifiers so as to offset the EMG signals and retain the negative component.
* A voltage divider and buffering amplifer (TL071) are used to generate the reference voltage.
* Standard decoupling capacitors are used for ADC protection, and clamping diodes are placed at the EMG inputs to short any large static voltages and protect the amplifiers. 

**The ADS1115 has the potential to read 4 input channels. However, only two of these channels are utilised per components to maintain a high rate of sampling within each channel.**


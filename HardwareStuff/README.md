The hardware aspect of this porject consists of: a 4, differential amplifiers, used for obtaining a differential EMG signal; 
2 adc's with i2c bus protocol output; a reference voltage circuit to provide the initial amplifiers with a 1.67V reference; 
and then your standard decoupling and protection.

The amplifiers used are INA126's.
The ADC's used are the ADS1115.
A buffer amplifier is also used for the reference, this is a TL071.

The adc's have 4 input channels however we will only be using two of these channels for each device to maximise the sampling rate 
of each chip. Protection diodes are situated before the amplifier to ensure any static charge buildup from the subject is disipated
through ground rather than through the amps!

The board is currently in production.


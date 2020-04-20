# Hardware Design :hammer_and_wrench:

As a result of the COVID-19 outbreak and associated facility closures, testing of hardware components described here remains incomplete.

---

## Disruption :warning: 

As can be seen from the Wiki page, much time and effort was dedicated to hardware design and construction, however a fault exists within the final PCB displayed in that the RPi was unable to detect connected I2C devices. The days leading up to the University's closure were spent in an effort to resolve this issue but to no avail. As the group had no access to the equipment or components necessary to continue this work, further development of the hardware was not possible.

The solution to this involved rigorous unit testing with firstly a matrix board that we had developed earlier in the project. This board employed an ADS1115 chip attached with floating inputs and an output connected to the RPi. From this board we could present real-time interrupt based sampling from interaction with one of the GPIO outputs of the RPi. The inputs of the board were connected to a signal generator, presenting realtime filtering, time-smoothing and interrupt based sampling, as well as internet transmission via UDP. We also managed to achieve signal integration with the game as shown in... by using pre-recorded EMG signals recorded before lab closure.

The amplification step, clock and data signals were all proved succesful using a signal generator, so if the issue of I2C address detection was solved for the final PCB, the board would operate as required. Hopefully from the provided unit test videos it can be seen just how close we were to total hardware-software integration. 


Important features of the design:

---

* The differential amplifiers (INA126) are used to obtain differential EMG signals.
   * These input to the ADCs (ADS1115).
   * The ADCs utilise the I2C bus protocol.
* A reference voltage circuit is used to provide a 1.67V reference to the amplifiers so as to offset the EMG signals and retain the negative component.
* A voltage divider and buffering amplifer (TL071) are used to generate the reference voltage.
* Standard decoupling capacitors are used for ADC protection, and clamping diodes are placed at the EMG inputs to short any large static voltages and protect the amplifiers. 

---

**The ADS1115 has the potential to read 4 input channels. However, only one of these channels are utilised per device to maintain a high rate of sampling within each channel.**


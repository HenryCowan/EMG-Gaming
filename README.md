# RTEP
A github to demonstrate workings of Real Time Embedded (RTE) project at the University of Glasgow. 

"Employ EMG as a method of user input to a gaming environment”

**The aim**

The general aim of this project is to develop a system which detects EMG signals from the bicep and tricep muscles and use these signal to innervate movement in a video game. **Get your flex on!**

Firstly we aim to hack simple, existing games as a proof of concept. We can then develop our own, or hack more complicated games. The more more stuff going on in a game, the better it must be! No?


**Methodology**

The methodology is to use two standard Ag/AgCl electrodes placed 20cm apart on the muscle.
The signal from these electrodes is sent through a two stage amplifer, the first stage being the differential stage, 
the second being a gain stage. The output of the amplifier is sent to an ADC and then passed to a Raspberry Pi via I2C data protocol for post-processing and game connection. 

**Potential Uses**

The primary use of this system is to increase the submersion effect of the player into a virtual envinroment.

The system also has uses in the field of rehabilitation, and could be used to encourage otherwise unpleasent rehabilitation programs.

This system could be used in combination with FES stimulation to assist those with muscular or neuronal pathologies.






**Progress** 

We've achieved a working AD7705 pcb to read in a stream of data to start plotting whilst the EMG pcb is being fabricated and tested.

A realtime Qt plot has been acheived, the basis of the plot is presented with window.cpp. 

The EMG adc has been selected as is getting implemented onto a custom pcb for 4 channel EMG recording.


=======================================================================================

We've swapped ADC's to the ads1115 and are reading in rt data from all channels using i2c.

The game is now fully functional and displays on android devices via UDP data transfer.

The game responds to changes in signal from the ADC.

Only thing left to do is get some muscle signals!

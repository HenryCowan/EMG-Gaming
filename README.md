
# :joystick: Muscle Power Gaming: Get Flexing! :joystick:


A repository to demomstrate the use of a Raspberry Pi in controlling a video game with realtime EMG signals. This is part of a course hosted by the University of Glasgow in Real Time Embedded Programming.

The repository describes how to measure EMG signals from the user's bicep and/or ticep muscles, and how these are then used in turn to control the movement of a paddle in the classic game Pong :ping_pong:(the principles being completely transferrable to other relatively rudimentary games). 

## Premise

The simplest video games have very limited inputs. For some this is simply left/right, while for others it may be up/down/left/right. This makes it relatively straightforward to hack these inputs to be controlled by EMG signals (one muscle controls left, another right, etc). With a 4 channel system, we hope to be able to accomodate single-player versions of games requiring 4 input options, or multiplayer versions of games requiring only 2 (a safe outlet for any pent up testosterone!).

The primary use of this system is to increase the level of submersion the player feels within the gaming environment, providing a new challenge, and adding a new dimension to the gaming experience. The system also has potential application in the field of rehabilitation, encouraging persistence with otherwise unpleasent rehabilitation regimes.

## EMG Measurement:

Here we provide a description of the methods that should be employed in measuring user EMG. In light of the recent Covid-19 outbreak, the hardware components of this project remain incomplete and as such sample EMG data was instead obtained using a USB-DUX and bioamplifier for software testing purposes. The acquired EMG data has been deposited in Gitlab, and can be found through the link below, along with an example Python script for filtering and plotting.

[Sample Data](https://gitlab.com/HenryCowan/rte-emg-signals/-/tree/master)

Standard Ag/AgCl electrodes should be place approximately 20cm apart on the chosen muscle(s). In our case, measuring 4 channels, this required a pair of electrodes on each bicep and a pair on each tricep, with a further electrode attached to the ankle to act as ground (9 total). For a 2 channel approach, any 2 pairs of electrodes may be discounted, leaving 5 total.

Had the hardware components been completed, these signals would be sent through a two stage amplifer, the first a differential stage and the second a gain stage. The output from the amplifier is sent to an ADC (ADS1115) and passed to a Raspberry Pi via the I2C bus protocol for post-processing and game connection. Using the sample EMG data, the amplifification stage was subverted, applying directly to the ADC component.  

## Outcomes

- A PCB using the AD7705 has been produced to read an artificial stream of data. This will allow data handling to be explored while fabricating and testing components associated with acquiring EMG data.

- The ADC for the EMG recording has been chosed as the ADS1115, and was implemented into a custom PCB, 4 ADS1115 for 4 input channels of differential EMG. The specifications of the ADS1115 can be found through the link below:

[ADS1115 Spec Sheet](http://www.ti.com/lit/ds/symlink/ads1114.pdf)

- The PCB using the ADS1115 now detects data in realtime from 1 channel using I2C. 

- RPI-end software: 	
1. ADS1115 driver reads in continuos data, [see here](https://github.com/TheUltraSoundGuys/RTEP/tree/master/Rpi_end/Rpi_end_unit_tests/0322%20High_speed_continous_ads1115%20unit).
1. Interrupt based sampling achieved using the GPIOlis command, [see here](https://github.com/TheUltraSoundGuys/RTEP/tree/master/Rpi_end/Rpi_end_unit_tests/0321%20GPIO_lis_interrupt_thread_unit).
1. Working IIR filter acheived, [see here](https://github.com/TheUltraSoundGuys/RTEP/tree/master/Rpi_end/Rpi_end_unit_tests/0304%20data%20filter%20%2Budp%20%20unit).
1. Time smoothing of EMG data acheived, [see here](https://github.com/TheUltraSoundGuys/RTEP/tree/master/Rpi_end/Rpi_end_unit_tests/0304%20data%20filter%20%2Budp%20%20unit).
1. Transmission of filtered and smoothed EMG data via UDP acheived, [see here](https://github.com/TheUltraSoundGuys/RTEP/blob/master/Rpi_end/Rpi_end_unit_tests/0304%20data%20filter%20%2Budp%20%20unit/window.cpp).
1. Plotting of the EMG data achieved, [see here](https://github.com/TheUltraSoundGuys/RTEP/blob/master/Rpi_end/Rpi_end_unit_tests/0304%20data%20filter%20%2Budp%20%20unit/window.cpp).

- Server end (Android) software

1. Pong game controlled by EMG signal (2 channel, for single channel see branch single-ch), [see here](https://github.com/TheUltraSoundGuys/RTEP/tree/master/Server_end/0301%20Pong%20GUI).	
1. Unit test of game using [pre-recorded EMG](https://gitlab.com/HenryCowan/rte-emg-signals/-/tree/master), [see here](https://github.com/TheUltraSoundGuys/RTEP/tree/master/Server_end/0301%20Pong%20GUI/0408-emg-read-in-local)

**And all of this done synchronously and in real-time! For an example video of each process, see the README in each folder** 


## Social Media

Below are the links to our Facebook and Twitter pages where you can keep up to date with all our latest and most exciting developments!

[Muscle Power Gaming - Facebook](https://www.facebook.com/EMGamingRPI/)

[Muscle Power Gaming - Twitter](https://twitter.com/emg_pi)

## Contribution
* **Henry Cowan:**
 
1. _Circuit design_
1. _Schematic draw-up_
1. _PCB design_
1. _PCB construction_
1. _Component selection_
1. _Hardware documentation_
1. _The wiki page_
1. _EMG Signal gitlab repo_
1. _General github maintenance_

* **Zonghan Gan**: 

1. _Data Processing_
1. _UDP transmission_
1. _ADC driver_
1. _GPIO interrupt system_
1. _Android Server_
1. _The game!_

* **Finlay Nelson**:

1. _Software Documentation_
1. _EMG Test Signal Recording_
1. _Social Media Presence_
1. _Github maintenance_



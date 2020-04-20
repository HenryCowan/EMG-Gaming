
# Muscle Power Gaming: Get Flexing! :video_game:

This repository demomstrates the use of a Raspberry Pi in controlling a video game using realtime EMG signals. This is part of a course hosted by the University of Glasgow in Real Time Embedded Programming.

The repository describes how to measure EMG signals from the user's bicep and/or ticep muscles, and how these are then used in turn to control the movement of a paddle in the classic game Pong :ping_pong: (the principles being completely transferrable to other relatively rudimentary games). 

## Premise

The simplest video games have very limited inputs. For some this is simply left/right, while for others it may be up/down/left/right. This makes it relatively straightforward to hack these inputs to be controlled by EMG signals (one muscle controls left, another right, etc). With a 4 channel system, we hope to be able to accomodate single-player versions of games requiring 4 input options, or multiplayer versions of games requiring only 2 (a safe outlet for any pent up testosterone!).

The primary use of this system is to increase the level of submersion the player feels within the gaming environment, providing a new challenge, and adding a new dimension to the gaming experience. The system also has potential application in the field of rehabilitation, encouraging persistence with otherwise unpleasant rehabilitation regimes.

## Social Media

Below are the links to our Facebook and Twitter pages where you can keep up to date with all our latest and most exciting developments. You can also find our code documentation so you can get to grips with our work yourselves!

[Muscle Power Gaming - Facebook](https://www.facebook.com/EMGamingRPI/)

[Muscle Power Gaming - Twitter](https://twitter.com/emg_pi)

[Software documentation!](https://finlay-nelson.github.io/Test.io/.)

## EMG Measurement :muscle:

Here we provide a description of the methods that should be employed in measuring user EMG. In light of the recent Covid-19 outbreak, the hardware components of this project remain incomplete and as such sample EMG data was instead obtained using a [USB-DUX](https://www.linux-usb-daq.co.uk/order2/) and bioamplifier for software testing purposes. The acquired EMG data has been deposited in Gitlab, and can be found through the link below, along with an example Python script for filtering and plotting.

[Sample Data](https://gitlab.com/HenryCowan/rte-emg-signals/-/tree/master)

Standard Ag/AgCl electrodes should be place approximately 20cm apart on the chosen muscle(s). In our case, measuring 4 channels, this required a pair of electrodes on each bicep and a pair on each tricep, with a further electrode attached to the ankle to act as ground (9 total). For a 2 channel approach, any 2 pairs of electrodes may be discounted, leaving 5 total.

Had the hardware components been completed, these signals would be sent through a two stage amplifer, the first a differential stage and the second a gain stage. The output from the amplifier is sent to an ADC (ADS1115) and passed to a Raspberry Pi via the I2C bus protocol for post-processing and game connection. Using the sample EMG data, the amplifification stage was subverted, applying directly to the ADC component.  

## Outcomes

- [x] A PCB using the AD7705 has been produced to read an artificial stream of data. This will allow data handling to be explored while fabricating and testing components associated with acquiring EMG data.

- [x] The ADC for the EMG recording has been selected as the ADS1115, and is being implemented into a custom PCB with 4 channel inputs. The specifications of the ADS1115 can be found through the link below:

[ADS1115 Spec Sheet](http://www.ti.com/lit/ds/symlink/ads1114.pdf)

- [x] Through use of the QT toolkit, a realtime plotting script has been tested. It is thought that presenting this to the user as a form of biofeedback could act as an effective means of encouragement. 

- [x] The PCB using the ADS1115 now detects data in realtime from 1 channel using I2C.

- [ ] Work to the 4 channel PCB could not be completed due to disruption caused by the COVID-19 outbreak. Follow the attached link to see our progress with the hardware elements
  - [Hardware](https://github.com/TheUltraSoundGuys/RTEP/tree/master/Hardware)

- RPI-end software
  - ADS1115 driver reads in continuous data [:ballot_box_with_check:](https://github.com/TheUltraSoundGuys/RTEP/tree/master/Rpi_end/Ads1115ContinousDriver)
  - Interrupt based sampling achieved using the [GPIOlis command](https://github.com/TheUltraSoundGuys/RTEP/tree/master/Rpi_end/Rpi%20end%20together).
  - Working [IIR filter](https://github.com/TheUltraSoundGuys/RTEP/tree/master/Rpi_end/unit%20tests%20in%20RPI%20end/Data%20filter%2Budp%20sending%20unit).
  - [Time smoothing](https://github.com/TheUltraSoundGuys/RTEP/tree/master/Rpi_end/unit%20tests%20in%20RPI%20end/Data%20filter%2Budp%20sending%20unit) of EMG data acheived 
  - Transmission of filtered and smoothed EMG data via [UDP](https://github.com/TheUltraSoundGuys/RTEP/blob/master/Rpi_end/unit%20tests%20in%20RPI%20end/Data%20filter%2Budp%20sending%20unit/window.cpp).
  - [Plotting](https://github.com/TheUltraSoundGuys/RTEP/blob/master/Rpi_end/unit%20tests%20in%20RPI%20end/Data%20filter%2Budp%20sending%20unit/window.cpp) of the EMG data achieved.

- Server end (Android) software

  - [Pong game](https://github.com/TheUltraSoundGuys/RTEP/tree/master/Server_end/Server%20Pong%20GUI-all%20together) controlled by EMG signal (2 channel, for single channel see branch single-ch).

**And all of this done synchronously and in real-time! For an example video of each process, see the README in each folder** 

## Primary Contributions

- Henry Cowan
  - Circuit Design
  - Schematic draw-up
  - PCB Design & Construction
  - Component Selection
  - Hardware Documentation
  - Wiki Page (Hardware)
  - EMG Signal Gitlab Repo
  - General Github Maintenance

- Zonghan Gan
  - Data Processing
  - UDP Transmission
  - ADC driver
  - GPIO Interrupt System
  - Android Server
  - The Game

- Finlay Nelson
  - Software Documentation
  - EMG Test Signal Recording
  - Social Media Presence
  - Github Maintenance
  - Wiki Page (Software)



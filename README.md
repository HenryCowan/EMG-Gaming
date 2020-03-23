
# :joystick: Muscle Power Gaming: Get Flexing! :joystick:


A repository to demomstrate the use of a Raspberry Pi in controlling a video game with realtime EMG signals. This is part of a course hosted by the University of Glasgow in Real Time Embedded Programming.

The repository describes how to measure EMG signals from the user's bicep and/or ticep muscles, and how these are then used in turn to control the movement of a paddle in the classic game Pong :ping_pong:(the principles being completely transferrable to other relatively rudimentary games). 

## Premise

The simplest video games have very limited inputs. For some this is simply left/right, while for others it may be up/down/left/right. This makes it relatively straightforward to hack these inputs to be controlled by EMG signals (one muscle controls left, another right, etc). With a 4 channel system, we hope to be able to accomodate single-player versions of games requiring 4 input options, or multiplayer versions of games requiring only 2 (a safe outlet for any pent up testosterone!).

The primary use of this system is to increase the level of submersion the player feels within the gaming environment, providing a new challenge, and adding a new dimension to the gaming experience. The system also has potential application in the field of rehabilitation, encouraging persistence with otherwise unpleasent rehabilitation regimes.

## EMG Measurement :muscle:

Here we provide a description of the methods that should be employed in measuring user EMG. In light of the recent Covid-19 outbreak, the hardware components of this project remain incomplete and as such sample EMG data was instead obtained using a USB-DUX and bioamplifier for software testing purposes. The acquired EMG data has been deposited in Gitlab, and can be found through the link below, along with an example Python script for filtering and plotting.

[Sample Data](https://gitlab.com/HenryCowan/rte-emg-signals/-/tree/master)

Standard Ag/AgCl electrodes should be place approximately 20cm apart on the chosen muscle(s). In our case, measuring 4 channels, this required a pair of electrodes on each bicep and a pair on each tricep, with a further electrode attached to the ankle to act as ground (9 total). For a 2 channel approach, any 2 pairs of electrodes may be discounted, leaving 5 total.

Had the hardware components been completed, these signals would be sent through a two stage amplifer, the first a differential stage and the second a gain stage. The output from the amplifier is sent to an ADC (ADS1115) and passed to a Raspberry Pi via the I2C bus protocol for post-processing and game connection. Using the sample EMG data, the amplifification stage was subverted, applying directly to the ADC component.  

## Progress

- [x] A PCB using the AD7705 has been produced to read an artificial stream of data. This will allow data handling to be explored while fabricating and testing components associated with acquiring EMG data.

- [x] Through use of the QT toolkit, a realtime plotting script has been tested. It is thought that presenting this to the user as a form of biofeedback could act as an effective means of encouragement. 

- [x] The ADC for the EMG recording has been selected as the ADS1115, and is being implemented into a custom PCB with 4 channel inputs. The specifications of the ADS1115 can be found through the link below:

[ADS1115 Spec Sheet](http://www.ti.com/lit/ds/symlink/ads1114.pdf)

- [x] The PCB using the ADS1115 now detects data in realtime from 1 channel using I2C. This single channel data can be used in the game (Pong), transferring data using the UDP and displaying on android devices, and responds to changes in input to the ADC

- [ ] Apply prerecorded EMG data to the ADC to control the game

- [ ] Apply live incoming EMG data to control the game

## Social Media

Below are the links to our Facebook and Twitter pages where you can keep up to date with all our latest and most exciting developments!

[Muscle Power Gaming - Facebook](https://www.facebook.com/EMGamingRPI/)

[Muscle Power Gaming - Twitter](https://twitter.com/emg_pi)

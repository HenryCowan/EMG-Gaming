# Rpi end code together
This folder contains all of the code for the RaspberryPi and ADS1115 together. This code covers the execution of:
1. The ADS1115 driver
1. Interrupt driven sampling
1. Multiple realtime plotting windows
1. An IIR filter 
1. Power and time-smoothing
1. Internet sending (UDP)

All of this is done synchronously and in real-time! 

## Unit Test Videos

https://www.youtube.com/watch?v=j-3AxjxNN2I
https://www.youtube.com/watch?v=jThJus-PdIQ

## Making it work


```
      git clone https://github.com/TheUltraSoundGuys/RTEP.git
      cd RTEP/Rpi_end/Rpi end together
```

To build, enter the folder and run in terminal:

```
    qmake
    make
```

To run (assuming you are logged into the RPi over ssh and no X-server is running):

```
    ./QwtExample
```

Pre-requisites 

Before running the code an IIR filter library from Dr Bernd Porr must be installed in advance. For the library and how to install, see [here](https://github.com/berndporr/iir1)

Adapt the path of iir1 lib in the .pro file to the iir1 path on your computer.

The WiringPi library must also be installed in advance. For the library and how to install, [see](http://wiringpi.com/download-and-install/)

Adapt the path of WiringPi lib in the .pro file to the WiringPi path on your computer.

# QwtExample+iir+power time smooth+udp sending

This is a unit test for the data processing and udp sending of an artificial sine function sampling at 200hz using the coarse timer of QT.

Raw data
![](origin.png)

High-passed, Fc = 10Hz
![](flhp1ed.png)

## Pre-requisites 

Before running the code an IIR filter library from Dr Bernd Porr must be installed in advance. For the library and how to install, see [here](https://github.com/berndporr/iir1)

Adapt the path of iir1 lib in the .pro file to the iir1 path on your computer.

## Making it work


```
      git clone https://github.com/TheUltraSoundGuys/RTEP.git
      cd RTEP/Rpi_end/unit tests in RPI end/Data filter+udp sending unit
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


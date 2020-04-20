## Realtime plotting/UDP-sending of filtered and power-time-smoothed EMG signals.

Below is an example of the raw data and filtered/smoothed data which will be send via UDP.

![](origin.png)

![](flhp1ed.png)

The first image displays the raw data, while the second shows the high-pass filtered and smoothed data (Fc = 10Hz; smoothed over 5 samples)

## Pre-requisites 

Before running the code an IIR filter library from Dr Bernd Porr must be installed in advance. For the library and how to install, see [here](https://github.com/berndporr/iir1)

Adapt the path of iir1 lib in the .pro file to the iir1 path on your computer.

## Action :movie_camera:


```
    git clone https://github.com/TheUltraSoundGuys/RTEP.git
    cd RTEP/Rpi_end/unit tests in RPI end/Data filter+udp sending unit
    qmake
    make
```

To run (assuming you are logged into the RPi over ssh and no X-server is running):

```
    ./QwtExample
```


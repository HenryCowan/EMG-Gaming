## Unit-tested: GPIO interrupt thread
The GPIOlis is a thread which will listen for a the GPIO interrupt pulse. In this test demo, the thread listens to the GPIO 1(PIN 12) from the RPi and interacts with the debug class in the main function which outputs a 'conversion ready' signal.
The GPIO monitoring is used to detect the 'conversion_ready' signal of the ADS1115 in continous mode (8us pulse for every conversion in continous mode) from the Alrt pin of the ADS1115 to the GPIO of the RPi.

---

## Demonstration Video :movie_camera:
[Video - Demonstration](https://www.youtube.com/watch?v=0bYEkJsHWhk)

---

## Pre-requisites 

The WiringPi library must also be installed in advance. For the library and how to install, see [here](http://wiringpi.com/download-and-install/).

Adapt the path of WiringPi lib in the .pro file to the WiringPi path on your computer.

---

## Action :clapper:


```
    git clone https://github.com/TheUltraSoundGuys/RTEP.git
    cd RTEP/Rpi_end/'unit tests in RPI end'/'GPIO interrupt monitor unit'
    qmake
    make 
```

To run (assuming you are logged into the RPi over ssh and no X-server is running):

```
    ./GPIOlis
```





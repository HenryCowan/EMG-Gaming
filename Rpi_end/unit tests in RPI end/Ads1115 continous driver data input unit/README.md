



## High speed continuous driver for the ADS1115 :runner:

To control the ADS1115 to read at in at a rate of greater than 400 samples per second, the ADC driver should control ADS1115 in continuous mode. We could not find a pre-existing ADS1115 continous driver in C++, so we wrote this QT/C++ one.

To see how we've tested this driver, check out this [code](https://github.com/TheUltraSoundGuys/RTEP/tree/master/Rpi_end/unit%20tests%20in%20RPI%20end/Ads1115%20continous%20driver%20data%20input%20unit) and the following demonstration videos!

* This video shows the unit test of the ADS1115 continuous driver:
  * [Continuous Driver](https://www.youtube.com/watch?v=aBgsSWfQyrE)

* This video shows the driver working with interrupt based sampling:
  * [Interrupt-based sampling](https://www.youtube.com/watch?v=M4weTT-E-Fw)
  
  

## Pre-requisites 

Before running the code, an IIR filter library from Dr Bernd Porr must be installed in advance. For the library and how to install, see [here](https://github.com/berndporr/iir1).

Adapt the path of iir1 lib in the .pro file to the iir1 path on your computer.



---

## Action :clapper:


```
    git clone https://github.com/TheUltraSoundGuys/RTEP.git
    cd Rpi_end\'unit tests in RPI end' \'Ads1115 continous driver data input unit' \
    qmake
    make
```

To run (assuming you are logged into the RPi over ssh and no X-server is running):

```
    ./QwtExample
```


---

## References

These two sites were used to aid our driver construction:

For those who can read Mandarin, [this](https://blog.csdn.net/weixin_45380951/article/details/103268996) is the site for you!

For those who are more comfortable speaking English - check out the [Adafruit python library](https://github.com/adafruit/Adafruit_Python_ADS1x15/blob/804728974fcefaafc8b5994be65d22e9c198a8d1/Adafruit_ADS1x15/ADS1x15.py#L297).


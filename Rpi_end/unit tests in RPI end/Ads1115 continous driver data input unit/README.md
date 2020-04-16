# High speed continous driver of ads1115

To control the ads1115 to read at >400hz, the ads driver should control ads1115 in continous mode
However, there is no existed ads1115 continous lib in C++ found so I write this QT/C++ one 
no need to write config every time before every reading, thus time interval can go beneath 2ms 
2020-03-19
## unit test video
https://www.youtube.com/watch?v=aBgsSWfQyrE
unit test - conversion ready signal/interrupt
https://www.youtube.com/watch?v=M4weTT-E-Fw

## Making it work

download files in this folder.

To build, entre the folder and run in terminal:

```
    qmake
    make
```

To run (assuming you are logged into the RPi over ssh and no X-server is running):

```
    ./QwtExample
```
Also, to run the code, the iir1 filter library from DR Bernd Porr need to be installed in advance. for the library and how to install, see
https://github.com/berndporr/iir1

adapt the path of iir1 lib in the .pro file to the iir1 path on your raspberry pi

## bibliography
https://blog.csdn.net/weixin_45380951/article/details/103268996
https://github.com/adafruit/Adafruit_Python_ADS1x15/blob/804728974fcefaafc8b5994be65d22e9c198a8d1/Adafruit_ADS1x15/ADS1x15.py#L297

## 2020-03-21
This is the unit tested version of the ads1115 driver
modification to previous intro
        There is no ads1115 continuous mode library in c++, but there is another python lib
        And another C code is found which is not yet object oriented but a demo and also continuous mode, yet not totally in the mode giving conversion ready interrupt

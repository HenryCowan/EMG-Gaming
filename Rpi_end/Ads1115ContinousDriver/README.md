# High speed continous driver of ads1115

To control the ads1115 to read at >400hz, the ads driver should control ads1115 in continous mode
However, there is no existed ads1115 continous lib in C++ found so I write this QT/C++ one 
no need to write config every time before every reading, thus time interval can go beneath 2ms 
2020-03-19

## bibliography
https://blog.csdn.net/weixin_45380951/article/details/103268996
https://github.com/adafruit/Adafruit_Python_ADS1x15/blob/804728974fcefaafc8b5994be65d22e9c198a8d1/Adafruit_ADS1x15/ADS1x15.py#L297

## Demo
see

 RTEP\Rpi_end\Rpi_end_unit_tests\0322 High_speed_continous_ads1115 unit
### demo/unit test video
https://www.youtube.com/watch?v=aBgsSWfQyrE
unit test - conversion ready signal/interrupt
https://www.youtube.com/watch?v=M4weTT-E-Fw

## 2020-03-21
This is the unit tested version of the ads1115 driver
modification to previous intro
        There is no ads1115 continuous mode library in c++, but there is another python lib
        And another C code is found which is not yet object oriented but a demo and also continuous mode, yet not totally in the mode giving conversion ready interrupt

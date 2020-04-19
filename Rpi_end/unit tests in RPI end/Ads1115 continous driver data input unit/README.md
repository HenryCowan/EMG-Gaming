# High speed continous driver of ads1115

To control the ADS1115 to read at >400Hz, the ads driver should control ADS1115 in continous mode
We could not find a pre-existing ADS1115 continous driver in C++, so we wrote this QT/C++ one.

To see how we've tested this driver, check the code [here](RTEP\Rpi_end\Rpi_end_unit_tests\0322 High_speed_continous_ads1115) and the following demonstration videos.

This video shows the unit test of the ADS1115 continuous driver:

https://www.youtube.com/watch?v=aBgsSWfQyrE

This video shows the driver working with interrupt based sampling:

https://www.youtube.com/watch?v=M4weTT-E-Fw

## References

These two sites were sued to aid our driver construction. For those who can read Mandarin, this is the site for you.
https://blog.csdn.net/weixin_45380951/article/details/103268996

For those who are more comfortable speaking English - check out the Adafruit python library [here](https://github.com/adafruit/Adafruit_Python_ADS1x15/blob/804728974fcefaafc8b5994be65d22e9c198a8d1/Adafruit_ADS1x15/ADS1x15.py#L297).






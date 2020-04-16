# Unit-tested: rpi end code together


This is the work sample for raspberryPi+ads1115 of all rpi end code together, including:
      ads driver
      thread monitering gpio interrupt
      rt plot
      iir
      power time smooth
      internet sending (UDP)
## unit test video
https://www.youtube.com/watch?v=j-3AxjxNN2I
https://www.youtube.com/watch?v=jThJus-PdIQ

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

the WiringPi lib need to be installed in advance. for the library and how to install, see 

http://wiringpi.com/download-and-install/ 

adapt the path of WiringPi lib in the .pro file to the WiringPi path on your raspberry pi

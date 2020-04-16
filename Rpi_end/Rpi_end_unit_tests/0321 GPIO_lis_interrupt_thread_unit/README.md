# unit-tested: Thread listen to GPIO interrupt
The GPIOlis is a thread which will listen to the GPIO impulse interrupt.
In this test demo, the thread would listen to the GPIO 1(PIN 12) and interact with the debug class in main function which would plot "conversion ready"
Such GPIO monitor is used to detect the conversion_ready of ads1115 in continous mode (8us pulse every conversion in ads continous mode) from Alrt of ads1115 to GPIO of rpi
## unit test video
https://www.youtube.com/watch?v=0bYEkJsHWhk

## Making it work

download files in this folder.

To build, entre the folder and run in terminal:

```
    qmake
    make
```

To run (assuming you are logged into the RPi over ssh and no X-server is running):

```
    ./GPIOlis
```



unit-tested: Thread listen to GPIO interrupt
The GPIOlis is a thread which will listen to the GPIO impulse interrupt.
In this test demo, the thread would listen to the GPIO 1(PIN 12) and interact with the debug class in main function which would plot "conversion ready"
Such GPIO monitor is used to detect the conversion_ready of ads1115 in continous mode (8us pulse every conversion in ads continous mode)
unit test video
https://www.youtube.com/watch?v=0bYEkJsHWhk

# QwtExample+iir+power time smooth+udp sending

This is a unit test to do the data processing and udp sending of an artificial function sampling at 200hz using the coarse timer of qt






![origin](origin.png)











![hp fc=10hz](flhp1ed.png)
## Making it work

Install the QT5 and Qwt development packages:

```
    apt-get install qtdeclarative5-dev-tools
    apt-get install libqwt-qt5-dev
```

To clone this git repository.

To build, open the path and run in terminal:

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

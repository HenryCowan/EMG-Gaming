# QwtExample+iir+power time smooth+udp sending

This is a unit test to do the data processing and udp sending of an artificial function sampling at 200hz using the coarse timer of qt

## Making it work

Install the QT5 and Qwt development packages:

```
    apt-get install qtdeclarative5-dev-tools
    apt-get install libqwt-qt5-dev
```

To clone this git repository.

To build:

```
    cd qwt-example
    qmake
    make
```

To run (assuming you are logged into the RPi over ssh and no X-server is running):

```
    startx ./QwtExample
```

or with X running

```
    ./QwtExample
```


## Pong controlled by EMG from server :ping_pong:

**This code is for the use of 2 EMG channels**

The games refresh rate is based on a local counter rather than a timer. This is to avoid coarse timer errors imposed as a result of the Android systems polling timer.

### Check it out the video below:
[Unit test](https://www.youtube.com/watch?v=rDG5sTIDT1k)

## Compilation

### Android
1. Compile Qt & Qt creator from source intergrated Qt for Android. Install Android SDK from source and set SDK & NDK. Connect the path to SDK & NDK in Qt creator settings to form a tool chain.
2. Connect an Android phone to the computer, set the mode 'transferring file', turn on developer mode and UDP testing.
3. In Qt creator on the computer, open the .pro file, select Qt for android-release for debug, then click run.
4. Approve installation on Android phone. 

**For the testing, an ubuntu 18.04 pc and an android 9.0.0 HUAWEI Mate 20 were used.**

### PC
1. Directly run in Qt creator.

## Local signal input
 You can either directly send from the  RPi end, or using 'emg-read-in-local' in the child path reading in local EMG data (sent in at 1000Hz). See [here](RTEP\Server_end\Server Pong GUI-all together\0408-emg-read-in-local).
 
## To play the game on pc without compiling Qt for android (Qt creator is required)
1. Download all the files in 'Server Pong GUI-all together\ and 0408-emg-read-in-local\', including the EMG data files
2. Change all IP address' to "127.0.0.1" in the 'Server Pong GUI-all together\mainwindow.cpp' and 'Server Pong GUI-all together\0408-emg-read-in-local\window.cpp'; adapt the EMG data file path in 'Server Pong GUI-all together\0408-emg-read-in-local\GPIOlis.cpp' to current path.
3. Open the GUI and the 'emg-read-in-local' both in Qt creator.
4. First run the GUI.
5. Then run the emg-read-in-local. :)

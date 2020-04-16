# server(mobile) pong: this is a Pong game using read in processed emg data to controll
this demo is for 2 emg channel
## this game refresh based on sample counting receiving from local, instead of timer. Android sys is with a polling time and cause coarse timer error.

## unit test video
https://www.youtube.com/watch?v=rDG5sTIDT1k

## compile
### Android
1. compile QT&QT creator from source intergrated QT for android. Install android SDK from source and set SDK&NDK. Connect the path to SDK&NDK in qt creator setting to form tool chain
2. connect an android phone to the pc, set the mode "transferring file", turn on developer mode and USP testing
3. In qt creator on PC, open the .pro file, select Qt for android-release for debug, then click run
4. approve installation on android phone. In the testing, an ubuntu 18.04 pc and an android 9.0.0 HUAWEI Mate 20 is used
### On PC
1. directly run in qt creator

## sig input from local
 either directly send from rpi end, or using the emg-read-in-local in the child path reading in local emg dat and send in 1000hz (RTEP\Server_end\Server Pong GUI-all together\0408-emg-read-in-local)
 
## To play with it on pc without compiling qt for android (qt creator is required)
1. change all ip address to "127.0.0.1" in the RTEP\Server_end\Server Pong GUI-all together\mainwindow.cpp and RTEP\Server_end\Server Pong GUI-all together\0408-emg-read-in-local\window.cpp 
2. Open the gui and the emg-read-in both in qt creator
3. first run the gui, then run the emg-read-in

/**
 *
 * "A Collection of Useful C++ Classes for Rpi sample (+ads1115), UDP transmission and Server (Android) Pong Game"
 * By Zonghan Gan
 *
 * Official project location:
 * https://github.com/TheUltraSoundGuys/RTEP
 *
 * License: MIT License (http://www.opensource.org/licenses/mit-license.php)
 * Copyright (c) 2020 by Zonghan Gan
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 **/
#ifndef GPIOLIS_H
#define GPIOLIS_H
#include <QThread>
/************************************************************\
 * class: GPIOlis
 * feature: lis to GPIO connected to Alert of ads1115, in continous mode, interrupt every time 
		*	ad conversion is ready
		*	then send the data and trigger datapros in signal-slot mechanism
 * function:
*		run();							listen to interrupt and call back interrupt. every time detect, sleep 1ms
*		interrupt();                    read in data and send readyread signal

 * Author: Zonghan Gan
 *  version        date              
 *  v1.0.0    2020-3-21-01-03    

\************************************************************/
extern int gpipinterrupt;
class GPIOlis : public QThread {
    Q_OBJECT
    int flag=1;
public:
    GPIOlis(QObject *parent=0);
    ~GPIOlis();
    void interrupt(void);
    int count;
protected:
    void run();
signals:
    void ready();
};

#endif // GPIOLIS_H

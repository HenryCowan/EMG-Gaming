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
#ifndef WINDOW_H
#define WINDOW_H
#include <qwt/qwt_thermo.h>
#include <qwt/qwt_knob.h>
#include <qwt/qwt_plot.h>
#include <qwt/qwt_plot_curve.h>
#include <QBoxLayout>
#include <QUdpSocket>
#include <Iir.h>
#include <QWidget>
#include <QTimer>
#include "ads1115.h"




using namespace std;
// class definition 'Window'
class QTimer;


/************************************************************\
 * class: window
 * feature: receive signal from ads1115(continous), filter the data and send through udp
 * function:
 *         datapros() - readin, filter, process and udp send data
 *         plotrefresh() - refresh plot with new data
 *
 * Author: Bernd Porr; Zonghan Gan
 *  version        date              des
 *  v4.0.0    2020-3-19-00-16     test of adslib, controlled by timer

\************************************************************/

class Window : public QWidget
{
    // must include the Q_OBJECT macro for for the Qt signals/slots framework to work with this class
    Q_OBJECT

public:

    QUdpSocket *sdersc;
    explicit Window(QWidget *parent = 0);// default constructor - called when a Window is declared without arguments

    ~Window();


    ads1115 *ads1;
    QTimer *rdtimer;
    QTimer *rftimer;
public slots:
    void setGain(double gain);
    void datapros(float);
    void plotrefresh();
// internal variables for the window class
private:



    //QwtKnob      *knob;
    QwtPlot      *plot1;
    QwtPlotCurve *curve1;
    QwtPlot      *plot2;
    QwtPlotCurve *curve2;


    // layout elements from Qt itself http://qt-project.org/doc/qt-4.8/classes.html
    //QVBoxLayout  *vLayout;  // vertical layout
    QHBoxLayout  *hLayout;  // horizontal layout

    static const int plotDataSize = 100;

    // data arrays for the plot
    double xData1[plotDataSize];
    double yData1[plotDataSize];
    double xData2[plotDataSize];
    double yData2[plotDataSize];
    double xData3[plotDataSize];
    double yData3[plotDataSize];

    double sumpower;
    double gain;
    int count;




//	ADCreader *adcreader;
};

#endif // WINDOW_H

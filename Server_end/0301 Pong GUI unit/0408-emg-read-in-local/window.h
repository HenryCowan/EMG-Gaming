#ifndef WINDOW_H
#define WINDOW_H

#include <qwt/qwt_thermo.h>
#include <qwt/qwt_knob.h>
#include <qwt/qwt_plot.h>
#include <qwt/qwt_plot_curve.h>

#include <QBoxLayout>
#include <QUdpSocket>
#include "Iir.h"
#include <Iir.h>
#include <QWidget>
#include <QTimer>
#include "ads1115.h"
#include "GPIOlis.h"



using namespace std;
// class definition 'Window'
class QTimer;


/************************************************************\
 * class: window 
 * feature: get data from GPIOlis, filter and process and send through udp to server (android)
 * function:
 *         datapros() - filter, power and time smooth of data, udp sending
 *         plotrefresh() - refresh plot with new data
 *
 * Author: Bernd Porr; Zonghan Gan
 *  version        date              
 *  v4.0.0    2020-3-19-00-16     

\************************************************************/

class Window : public QWidget
{
    // must include the Q_OBJECT macro for for the Qt signals/slots framework to work with this class
    Q_OBJECT

public:

    QUdpSocket *sdersc;
    explicit Window(QWidget *parent = 0);// default constructor - called when a Window is declared without arguments

    ~Window();


    GPIOlis* gpiolis1;

    QTimer *rftimer;
public slots:

    void datapros(float ch1, float ch2);
    void plotrefresh();
// internal variables for the window class
private:




    QwtPlot      *plot1;
    QwtPlotCurve *curve1;
    QwtPlot      *plot2;
    QwtPlotCurve *curve2;


    // layout elements from Qt itself http://qt-project.org/doc/qt-4.8/classes.html
    //QVBoxLayout  *vLayout;  // vertical layout
    QHBoxLayout  *hLayout;  // horizontal layout

    static const int plotDataSize = 5;

    // data arrays for the plot
    double xData1[plotDataSize];
    double yData1[plotDataSize];
    double xData2[plotDataSize];
    double yData2[plotDataSize];
    double xData3[plotDataSize];
    double yData3[plotDataSize];


    double yData2_1[plotDataSize];
    double yData2_2[plotDataSize];
    double yData2_3[plotDataSize];

    double sumpower;
    //double sumpower2;
//    double gain;
    int count;




//	ADCreader *adcreader;
};

#endif // WINDOW_H

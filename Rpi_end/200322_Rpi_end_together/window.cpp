/* This demo is to test the ads1115 lib self-written to sample continously
 *  no such lib for ads1115 in c++ yet.
 *  in this test demo the ads sampling is controlled by timer
 * instead of interrupt. This is not because we can't
 * This is to separate the lib and expose if any bug
 * the interrupt thread unit will soon comes out
 *  --Zonghan Gan 200318 23-39*/

#include "window.h"
#include "ads1115.h"
#include <Iir.h>
#include "GPIOlis.h"
#include <cmath>  // for sine stuff
#include<stdio.h>
#include<stdlib.h>
#include <QObject>

 using namespace std;
 //set filter
 const int order = 40;

 // sampling rate here 1kHz as an example
 const float samplingrate = 860;

 const quint16 sderprt = 1117;
 const quint16 rscverprt = 1112;

 FILE *florigin = NULL;
 FILE *flhp1 = NULL;
 FILE *flpower=NULL;
 Iir::Butterworth::HighPass<order> hp1;

Window::Window(QWidget *parent): QWidget(parent)
{
        count = 0;
        // set up the initial plot data
        for( int index=0; index<plotDataSize; ++index )
        {
            xData1[index] = index;
            yData1[index] = 0;
            xData2[index] = index;
            yData2[index] = 0;
            xData3[index] = index;
            yData3[index] = 0;
        }

        curve1 = new QwtPlotCurve;
        curve2 = new QwtPlotCurve;
        plot1 = new QwtPlot;
        plot2 = new QwtPlot;
// make a plot curve from the data and attach it to the plot
        curve1->setSamples(xData1, yData1, plotDataSize);
        curve1->attach(plot1);
        curve2->setSamples(xData2, yData2, plotDataSize);
        curve2->attach(plot2);
        plot1->replot();
        plot1->show();
        plot2->replot();
        plot2->show();
        hLayout = new QHBoxLayout;
        hLayout->addWidget(plot1);
        hLayout->addWidget(plot2);
        setLayout(hLayout);
// Butterworth highpass
    const float cutoff_frequency = 2; // Hz
    const float passband_gain = 10; // db
    hp1.setup (samplingrate, cutoff_frequency);


//create file to log data
    flhp1 = fopen("flhp1ed.dat","wt");
    florigin = fopen("origin.dat","wt");
    flpower = fopen("flpowertimesmooth.dat","wt");

//initialize ads

    rftimer = new QTimer;

    rftimer->setInterval(20);//refresh every ~20ms

    rftimer->start();
    connect(rftimer, &QTimer::timeout, this, &Window::plotrefresh);
//initialize UDP sender the udp has been testified and commented as not essential in this test, yet have fun if you want--Zonghan Gan
    //initialize UDP sender
    sdersc= new QUdpSocket;
    //bind local address and check
    sdersc->bind(QHostAddress("192.168.1.174"), sderprt);
    //sdersc->bind(QHostAddress::LocalHost, sderprt);
        //qDebug()<<"sender sc bind sucess";
    sumpower=0.0;
    gpiolis1=new GPIOlis();
    connect( gpiolis1, &GPIOlis::readyread, this, &Window::datapros);
    gpiolis1->start();

}
/* Function to end window
*===================================*/
Window::~Window() {
    delete &hp1;

    gpiolis1->quit();
	delete plot1;
	delete plot2;
	delete curve1;
	delete curve2;
	delete hLayout;
    delete gpiolis1;
	delete rftimer;
	delete sderprt;
	
	

	
//close the file writing
    fclose(florigin);
    fclose(flhp1);
    fclose(flpower);
}
/* Function to process data
*===================================*/
void Window::datapros(float inval)
{
    qDebug()<<"new data feed in";

    float inVal1= inval;
    float inVal1_2 = hp1.filter(inVal1);
//calculate the time-smoothed power of sig before renewing the filtered data
    float inVal1_3= pow(inVal1_2,2.0);
    sumpower -=pow(yData2[0],2.0);
    sumpower += inVal1_3;
    float inVal3 = sumpower/float(plotDataSize);

// add the new original input to the plot
    memmove( yData1, yData1+1, (plotDataSize-1) * sizeof(float) );
    yData1[plotDataSize-1] = inVal1;


//add the new filtered input to the plot
    memmove( yData2, yData2+1, (plotDataSize-1) * sizeof(float) );
    yData2[plotDataSize-1] = inVal1_2;
//add the new filtered and powered input to the plot
    memmove( yData3, yData3+1, (plotDataSize-1) * sizeof(float) );
    yData3[plotDataSize-1] = inVal3;


//save data
    fprintf(florigin,"%e\n",inVal1);
    fprintf(flhp1,"%e\n",inVal1_2);
    fprintf(flpower,"%e\n",inVal1_3);

//udp sending 1channel test to control game
    int nofch=1;
    float  fVar[nofch];//initialize to-be-sent dataset
    fVar[0]=inVal3;
	// transforming float into qbytearray
    int len_fVar = sizeof(fVar); // 4*4 = 16 bit
	//send and check
    //        bool cksd = sdersc.writeDatagram(msg, QHostAddress("192.168.43.30"), rscverprt);
    //    bool cksd = sdersc->writeDatagram((char*)fVar,len_fVar,QHostAddress("192.168.43.161"), rscverprt);
    bool cksd = sdersc->writeDatagram((char*)fVar,len_fVar,QHostAddress("192.168.1.165"), rscverprt);
    //bool cksd = sdersc.writeDatagram(msg, QHostAddress::LocalHost, 1112);
    if(cksd>0)
      qDebug()<<"successfully send";
    else
    {
    //see the fail reason with error()
      qDebug()<<"sending is failed";
      qDebug()<<sdersc->error();
    }
	++count;
}
//this function is used to refresh the window plot every~20ms
void Window::plotrefresh()
{

//plot
        curve1->setSamples(xData1, yData1, plotDataSize);
        plot1->replot();
        curve2->setSamples(xData3, yData3, plotDataSize);
        plot2->replot();
}


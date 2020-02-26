#include "window.h"
// #include "adcreader.h"

#include <cmath>  // for sine stuff



// standard I/O stuff
#include <stdio.h>
#include <assert.h>

// includes the 2nd order IIR filter

#include <iostream>
// Simulates a realtime system by sending a 12 bit integer ECG
// through a 50Hz fixed point IIR bandstop

// standard I/O stuff
#include <stdio.h>
#include <assert.h>



	// set up the initial plot data
	for( int index=0; index<plotDataSize; ++index )
	{
		xData[index] = index;
		yData[index] =  sin( M_PI * index/50 );
	}

    curve1 = new QwtPlotCurve;
    curve2 = new QwtPlotCurve;
    curve3 = new QwtPlotCurve;
    curve4 = new QwtPlotCurve;
    
    plot1 = new QwtPlot;
    plot2 = new QwtPlot;
    plot3 = new QwtPlot;
    plot4 = new QwtPlot;
	// make a plot curve from the data and attach it to the plot
    

    curve1->setSamples(xData, yData, plotDataSize);
    curve1->attach(plot1);
    curve2->setSamples(xData, yData, plotDataSize);
    curve2->attach(plot2);
    curve3->setSamples(xData, yData, plotDataSize);
    curve3->attach(plot3);
    curve4->setSamples(xData, yData, plotDataSize);
    curve4->attach(plot4);

    plot1->replot();
    plot1->show();
    plot2->replot();
    plot2->show();
    plot3->replot();
    plot3->show();
    plot4->replot();
    plot4->show();


    vLayout1 = new QVBoxLayout;
    vLayout1->addLayout(vLayout1);

    vLayout1->addWidget(plot1);
    vLayout1->addWidget(plot2);
    vLayout1->addWidget(plot3);
    vLayout1->addWidget(plot4);

	setLayout(vLayout1);
	// This is a demo for a thread which can be
	// used to read from the ADC asynchronously.
	// At the moment it doesn't do anything else than
	// running in an endless loop and which prints out "tick"
	// every second.
//	adcreader = new ADCreader();
//	adcreader->start();
}

Window::~Window() {
	// tells the thread to no longer run its endless loop
//	adcreader->quit();
	// wait until the run method has terminated
//	adcreader->wait();
//	delete adcreader;
}

void Window::timerEvent( QTimerEvent * )
{
	int inVal = yData;
	++count;

	// add the new input to the plot
	memmove( yData, yData+1, (plotDataSize-1) * sizeof(double) );
	yData[plotDataSize-1] = inVal;

    curve1->setSamples(xData, yData, plotDataSize);
    curve2->setSamples(xData, yData, plotDataSize);
    curve3->setSamples(xData, yData, plotDataSize);
    curve4->setSamples(xData, yData, plotDataSize);

    plot1->replot();
    plot2->replot();
    plot3->replot();
    plot4->replot();




}




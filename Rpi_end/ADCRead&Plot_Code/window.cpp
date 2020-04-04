
#include "window.h"
#include "adcreader.h"

#include <cmath>  // for sine stuff
#include <unistd.h> // usleep



Window::Window() : qgain(5), count(0)
{
	knob = new QwtKnob;
	// set up the gain knob
	knob->setValue(qgain);

	// use the Qt signals/slots framework to update the gain -
	// every time the knob is moved, the setGain function will be called
	connect( knob, SIGNAL(valueChanged(double)), SLOT(setGain(double)) );



	// set up the initial plot data
	for( int index=0; index<plotDataSize; ++index )
	{
		xData[index] = index;
		yData[index] = qgain * sin( M_PI * index/50 );
	}

	curve = new QwtPlotCurve;
	plot = new QwtPlot;
	// make a plot curve from the data and attach it to the plot
	curve->setSamples(xData, yData, plotDataSize);
	curve->attach(plot);

	plot->replot();
	plot->show();


	// set up the layout - knob above thermometer
	vLayout = new QVBoxLayout;
	vLayout->addWidget(knob);


	// plot to the left of knob and thermometer
	hLayout = new QHBoxLayout;
	hLayout->addLayout(vLayout);
	hLayout->addWidget(plot);

	setLayout(hLayout);


    ads.setGain(adsGain_t::GAIN_EIGHT);
    ads.begin();
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

    
    adc0 = ads.readADC_SingleEnded(0);
    //printBits(sizeof(adc0), &adc0);
    usleep(1);
    
    	double inVal = adc0;
	++count;

	// add the new input to the plot
	memmove( yData, yData+1, (plotDataSize-1) * sizeof(double) );
	yData[plotDataSize-1] = inVal;
	curve->setSamples(xData, yData, plotDataSize);
	plot->replot();


}


// this function can be used to change the gain of the A/D internal amplifier
void Window::setGain(double qgain)
{
	// for example purposes just change the amplitude of the generated input
	this->qgain = qgain;
}



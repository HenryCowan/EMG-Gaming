#include "window.h"
#include "adcreader.h"

#include <cmath>  // for sine stuff
#include <QUdpSocket>


#include <unistd.h>

// includes the 2nd order IIR filter

const quint16 sderprt = 1117;
const quint16 rscverprt = 1112;
 
Window::Window() : count(0)
{
	// set up the initial plot data
	for( int index=0; index<plotDataSize; ++index )
	{
		xData[index] = index;
		yData[index] =  sin( M_PI * index/50 );
		yData1[index] =  sin( M_PI * index/50 );
		yData2[index] =  sin( M_PI * index/50 );
		yData3[index] =  sin( M_PI * index/50 );
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
    //curve3->setSamples(xData, yData, plotDataSize);
    //curve3->attach(plot3);
    //curve4->setSamples(xData, yData, plotDataSize);
    //curve4->attach(plot4);

    plot1->replot();
    plot1->show();
    plot2->replot();
    plot2->show();
    //plot3->replot();
    //plot3->show();
    //plot4->replot();
    //plot4->show();


    vLayout1 = new QVBoxLayout;
    vLayout1->addLayout(vLayout1);

    vLayout1->addWidget(plot1);
    vLayout1->addWidget(plot2);
    //vLayout1->addWidget(plot3);
    //vLayout1->addWidget(plot4);

	setLayout(vLayout1);

    ads.setGain(adsGain_t::GAIN_EIGHT);
    ads.begin();
    
        //initialize UDP sender
    sdersc= new QUdpSocket;
    //bind local address and check
    sdersc->bind(QHostAddress("192.168.1.174"), sderprt);
    //if(sdersc.bind(QHostAddress("192.168.1.174"), sderprt)>0)
    ////if(sdersc->bind(QHostAddress::LocalHost, sderprt)>0);
        //qDebug()<<"sender sc bind sucess";
}

Window::~Window() {
	// tells the thread to no longer run its endless loop
//	adcreader->quit();
	// wait until the run method has terminated
//	adcreader->wait();
//	delete adcreader;
    delete sdersc;
}

void Window::timerEvent( QTimerEvent * )
{
     adc0 = ads.readADC_SingleEnded(0);
     adc1 = ads.readADC_SingleEnded(1);
     //adc2 = ads.readADC_SingleEnded(2);
     //adc3 = ads.readADC_SingleEnded(3);
     
    //printBits(sizeof(adc0), &adc0);
    usleep(100);
    
    	double inVal = adc0;
    	double inVal1 = adc1;
	double inVal2 = adc2;
    	//double inVal3 = adc3;
	
	++count;

	// add the new input to the plot
	memmove( yData, yData+1, (plotDataSize-1) * sizeof(double) );
	yData[plotDataSize-1] = inVal;
	curve1->setSamples(xData, yData, plotDataSize);
	plot1->replot();
	
	memmove( yData1, yData1+1, (plotDataSize-1) * sizeof(double) );
	yData1[plotDataSize-1] = inVal1;
	curve2->setSamples(xData, yData1, plotDataSize);
	plot2->replot();
	
	//udp sending 1channel test to control game
	
	QByteArray msg;
	msg.setNum(inVal);
	bool cktp;
	const float outval= msg.toFloat(&cktp);
	if (!cktp and outval != inVal2) qDebug() << "before sending data, data type Conversion failed";
	qDebug() << "--- Sending";
	qDebug() << "data: " << msg;
	//qDebug() << "sendingtest " << msg;
	qDebug() << "sendingtest " << outval;
	//send and check
	//        bool cksd = sdersc.writeDatagram(msg, QHostAddress("192.168.43.30"), rscverprt);
	bool cksd = sdersc->writeDatagram(msg, QHostAddress("192.168.1.165"), rscverprt);
	//bool cksd = sdersc.writeDatagram(msg, QHostAddress::AnyIPv4, 1112);
	//bool cksd = sdersc.writeDatagram(msg, QHostAddress::LocalHost, 1112);
	if(cksd>0)
	  qDebug()<<"successfully send";
	else
	{
	//see the fail reason with error()
	  qDebug()<<"sending is failed";
	  qDebug()<<sdersc->error();
	    
	}
	    //memmove( yData1, yData2+1, (plotDataSize-1) * sizeof(double) );
	//yData2[plotDataSize-1] = inVal2;
	//curve3->setSamples(xData, yData2, plotDataSize);
	//plot2->replot();
	

	//memmove( yData1, yData3+1, (plotDataSize-1) * sizeof(double) );
	//yData3[plotDataSize-1] = inVal3;
	//curve4->setSamples(xData, yData3, plotDataSize);
	//plot4->replot();
	



    curve1->setSamples(xData, yData, plotDataSize);
    curve2->setSamples(xData, yData1, plotDataSize);
    curve3->setSamples(xData, yData2, plotDataSize);
    curve4->setSamples(xData, yData3, plotDataSize);

    plot1->replot();
    plot2->replot();
    plot3->replot();
    plot4->replot();

}

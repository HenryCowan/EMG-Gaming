#ifndef WINDOW_H
#define WINDOW_H


#include <qwt/qwt_thermo.h>
#include <qwt/qwt_knob.h>
#include <qwt/qwt_plot.h>
#include <qwt/qwt_plot_curve.h>

#include <QBoxLayout>

#include "adcreader.h"
#include <QUdpSocket>





// class definition 'Window'
class Window : public QWidget
{
	// must include the Q_OBJECT macro for for the Qt signals/slots framework to work with this class
	Q_OBJECT

public:
	Window(); // default constructor - called when a Window is declared without arguments

	~Window();
    QUdpSocket *sdersc;
	void timerEvent( QTimerEvent * );


// internal variables for the window class
private:

	
	QwtPlot      *plot1;
	QwtPlot      *plot2;
	QwtPlot      *plot3;
	QwtPlot      *plot4;


	QwtPlotCurve *curve1;
	QwtPlotCurve *curve2;
	QwtPlotCurve *curve3;
	QwtPlotCurve *curve4;

	
	Adafruit_ADS1015 ads;
	uint16_t adc0;
	uint16_t adc1;
	uint16_t adc2;
	uint16_t adc3;
			
	// layout elements from Qt itself http://qt-project.org/doc/qt-4.8/classes.html
	QVBoxLayout  *vLayout1;  // vertical layout
    QVBoxLayout  *vLayout2;  // vertical layout
	QHBoxLayout  *hLayout;  // horizontal layout

	static const int plotDataSize = 100;

	// data arrays for the plot
	double xData[plotDataSize];
	double yData[plotDataSize];
	double yData1[plotDataSize];
	double yData2[plotDataSize];
	double yData3[plotDataSize];



	int count;

//	ADCreader *adcreader;
};

#endif // WINDOW_H

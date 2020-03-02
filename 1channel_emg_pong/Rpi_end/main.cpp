#include <window.h>

#include <QApplication>
#include <stdio.h>
#include <unistd.h>

#include "adcreader.h"

//Adafruit_ADS1015 ads


int main(int argc, char *argv[])

{
	QApplication app(argc, argv);

	// create the window
	Window window;
	window.showMaximized();

	// call the window.timerEvent function every 40 ms
	window.startTimer(1.7);

	// execute the application
	return app.exec();

  
}

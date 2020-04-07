#include <window.h>

#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	// create the window
	Window window;
	window.showMaximized();

    // call the window.timerEvent function every 5 ms
    window.startTimer(5);

	// execute the application
	return app.exec();
}

#include <QApplication>
#include "mainwindow.h"
#include <QScreen>

int main(int argc, char *argv[])
{
    //automatically adjust dpi of display
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);
	/*Detecting the screen size and adjust the display size in according
	**It's extremely important in Qt for android
	*/
    QScreen *iScreen = a.primaryScreen();
    QSize rScreenSize = iScreen->size();
    //pass screen size to mainwindow as argument
	MainWindow w(rScreenSize.rwidth(),rScreenSize.rheight());
    w.show();

    return a.exec();
}

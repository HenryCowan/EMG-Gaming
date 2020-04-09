#include <QApplication>
#include "mainwindow.h"
#include <QScreen>
/**
 * The <code>main</code> function is used to find and update
 * the mainwindow with the optimum screen and display size
 * for android applications using Qt
 */

int main(int argc, char *argv[])
{
    //*automatically adjust dpi of display*/
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);
	/*Detecting the screen size and adjust the display size in according
	**It's extremely important in Qt for android
	*/
    QScreen *iScreen = a.primaryScreen();
    QSize rScreenSize = iScreen->size();
    //*pass screen size to mainwindow as argument*/
	MainWindow w(rScreenSize.rwidth(),rScreenSize.rheight());
    w.show();

    return a.exec();
}

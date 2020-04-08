#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>
#include <QGraphicsScene>
#include <QMainWindow>
#include <QObject>
#include <QUdpSocket>
#include <QElapsedTimer>

class QGraphicsItem;
class QTimer;




namespace Ui {
    class MainWindow;
}
/************************************************************\
 * class: Mainwindow
 * feature: receive udp sig and move pong gui in according
 * function:
*		void refreshScore(int count);  renew score
*		void Position();               calculate position based on sig
*		void receive();                receive udp sig
 * Author: Zonghan Gan
 *  version        date              des
 *  v1.0.0    2020-4-8-21-03    Pong gui on udp emg sig

\************************************************************/
class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    explicit MainWindow(int scrnwidth, int scrnheight, QWidget *parent = 0);
    ~MainWindow();
    Ui::MainWindow *ui;
    int iScore;

//graphic item in gameplay
    QGraphicsScene * iScene;
    QGraphicsRectItem *iP2, *iP1;
    QGraphicsEllipseItem *iBall;
    QTimer *iTimer;
    QElapsedTimer timer_measure;

    QPointF iBallMotion;
    qreal iP2Motion;
    qreal iP1Motion;
    qreal CpuP1Motion();

    int rfshcount=0;
public slots:
    void refreshScore(int count);
    void Position();
    void receive();



signals:
    void goal(int player);

    void rfsh();


private:
    QUdpSocket *rsverSocket;
    int wdwidth;
    int wdheight;
    int totalHeight = 350;
    int totalWidth = 320;
};

#endif // MAINWINDOW_H

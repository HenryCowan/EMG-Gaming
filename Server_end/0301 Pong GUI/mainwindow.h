/**
 *
 * "A Collection of Useful C++ Classes for Rpi sample (+ads1115), UDP transmission and Server (Android) Pong Game"
 * By Zonghan Gan
 *
 * Official project location:
 * https://github.com/TheUltraSoundGuys/RTEP
 *
 * License: MIT License (http://www.opensource.org/licenses/mit-license.php)
 * Copyright (c) 2020 by Zonghan Gan
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 **/
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

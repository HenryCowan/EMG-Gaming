#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>


#include <QPen>
#include <QResizeEvent>
#include <QDebug>
#include <QTimer>
#include <QObject>

const quint16 rsPort = 1112;
//Function to initiate the window 
MainWindow::MainWindow(int scrnwidth, int scrnheight, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    iScore ( 0 ),
    iBallMotion ( -2, -2 ),
    iP2Motion( 0 ),
    iP1Motion( 0 )
{
    wdwidth=scrnwidth-10;
    wdheight=scrnheight-10;

    ui->setupUi(this);
    this->setFixedSize(wdwidth,wdheight);
    iScene = new QGraphicsScene(this);
    iP2 = new QGraphicsRectItem(0, 0, 80, 20);
    iP2->setBrush(QBrush(Qt::blue));
    iP1 = new QGraphicsRectItem(0, 0, 80, 20);
    iP1->setBrush(QBrush(Qt::green));
    iBall = new QGraphicsEllipseItem(0, 0, 30, 30);
    iBall->setBrush(QBrush(Qt::green));
//measure timer accuracy
    //    QElapsedTimer time_measure;
    //    timer_measure=time_measure;
    iScene->setSceneRect(0, 0, wdwidth * 0.95, wdheight * 0.8);
    iP1->setPos(wdwidth*0.45, wdheight*0.815);
    iP2->setPos(wdwidth*0.45, -wdheight*0.0375); //iScene->width() * 0.39, iScene->height() * 0.94); //blue
    iBall->setPos(iScene->width() * 0.50, iScene->height() * 0.50);
    iScene->addItem(iP2);
    iScene->addItem(iP1);
    iScene->addItem(iBall);
    ui->boardView->setScene(iScene);
    QObject::connect(this, SIGNAL(goal(int)),this, SLOT(refreshScore(int)));
//receive udp sig
    rsverSocket = new QUdpSocket;
//bind ip address and port for receiving

    //bool bdrsvsc = rsverSocket->bind(QHostAddress("172.30.141.244"), rsPort);
    //bool bdrsvsc = rsverSocket->bind(QHostAddress("192.168.1.163"), rsPort);
    //bool bdrsvsc = rsverSocket->bind(QHostAddress::LocalHost, rsPort);
    //bool bdrsvsc = rsverSocket->bind(QHostAddress("127.0.0.1"), rsPort);//local address
    bool bdrsvsc = rsverSocket->bind(QHostAddress("192.168.43.161"), rsPort);//ip in local hot spot
    //bool bdrsvsc = rsverSocket->bind(QHostAddress::LocalHost, rsPort);
    if(bdrsvsc>0)
      { qDebug()<<"bind success";
        qDebug() << "--- receiving--";
    }
    else
    {
        qDebug()<<"bind failed";
        qDebug()<<rsverSocket->error();
    }
    connect(rsverSocket, SIGNAL(readyRead()), this, SLOT(receive()));

    connect(this, SIGNAL(rfsh()), this, SLOT(Position()));
}
//Function to eliminate window
MainWindow::~MainWindow()
{
	delete ui;
	delete rsverSocket;
	delete iScene;
	delete iP1;
	delete iP2;
	delete iBall;
	delete iTimer;
}
//Funtion to calculate score
void MainWindow::refreshScore(int count)
{
    iScore += count;
    ui->lcdNumber->display(iScore);
}
//Function to refresh gui
void MainWindow::Position()
{
    //qDebug()<<timer_measure.elapsed();
//calculate next position
	iBall->setBrush(QBrush(Qt::magenta));
    qreal Xprime = iBall->pos().x() + iBallMotion.x();
    qreal Yprime = iBall->pos().y() + iBallMotion.y();

    qreal P2Xprime = iP2->pos().x() + iP2Motion;
    qreal P1Xprime = iP1->pos().x() + iP1Motion;
//Bouncing condition
    if ( ( Xprime < 0 ) || ( Xprime + iBall->boundingRect().right() > iScene->sceneRect().right() ) )
    {
        iBallMotion.rx() *= -1;
    }

    if ( ( Yprime < 0 ) || ( Yprime + iBall->boundingRect().bottom() > iScene->sceneRect().bottom() ) )
    {
        // 1 for hitting the bottom wall, -1 for hitting the top wall
        emit goal(Yprime / abs(Yprime));
        iBallMotion.ry() *= -1;
    }

    if ( ( P2Xprime < 0 ) || ( P2Xprime + iP2->boundingRect().right() > iScene->sceneRect().right() ) )
    {
        iP2Motion = 0;
    }

    if ( ( P1Xprime < 0 ) || ( P1Xprime + iP2->boundingRect().right() > iScene->sceneRect().right() ) )
    {
        iP1Motion = 0;
    }

    if ( ( iP2->collidesWithItem(iBall) ) && ( iBallMotion.y() < 0 ) )
    {
        iBallMotion.ry() *= -1;
    }

    if ( ( iP1->collidesWithItem(iBall) ) && ( iBallMotion.y() > 0 ) )
    {
        iBallMotion.ry() *= -1;
    }

    if ( qrand() % 10 == 0 )//randomly block paddle1(cpu controlled) to give player chance
    {
        iP1Motion = CpuP1Motion();
    }
    iBall->moveBy(iBallMotion.x(), iBallMotion.y());
    iP2->moveBy(iP2Motion, 0);
    iP1->moveBy(iP1Motion, 0);
}


//Function to control paddle 1 with cpu
qreal MainWindow::CpuP1Motion()
{
    qreal dir = 0;

    if ( iBall->pos().x() + iBallMotion.x() > iP1->sceneBoundingRect().right() )
    {
        // move right
        dir = 5.0;// /6.0;
    }
    else if ( iBall->pos().x() + iBallMotion.x() < iP1->sceneBoundingRect().left() )
    {
        // move left
        dir = -5.0 ;// /6.0;
    }

    return dir;

}


//Function to receive and process emg sig through udp
void MainWindow::receive()
{
//reading from udp
    while(rsverSocket->hasPendingDatagrams())
    {

		int nofch=2;//array size: no. of channel
        float  outval[nofch];//output arry
        rsverSocket->readDatagram((char*)outval, sizeof(outval));//read and convert udp char as float
        //calculate difference to move paddle2
		float delta=outval[0]-outval[1];
        qDebug()<<delta;
        if (delta>0.3)
        {

            iP2Motion = (iP2Motion == 0 ? -20 : 0);

        }
        else if(delta<-0.3) //if (outval<0)
        {

           iP2Motion  = (iP2Motion == 0 ? 20 : 0);

        }
    this->rfshcount++;

    }
/*refresh relies on count of frequency to get rid of timer in android
**Android is a non-instant sys not like linux, the polling time >5ms
**refresh every 5 samples. if f=1000hz, t0=5ms;if fs=860hz(ads1115), t0=8.5ms
*/
    if (this->rfshcount>5)
    {
        emit rfsh();
        this->rfshcount=0;
        qDebug()<<"rfsh";
    }
}

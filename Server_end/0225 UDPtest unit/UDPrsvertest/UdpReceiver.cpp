#include <QByteArray>
#include <iostream>
#include "UDPrsvertest.h"
#include <QUdpSocket>

const quint16 PORT = 1112;

Udprsvertest::Udprsvertest(QObject *p) :
    QObject(p)
{
    rsverSocket = new QUdpSocket;
    //bind local address and port for receiving
    //bool bdrsvsc = rsverSocket->bind(QHostAddress("172.30.141.244"), PORT);
    //bool bdrsvsc = rsverSocket->bind(QHostAddress("172.30.156.14"), PORT);

    bool bdrsvsc = rsverSocket->bind(QHostAddress::LocalHost, PORT);
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
}

Udprsvertest::~Udprsvertest()
{
    delete rsverSocket;
}

void Udprsvertest::receive()
{

    while(rsverSocket->hasPendingDatagrams())
    {

        float  outFval[4];
        rsverSocket->readDatagram((char*)outFval, sizeof(outFval));//send float array directly as char instead of using qbytearray
        qDebug() << "data: " << outFval[0]<<outFval[1]<<outFval[2]<<outFval[3];
    }
}

//inspired by https://blog.csdn.net/weixin_42216430/article/details/80780297


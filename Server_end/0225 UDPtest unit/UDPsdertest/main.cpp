#include <QByteArray>
#include <QCoreApplication>
#include <QHostAddress>
#include <QUdpSocket>


using namespace std;
const quint16 sderprt = 1117;

const quint16 rscverprt = 1112;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
//define the port of the socket
    QUdpSocket sdersc;
    //bind local address and check

    if(sdersc.bind(QHostAddress::LocalHost, sderprt)>0);
        qDebug()<<"sender sc bind sucess";
    float dt = 20.0;
    QByteArray msg;
    for(int i=0; i<10000; i++){
        // float[] transform to QByteArray
        float  fVar[4] = { 1.1, 2.3, 9.5, 0.2 };//initialize to-be-sent dataset

// transforming float into qbytearray
        int len_fVar = sizeof(fVar); // 4*4 = 16 bit


        qDebug() << "--- Sending";

        bool cksd = sdersc.writeDatagram((char*)fVar,len_fVar,QHostAddress("127.0.0.1"), rscverprt);
        qDebug()<<fVar[0]<<fVar[2];
        if(cksd>0)
            qDebug()<<"successfully send";
        else
        {
        //see the fail reason with error()
            qDebug()<<"sending is failed";
            qDebug()<<sdersc.error();

        }


        }
    return a.exec();
}


// inspired by https://blog.csdn.net/weixin_42216430/article/details/80780297

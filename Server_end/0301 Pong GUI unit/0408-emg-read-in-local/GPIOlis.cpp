#include "GPIOlis.h"
#include <QDebug>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <iostream>
#include <functional>
#include <QFile>

int gpipinterrupt=0;
std::mutex cmdmtx;
using namespace std;


int ReadLine(int datasize,float *data1,QString path)
{

    QFile file1(path);//load file path
    if (file1.open(QIODevice::ReadOnly | QIODevice::Text))//open file and check
    {

        int i=0;
        bool cktp1;
        //qDebug()<<"reading";
        while (!file1.atEnd()&(i<datasize))//check if file end
        {

            QByteArray line1 = file1.readLine();//read in 1 line
            data1[i]= line1.toFloat(&cktp1);//convert to float
            //qDebug()<<data1[i];

            i++;

        }
        file1.close();
    }

    return 1;
}

GPIOlis::GPIOlis(QObject *parent): QThread(parent)
{
this->count=0;


QString path1="/home/zonghan-gan/qt/txtrd/Alternating_4Channel_Part1.dat";
QString path4="/home/zonghan-gan/qt/txtrd/Alternating_4Channel_Part4.dat";
ReadLine(datasize,this->data1,path1);
ReadLine(datasize,this->data2,path4);

sdtmr = new QTimer(this);
sdtmr->setTimerType(Qt::PreciseTimer);
sdtmr->setInterval(1);
//condition of timer start
sdtmr->start();
QObject::connect(sdtmr, SIGNAL(timeout()), this, SLOT(sddata()));

}
void GPIOlis::sddata(void)
{
    emit readyread(data1[count]);

    this->count ++;
    if (this->count>=61855)
    {
        this->quit();
    }
    return;


}
GPIOlis::~GPIOlis() {
}

void GPIOlis::run() {

    while(flag)
    {
        

    }
    return;
}
void GPIOlis::quit()
{
//    ads1->endads();
//    delete ads1;
    delete sdtmr;
    QThread::quit();
}

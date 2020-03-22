#include "GPIOlis.h"
#include <QDebug>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <iostream>
#include <functional>


int gpipinterrupt=0;
std::mutex cmdmtx;
using namespace std;

void interrupt2(void)
{
    
    //qDebug()<<"interrupt";
    cmdmtx.lock();
    gpipinterrupt =1;
    cmdmtx.unlock();
    }


GPIOlis::GPIOlis(QObject *parent): QThread(parent)
{
count=0;
ads1=new ads1115(0x48);
//connect(this, &GPIOlis::ready, ads1, &ads1115::readsig);
//qDebug()<<"thread set up";
}
void GPIOlis::interrupt(void)
{
    //emit ready();
    count ++;
    qDebug()<<"gpio awake, conversion ready";
    gpipinterrupt=0;
    float voltage=ads1->readsig();
    emit readyread(voltage);
    //qDebug()<<"data read";
    return;
}
GPIOlis::~GPIOlis() {
}

void GPIOlis::run() {
    if (wiringPiSetup () < 0) {
          qDebug()<< "Unable to setup wiringPi";
          flag=0;
      }


    if ( wiringPiISR (1, INT_EDGE_RISING, &interrupt2) < 0 )
    {
        qDebug()<<"unable to set up listensing";
        flag=0;
    }
    while(flag)
    {   
        
        cmdmtx.lock();
        //qDebug()<<"test"<<gpipinterrupt;
        if(gpipinterrupt)
        {
            
            this->interrupt();
        }
        cmdmtx.unlock();    
        this->usleep(1000);
    }
    return;
}
void GPIOlis::quit()
{
    ads1->endads();
    delete ads1;
    QThread::quit();
}

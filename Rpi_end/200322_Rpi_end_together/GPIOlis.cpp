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
/* Function to be called back and change flag when interrupt
*===================================*/
void interrupt2(void)
{
    
    //qDebug()<<"interrupt";
    cmdmtx.lock();
    gpipinterrupt =1;
    cmdmtx.unlock();
    }
/* Function to initialise thread
*===================================*/

GPIOlis::GPIOlis(QObject *parent): QThread(parent)
{
count=0;
ads1=new ads1115(0x48);

}
/* Function to be executed when interrupted and flag (gpipinterrupt) is changed
*===================================*/
void GPIOlis::interrupt(void)
{
    count ++;
    qDebug()<<"gpio awake, conversion ready";
    gpipinterrupt=0;
    float voltage=ads1->readsig();
    emit readyread(voltage);
    return;
}
GPIOlis::~GPIOlis() {
}

void GPIOlis::run() {
    if (wiringPiSetup () < 0) {
          qDebug()<< "Unable to setup wiringPi";
          flag=0;
      }
	//call back when interrupt
	//even if the waitforinterrupt func abandoned by wiringpi
	//we can borrow the idea to return a flag and in according doing the executions
    if ( wiringPiISR (1, INT_EDGE_RISING, &interrupt2) < 0 )//call back when interrupt
    {
        qDebug()<<"unable to set up listensing";
        flag=0;
    }
    while(flag)
    {   
        
        cmdmtx.lock();

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

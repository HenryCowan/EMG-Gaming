#ifndef GPIOLIS_H
#define GPIOLIS_H
#include <QThread>
//#include "ads1115.h"
#include <QTimer>
extern int gpipinterrupt;
const int datasize=61855;
/************************************************************\
 * class: GPIOlis
 * feature: read in 1000hz emg data from text, send sig every 1ms using QpreciseTimer
 * function:
*		sddata();                      send data everytime timer is out

 * Author: Zonghan Gan
 *  version        date              des
 *  v1.0.0    2020-4-8-21-03    Pong gui on udp emg sig

\************************************************************/


class GPIOlis : public QThread {
    Q_OBJECT
    int flag=1;
public:
    GPIOlis(QObject *parent=0);
    ~GPIOlis();
    void interrupt(void);
    int count;
    void quit();
    float data1[datasize];
    float data2[datasize];
    QTimer *sdtmr;

//private:
//    ads1115* ads1;
protected:
    void run();
signals:
    void ready();
    void readyread(float ch1,float ch2);
private slots:
    void sddata();
};

#endif // GPIOLIS_H

#ifndef GPIOLIS_H
#define GPIOLIS_H
#include <QThread>
#include "ads1115.h"
/************************************************************\
 * class: GPIOlis
 * feature: lis to GPIO connected to Alert of ads1115, in continous mode, interrupt every time 
		*	ad conversion is ready
		*	then send the data and trigger datapros in signal-slot mechanism
 * function:
*		run();							listen to interrupt and call back interrupt. every time detect, sleep 1ms
*		interrupt();                    read in data and send readyread signal

 * Author: Zonghan Gan
 *  version        date              
 *  v1.0.0    2020-3-21-01-03    

\************************************************************/
extern int gpipinterrupt;
class GPIOlis : public QThread {
    Q_OBJECT
    int flag=1;
public:
    GPIOlis(QObject *parent=0);
    ~GPIOlis();
    void interrupt(void);
    int count;
    void quit();
private:
    ads1115* ads1;
protected:
    void run();
signals:
    void ready();
    void readyread(float voltage);
};

#endif // GPIOLIS_H

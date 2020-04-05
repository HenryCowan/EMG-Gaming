#ifndef GPIOLIS_H
#define GPIOLIS_H
#include <QThread>
#include "ads1115.h"
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

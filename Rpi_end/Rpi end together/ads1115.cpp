#include <wiringPi.h>
#include <wiringPiI2C.h>
#include "ads1115.h"
#include <QElapsedTimer>
#include <QDebug>
#include <QApplication>
/* convert config command into binary:
*===============================================*/
int load_config(int config)
{
    int hight = config / 256;
    int low = config % 256;
    config = low * 256 + hight;
    return config;
}
/* ADS1115 setup:
 *    set up ADS1115 with iic addr.
 *    pinbase is 100
*===============================================*/
ads1115::ads1115(uchar addr, QObject *parent)
    : QObject(parent)
{

    this->iicaddr=addr;
    this->fd = wiringPiI2CSetup(addr);


    if (fd <= 0) {

    qDebug()<<"I2C connect failed"<<addr;
  } else {

    qDebug()<<"I2C connect successful"<<addr;
  }

    int chan = 0;


//initializing configure register
    int config =      ADS1015_REG_CONFIG_OS_SINGLE  |
                   ADS1015_REG_CONFIG_MUX_SINGLE_0  |
                    ADS1015_REG_CONFIG_PGA_4_096V   |
                   ADS1015_REG_CONFIG_MODE_CONTIN   |// Continuous mode (doesn't work with more than one channel)
                     ADS1115_REG_CONFIG_DR_860SPS   | // 860 samples per second (max)
                    ADS1015_REG_CONFIG_CMODE_TRAD   | // Traditional comparator (default val)
                    ADS1015_REG_CONFIG_CPOL_ACTVHI  |//active high for comparator
                    ADS1015_REG_CONFIG_CLAT_NONLAT  | // Non-latching (default val)
                   ADS1015_REG_CONFIG_CQUE_1CONV    ; // Disable the comparator (default val)


          /*                    ADS1015_REG_CONFIG_CPOL_ACTVLOW |*/ // Alert/Rdy active low   (default val)



    // Sent the config data in the right order

    config=load_config(config);
    int rcr = 0;
    rcr=wiringPiI2CWriteReg16(fd, ADS1015_REG_POINTER_CONFIG, config);
    if(rcr!= 0)
        {
            qDebug() << "Failed to set up ads" ;
        }
    //conversion ready sig set
    int high_config = ADS1115_REG_THRES_MSB_1;
    high_config=load_config(high_config);
    rcr=wiringPiI2CWriteReg16(fd,ADS1015_REG_POINTER_HITHRESH, high_config);

    if(rcr!= 0)
        {
            qDebug() << "Failed to set up ads" ;
        }

    int low_config = ADS1115_REG_THRES_MSB_0;
    low_config=load_config(low_config);
    rcr=wiringPiI2CWriteReg16(fd,ADS1015_REG_POINTER_LOWTHRESH, low_config);
    if(rcr!= 0)
        {
            qDebug() << "Failed to set up ads" ;
        }

    // Wait for 1st conversion to complete

#if 1
    QElapsedTimer t;
    t.start();
    while(t.elapsed() < 5)
    {
        QApplication::processEvents();//if there is no window, use coreapplication instead of application
    }
#endif

}

/* ADS1115 analogRead function
*===================================*/


float ads1115::readsig() {
    qDebug()<<"data reading";
    int value=0;
    value=wiringPiI2CReadReg16(fd, ADS1015_REG_POINTER_CONVERT);
    // wiringPi doesn't include stdint so everything is an int (int32), this should account for this
    int hight = value / 256;
    int low = value % 256;
    value = low * 256 + hight;
    if(value > 32767)
    {
      value -= 65535;
    }
    float voltage = value * 0.125f / 1000.0f;
    qDebug()<<voltage;
    emit readyread(voltage);
    return voltage;

}

void ads1115::endads()
{
    int config = ADS1015_REG_CONFIG_MODE_ENDCON;

    config=load_config(config);
    int rcr = 0;
    rcr=wiringPiI2CWriteReg16(fd, ADS1015_REG_POINTER_CONFIG, config);
    if(rcr!= 0)
        {
            qDebug() << "Failed to end ads" ;
        }

}

// inspired by https://blog.csdn.net/weixin_45380951/article/details/103268996
//inspired by https://github.com/adafruit/Adafruit_Python_ADS1x15/blob/804728974fcefaafc8b5994be65d22e9c198a8d1/examples/continuous.py

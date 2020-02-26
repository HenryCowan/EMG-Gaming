//cited from：https://blog.csdn.net/WangShiRuManWoRuLi/article/details/103728915
#ifndef  _ADS115_H_
#define  _ADS115_H_
#include "sys.h"
#define	 SDA_A1     PBout(7)=1    //SDA OUT
#define	 SDA_A0     PBout(7)=0
#define	 SCL_A1	    PBout(6)=1    //SCL
#define	 SCL_A0	    PBout(6)=0
#define	 SDA_AI	    PBin(7)       //SDA IN
 
#define  WR_REG     0x90      
#define  RE_REG     0x91     
#define  WR_REG_H   0x92    
#define  RE_REG_H   0x93     
 
#define  ADDR_HIGH 	1     
#define  ADDR_LOW 	0     
#define  DATA_REG   0x00	
#define  CONF_REG   0x01    
#define  LOTH_REG   0x02	
#define  HITH_REG   0x03	
 
#define  ch0        0xc0      
#define  ch1        0xd0      
#define  ch2        0xe0    
#define  ch3        0xf0  
  
 
 
#define  HCMD1         0x64   //AIN0 +-4.096  01000100b
#define  LCMD1	       0xF0	 //860sps 
 
 
 
void ads1115_init(void);
void i2c_start(void);
void i2c_stop(void);
void i2c_wtite_byte(u8 DATA);
u8 i2c_read_byte(void);
void ads1115_config(u8 LCMD,u8 HCMD,u8 addr);
    
u16 adc_get(u8 addr);
u16 adc_value_get(u8 LCMD,u8 HCMD,u8 addr);
u16 lvbo(u8 LCMD,u8 HCMD,u8 addr);
u16 adc_value_sample(u8 ch);
#endif		


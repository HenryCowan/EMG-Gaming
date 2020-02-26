//cited from https://blog.csdn.net/WangShiRuManWoRuLi/article/details/103728915
#include "ads1115.h"
 
void ads1115_init(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);
  SDA_A1;
  SCL_A1;
  delay_ms(5);
}
 
void i2c_start(void)
{
  SDA_A1;
  delay_us(15);
  SCL_A1;
  delay_us(15);
  SDA_A0;
  delay_us(15); //MIN 160ns
  SCL_A0;
  delay_us(15);
}
 
void i2c_stop(void)
{
  SDA_A0;
  delay_us(15);
  SCL_A1;
  delay_us(15);
  SDA_A1;
  delay_us(15); //MIN 160ns
}
 
void i2c_write_byte(u8 DATA)
{
  u8 i;
  SCL_A0;
  for (i = 0; i < 8; i++)
  {
    if (DATA & 0x80)
    {
      SDA_A1;
    }
    else
    {
      SDA_A0;
    }
    SCL_A1;
    delay_us(15);
    SCL_A0;
    delay_us(15);
    DATA = DATA << 1;
  }
  SDA_A1;
  SCL_A1;
  delay_us(15);
  SCL_A0;
}
 
u8 i2c_read_byte(void)
{
  u8 TData = 0, i;
  for (i = 0; i < 8; i++)
  {
    SCL_A1;
    delay_us(15);
    TData = TData << 1;
    if (SDA_AI)
    {
      TData |= 0x01;
    }
    SCL_A0;
    delay_us(15);
  }
  SCL_A0;
  delay_us(15);
  SDA_A0;
  delay_us(15);
  SCL_A1;
  delay_us(15);
  SCL_A0;
  delay_us(15);
  SDA_A1;
  return TData;
}
 
void ads1115_config(u8 LCMD, u8 HCMD, u8 addr)
{
  u8 i = 0;
  u8 Initdata[4];
  if (addr == ADDR_HIGH)
  {
    Initdata[0] = WR_REG_H;
  }
  else if (addr == ADDR_LOW)
  {
    Initdata[0] = WR_REG;
  }
 
  Initdata[1] = CONF_REG;
  Initdata[2] = HCMD;
  Initdata[3] = LCMD;
  SCL_A1;
  i2c_start();
  for (i = 0; i < 4; i++)
  {
    i2c_write_byte(Initdata[i]);
    delay_us(30);
  }
  i2c_stop();
}
 
u16 adc_get(u8 addr)
{
  u16 Data[2] = {0, 0};
 
  SCL_A1;
  i2c_start();
  if (addr == ADDR_HIGH)
  {
    i2c_write_byte(WR_REG_H); // 0x92
  }
  else if (addr == ADDR_LOW)
  {
    i2c_write_byte(WR_REG); // 0x90
  }
  i2c_write_byte(DATA_REG);
  i2c_stop();
 
  i2c_start();
  if (addr == ADDR_HIGH)
  {
    i2c_write_byte(RE_REG_H); // 0x92
  }
  else if (addr == ADDR_LOW)
  {
    i2c_write_byte(RE_REG); // 0x90
  }
  Data[0] = i2c_read_byte();
  Data[1] = i2c_read_byte();
  i2c_stop();
 
  Data[0] = Data[0] << 8 | Data[1];
  return (Data[0]); //&0x7fff
}
 
u16 adc_value_get(u8 LCMD, u8 HCMD, u8 addr)
{
  float value = 0;
  ads1115_config(LCMD, HCMD, addr);
  value = adc_get(addr);
  return value;
}
 
u16 lvbo(u8 LCMD, u8 HCMD, u8 addr)
{
  int k;
  float U = 0, temp;
 
  for (k = 0; k < 500; k++)
  {
    U += adc_value_get(LCMD, HCMD, addr);
  }
  temp = U;
  U = 0;
  return (temp / 500);
}
 
u16 adc_value_sample(u8 ch)
{
  u8 LCMD, HCMD;
  u8 addr = 0;
  u16 AD_Value = 0;
 
  switch (ch)
  {
  case ch_sensor_v:
  {
    LCMD = 0xE3;
    HCMD = 0xC2;
    addr = ADDR_HIGH;
    AD_Value = lvbo(LCMD, HCMD, addr);
  }
  break;
 
  case ch_refer_v:
  {
    LCMD = 0xE3;
    HCMD = 0xE2;
    addr = ADDR_HIGH;
    AD_Value = lvbo(LCMD, HCMD, addr);
  }
  break;
  /////////////////////////////////////////////////////////////////////////////
  default:
    break;
  }
 
  AD_Value = 4096 * 2 * AD_Value / 65535;
  return AD_Value;
}

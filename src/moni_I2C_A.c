#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "em_gpio.h"
#include "moni_I2C_A.h"
//#include "delay.h"

//定义好引脚

//定义命令
#define  I2C_READ_A      0x01
#define  I2C_WRITE_A     0x00

#define  I2C_delay_T_A  10

//定义好引脚的高低动作

#define I2C_SDA_H  GPIO_PinOutSet(I2C_PORT, I2C_SDA)
#define I2C_SDA_L  GPIO_PinOutClear(I2C_PORT, I2C_SDA)

#define I2C_SCL_H  GPIO_PinOutSet(I2C_PORT, I2C_SCL)
#define I2C_SCL_L  GPIO_PinOutClear(I2C_PORT, I2C_SCL)


extern void Delay_Us(uint16_t time);


//#define SDA_enOUT_A   {IIC2PORT_A->CRL&=0x0FFFFFFF;IIC2PORT_A->CRL|=7<<(7*4);}  //pin_no * 4
#define SDA_enOUT_A   GPIO_PinModeSet(I2C_PORT, I2C_SDA, gpioModePushPull, 1)
//#define SDA_enIN_A    {IIC2PORT_A->CRL&=0x0FFFFFFF;IIC2PORT_A->CRL|=4<<(7*4);Delay_Us(10);}// pin_no * 4
#define SDA_enIN_A    GPIO_PinModeSet(I2C_PORT, I2C_SDA, gpioModeInput, 0)
//#define SDA_inD     {GPIO_ReadInputDataBit(GPIOC,SDA_LR)// GPIO_ReadInputData
#define SDA_inD_A     GPIO_PinInGet(I2C_PORT,I2C_SDA)
	


void i2c_gpio_init_A(void)
{
  //这里相应的处理器的GPIO的初始化。
	 /* Enable GPIO clock */
		  CMU_ClockEnable(cmuClock_GPIO, true);

		  /* Configure sda/scl as a push pull */
		  GPIO_PinModeSet(I2C_PORT, I2C_SDA, gpioModePushPull, 1);
		  GPIO_PinModeSet(I2C_PORT, I2C_SCL, gpioModePushPull, 1);

 }
/*
 void fun_SDA_enOUT(void)
 {
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = SDA_LR;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP ;   //推挽输出
  GPIO_Init(GPIOB, &GPIO_InitStructure);	 
 }
 
 void fun_SDA_enIN(void)
 {
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = SDA_LR;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//GPIO_Mode_Out_PP ;   //推挽输出
  GPIO_Init(GPIOB, &GPIO_InitStructure);	 
 }

*/
 
/*
void SDA_enOUT(void)
{
  //这里相应的处理器的GPIO的初始化。
	GPIO_InitTypeDef GPIO_InitStructure;
	
	GPIO_InitStructure.GPIO_Pin = SDA_LR;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING ;   //推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

 }
 
void SDA_enIN(void)
{
  //这里相应的处理器的GPIO的初始化。
	GPIO_InitTypeDef GPIO_InitStructure;
	
	GPIO_InitStructure.GPIO_Pin = SDA_LR;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP ;   //推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

 }
*/ 
//void I2C_Delay(void)
//{
	//unsigned short i,j;
	//for(i=0;i<=1000;i++)
	  //{for(j=0;j<=100;j++);}
//}
 
volatile void delayiic2_A(unsigned long ulDelay)
{
  //这里要控制好延时，因为处理器太快，容易超出I2C DEVICE 的接收速度。
}
/*********************************************************************************************************
** Function name:       I2C_Start
** Descriptions:        IO模拟I2C，产生起始条件
** input parameters:    NONE
** output parameters:   NONE
** Returned value:      NONE
*********************************************************************************************************/
void I2C_Start_A(void)
{
	 SDA_enOUT_A;//
	 I2C_SDA_H;
	 I2C_SCL_H;
     Delay_Us(I2C_delay_T_A);//I2C_Delay();
     I2C_SDA_L;
     Delay_Us(I2C_delay_T_A);
     I2C_SCL_L;
     Delay_Us(I2C_delay_T_A);
}
/*********************************************************************************************************
** Function name:       I2C_Stop
** Descriptions:        IO模拟I2C，产生停止条件
** input parameters:    NONE
** output parameters:   NONE
** Returned value:      NONE
*********************************************************************************************************/
void I2C_Stop_A(void)
{
     SDA_enOUT_A;//
     I2C_SCL_L;;
     I2C_SDA_L;
     Delay_Us(I2C_delay_T_A);
     I2C_SCL_H;
     Delay_Us(I2C_delay_T_A);
     I2C_SDA_H;
     Delay_Us(I2C_delay_T_A);
	
}
/*********************************************************************************************************
** Function name:       I2C_Ack
** Descriptions:        IO模拟I2C，产生ACK信号
** input parameters:    NONE
** output parameters:   NONE
** Returned value:      NONE
*********************************************************************************************************/
void I2C_Ack_A(void)
{ 
     SDA_enOUT_A;//
     I2C_SCL_L;
     Delay_Us(I2C_delay_T_A);
     I2C_SDA_L;
     Delay_Us(I2C_delay_T_A);
     I2C_SCL_H;
     Delay_Us(I2C_delay_T_A);
     I2C_SCL_L;
     Delay_Us(I2C_delay_T_A);
}

/*********************************************************************************************************
** Function name:       I2C_NoAck
** Descriptions:        IO模拟I2C，产生NOACK信号
** input parameters:    NONE
** output parameters:   NONE
** Returned value:      NONE
*********************************************************************************************************/
void I2C_NoAck_A(void)
{ 
     SDA_enOUT_A;//
     I2C_SCL_L;
     Delay_Us(I2C_delay_T_A);
     I2C_SDA_H;
     Delay_Us(I2C_delay_T_A);
     I2C_SCL_H;
     Delay_Us(I2C_delay_T_A);
     I2C_SCL_L;
     Delay_Us(I2C_delay_T_A);
}

/*
 unsigned char SDA_Read(void)
{
  //改 SDA 为输入配置
  //读取 SDA 线的电平
  //返回都到的值
	unsigned char xreturn;
	SDA_enIN;//SDA_enOUT;//
	SDA_inD
	return xreturn;
}
*/
/*********************************************************************************************************
** Function name:       I2C_WaitAck
** Descriptions:        IO模拟I2C，产生waitACK信号
** input parameters:    NONE
** output parameters:   NONE
** Returned value:      true:有ACK信号；false:无ACK信号
*********************************************************************************************************/
uint8_t I2C_WaitAck_A(void)
{
    SDA_enOUT_A;//
    I2C_SCL_L;
    Delay_Us(I2C_delay_T_A);
    I2C_SDA_H;
    Delay_Us(I2C_delay_T_A);
    I2C_SCL_H;
    Delay_Us(I2C_delay_T_A);
	  SDA_enIN_A;//
	  Delay_Us(60);
	  if(SDA_inD_A)
    {
		  I2C_SCL_L;
			return 0;
    }
	  I2C_SCL_L;
		return 1;
}

/*********************************************************************************************************
** Function name:       I2C_SendByte
** Descriptions:        模拟I2C 发送一个字节
** input parameters:    ucByte: 先发送MSB，再送LSB
** output parameters:   NONE
** Returned value:      NONE
*********************************************************************************************************/
void I2C_SendByte_A(unsigned char ucByte)
{
    unsigned char i=8;
		SDA_enOUT_A;//
    while(i--)
    {
    	I2C_SCL_L;
        Delay_Us(I2C_delay_T_A);
        if(ucByte&0x80)
        	{I2C_SDA_H;}
        else 
            {I2C_SDA_L;}
        ucByte<<=1;
        Delay_Us(I2C_delay_T_A);
        I2C_SCL_H;
        Delay_Us(I2C_delay_T_A);
    }
    I2C_SCL_L;
}

/*********************************************************************************************************
** Function name:       I2C_RecvByte
** Descriptions:        模拟I2C 接收一个字节
** input parameters:    NONE
** output parameters:   NONE
** Returned value:      接收到的数据，数据从高位到底位
*********************************************************************************************************/
unsigned char I2C_RecvByte_A(void)
{ 
    unsigned char i=8;
    unsigned char ucByte=0;

    //SDA_enOUT;//
    //SDA_H;
      I2C_SCL_L;
	  SDA_enIN_A;//
    while(i--)
    {
      ucByte <<= 1;
      I2C_SCL_L;
      Delay_Us(I2C_delay_T_A);
      I2C_SCL_H;
      Delay_Us(I2C_delay_T_A); 
      //SDA_enIN;//
	    if(SDA_inD_A)
       {
        ucByte|=0x01;
       }
    }
    I2C_SCL_L;
		return ucByte;
}


//ES9018 是单子节地址，因此以下两个函数即可；

void moni_IIC_Write_A(uint8_t chip,uint8_t addr,uint8_t value)
{
	unsigned int x;
	I2C_Start_A();
	I2C_SendByte_A(chip);
	x =0;
	while((!I2C_WaitAck_A()) && (x < myi2cTIMEOUT)){x++;}//这里，最好改成超时退出
	I2C_SendByte_A(addr);
	x =0;
	while((!I2C_WaitAck_A()) && (x<myi2cTIMEOUT)){x++;}//while(!I2C_WaitAck());//这里，最好改成超时退出。
	I2C_SendByte_A(value);
	//I2C_SendByte_A(value>>8);
	//x =0;
	//while((!I2C_WaitAck_A())&&(x<myi2cTIMEOUT)){x++;}//while(!I2C_WaitAck());//这里，最好改成超时退出。
	//I2C_SendByte_A(value&0x0ff);	
	x =0;
	while((!I2C_WaitAck_A())&&(x<myi2cTIMEOUT)){x++;}//while(!I2C_WaitAck());//这里，最好改成超时退出。
	I2C_Stop_A();

}


uint8_t moni_IIC_Read_A(uint8_t chip,uint8_t addr )
{
	unsigned int temp;//temp1,temp2;
	unsigned int x;
	I2C_Start_A();
	I2C_SendByte_A(chip);
	x =0;
	while((!I2C_WaitAck_A()) && (x<myi2cTIMEOUT)){x++;}//while(!I2C_WaitAck());//这里，最好改成超时退出。
	I2C_SendByte_A(addr);
	x =0;
	while((!I2C_WaitAck_A()) && (x<myi2cTIMEOUT)){x++;}//while(!I2C_WaitAck());//这里，最好改成超时退出。
	I2C_Start_A();
	I2C_SendByte_A(chip|0x01);
	x =0;
	while((!I2C_WaitAck_A()) && (x<myi2cTIMEOUT)){x++;}//while(!I2C_WaitAck());//这里，最好改成超时退出。
	temp=I2C_RecvByte_A();
	//temp1=I2C_RecvByte_A();
	//I2C_Ack_A();
	//x =0;
	//while((!I2C_WaitAck_A()) && (x<myi2cTIMEOUT)){x++;}//while(!I2C_WaitAck());//这里，最好改成超时退出。
	//temp2=I2C_RecvByte_A();
	//temp=temp1<<8|temp2;
	I2C_NoAck_A();
	I2C_Stop_A();
	return temp;
}


#define EEPROM_i2c_ADDR_i  0xA0
unsigned char tset_eeprom(void)
{
	unsigned char x;
	x = moni_IIC_Read_A(0xa0,1);
	//moni_IIC_Write_A(0xa0,1,0xab); 	Delay_Ms(EEPROM_WRITE_T);
	//x = moni_IIC_Read_A(0xa0,1);
	return x;
}

#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "em_gpio.h"
#include "moni_I2C_A.h"
//#include "delay.h"

//���������

//��������
#define  I2C_READ_A      0x01
#define  I2C_WRITE_A     0x00

#define  I2C_delay_T_A  10

//��������ŵĸߵͶ���

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
  //������Ӧ�Ĵ�������GPIO�ĳ�ʼ����
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
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP ;   //�������
  GPIO_Init(GPIOB, &GPIO_InitStructure);	 
 }
 
 void fun_SDA_enIN(void)
 {
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = SDA_LR;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//GPIO_Mode_Out_PP ;   //�������
  GPIO_Init(GPIOB, &GPIO_InitStructure);	 
 }

*/
 
/*
void SDA_enOUT(void)
{
  //������Ӧ�Ĵ�������GPIO�ĳ�ʼ����
	GPIO_InitTypeDef GPIO_InitStructure;
	
	GPIO_InitStructure.GPIO_Pin = SDA_LR;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING ;   //�������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

 }
 
void SDA_enIN(void)
{
  //������Ӧ�Ĵ�������GPIO�ĳ�ʼ����
	GPIO_InitTypeDef GPIO_InitStructure;
	
	GPIO_InitStructure.GPIO_Pin = SDA_LR;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP ;   //�������
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
  //����Ҫ���ƺ���ʱ����Ϊ������̫�죬���׳���I2C DEVICE �Ľ����ٶȡ�
}
/*********************************************************************************************************
** Function name:       I2C_Start
** Descriptions:        IOģ��I2C��������ʼ����
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
** Descriptions:        IOģ��I2C������ֹͣ����
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
** Descriptions:        IOģ��I2C������ACK�ź�
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
** Descriptions:        IOģ��I2C������NOACK�ź�
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
  //�� SDA Ϊ��������
  //��ȡ SDA �ߵĵ�ƽ
  //���ض�����ֵ
	unsigned char xreturn;
	SDA_enIN;//SDA_enOUT;//
	SDA_inD
	return xreturn;
}
*/
/*********************************************************************************************************
** Function name:       I2C_WaitAck
** Descriptions:        IOģ��I2C������waitACK�ź�
** input parameters:    NONE
** output parameters:   NONE
** Returned value:      true:��ACK�źţ�false:��ACK�ź�
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
** Descriptions:        ģ��I2C ����һ���ֽ�
** input parameters:    ucByte: �ȷ���MSB������LSB
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
** Descriptions:        ģ��I2C ����һ���ֽ�
** input parameters:    NONE
** output parameters:   NONE
** Returned value:      ���յ������ݣ����ݴӸ�λ����λ
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


//ES9018 �ǵ��ӽڵ�ַ��������������������ɣ�

void moni_IIC_Write_A(uint8_t chip,uint8_t addr,uint8_t value)
{
	unsigned int x;
	I2C_Start_A();
	I2C_SendByte_A(chip);
	x =0;
	while((!I2C_WaitAck_A()) && (x < myi2cTIMEOUT)){x++;}//�����øĳɳ�ʱ�˳�
	I2C_SendByte_A(addr);
	x =0;
	while((!I2C_WaitAck_A()) && (x<myi2cTIMEOUT)){x++;}//while(!I2C_WaitAck());//�����øĳɳ�ʱ�˳���
	I2C_SendByte_A(value);
	//I2C_SendByte_A(value>>8);
	//x =0;
	//while((!I2C_WaitAck_A())&&(x<myi2cTIMEOUT)){x++;}//while(!I2C_WaitAck());//�����øĳɳ�ʱ�˳���
	//I2C_SendByte_A(value&0x0ff);	
	x =0;
	while((!I2C_WaitAck_A())&&(x<myi2cTIMEOUT)){x++;}//while(!I2C_WaitAck());//�����øĳɳ�ʱ�˳���
	I2C_Stop_A();

}


uint8_t moni_IIC_Read_A(uint8_t chip,uint8_t addr )
{
	unsigned int temp;//temp1,temp2;
	unsigned int x;
	I2C_Start_A();
	I2C_SendByte_A(chip);
	x =0;
	while((!I2C_WaitAck_A()) && (x<myi2cTIMEOUT)){x++;}//while(!I2C_WaitAck());//�����øĳɳ�ʱ�˳���
	I2C_SendByte_A(addr);
	x =0;
	while((!I2C_WaitAck_A()) && (x<myi2cTIMEOUT)){x++;}//while(!I2C_WaitAck());//�����øĳɳ�ʱ�˳���
	I2C_Start_A();
	I2C_SendByte_A(chip|0x01);
	x =0;
	while((!I2C_WaitAck_A()) && (x<myi2cTIMEOUT)){x++;}//while(!I2C_WaitAck());//�����øĳɳ�ʱ�˳���
	temp=I2C_RecvByte_A();
	//temp1=I2C_RecvByte_A();
	//I2C_Ack_A();
	//x =0;
	//while((!I2C_WaitAck_A()) && (x<myi2cTIMEOUT)){x++;}//while(!I2C_WaitAck());//�����øĳɳ�ʱ�˳���
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

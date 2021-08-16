#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "em_gpio.h"
#include "hal-config.h"

#include "moni_I2C_A.h"
#include "em_usart.h"

extern void config_init_si5338(void);
extern void config_si5338_10M_98M(void);
extern void config_si5338_10M_90M(void);
extern void config_si5338_100M_98M(void);
extern void config_si5338_100M_90M(void);




//---------------AS313C CODE------------------------------------------------------
#define AS511
#define ON 1
#define OFF 0
#define cSi5356B_addr 0xe0
#define cSi5338_addr 0xe0
#define NUM_REGS_MAX 350

//-------------PLL_INIT----------------------------------------------


#define PLL_INTR 4
#define PLL_SEL  3
#define PLL_CTR_PORT  gpioPortA

#define nEN 0
#define nEN_PORT gpioPortA

#define PLL_INTR_H  GPIO_PinOutSet(PLL_CTR_PORT, PLL_INTR)
#define PLL_INTR_L  GPIO_PinOutClear(PLL_CTR_PORT, PLL_INTR)

#define BUFLEN  80
#define LOCK_MASK 0x11
#define LOS_MASK 0x04		//IN3
//#define LOS_MASK 0x04		//crystal
void pll_init(void){
	/* Enable GPIO clock */
	CMU_ClockEnable(cmuClock_GPIO, true);
	CMU_ClockEnable(cmuClock_USART0, true);

	/* Configure INTR/nOE as a push pull */
    //GPIO_PinModeSet(PLL_CTR_PORT, PLL_INTR, gpioModePushPull, 1);
    GPIO_PinModeSet(PLL_CTR_PORT, PLL_INTR, gpioModeInput, 0);

	GPIO_PinOutSet(PLL_CTR_PORT, PLL_INTR);
    GPIO_PinModeSet(nEN_PORT, nEN, gpioModeInput, 0);
    GPIO_PinModeSet(PLL_CTR_PORT, PLL_SEL, gpioModeInput, 0);
    GPIO_PinModeSet(gpioPortB, 2, gpioModePushPull, 1);
    GPIO_PinModeSet(gpioPortB, 1, gpioModePushPull, 1);
    // Configure PA5 as an output (TX)
    GPIO_PinModeSet(gpioPortD, 1, gpioModePushPull, 0);

    // Configure PA6 as an input (RX)
    GPIO_PinModeSet(gpioPortD, 0, gpioModeInput, 0);

}

//------------ACK_OUT_CTR---------------------------------------------

void initUsart0(void)
{
  // Default asynchronous initializer (115.2 Kbps, 8N1, no flow control)
  USART_InitAsync_TypeDef init = USART_INITASYNC_DEFAULT;

  // Route USART1 TX and RX to PA5 and PA6 pins, respectively
  GPIO->USARTROUTE[0].TXROUTE = (gpioPortD << _GPIO_USART_TXROUTE_PORT_SHIFT)
      | (1 << _GPIO_USART_TXROUTE_PIN_SHIFT);
  GPIO->USARTROUTE[0].RXROUTE = (gpioPortD << _GPIO_USART_RXROUTE_PORT_SHIFT)
      | (0 << _GPIO_USART_RXROUTE_PIN_SHIFT);

  // Enable RX and TX
  GPIO->USARTROUTE[0].ROUTEEN = GPIO_USART_ROUTEEN_RXPEN | GPIO_USART_ROUTEEN_TXPEN;

  // Configure and enable USART1
  USART_InitAsync(USART0, &init);
}


void sel_init(void){




}
//------------CLK_IN_CTR---------------------------------------------


void rs_init(void){


}
//------------ACK_OUT_LOCK--------------------------------------------
#define LOCK 0
#define LOCK_PORT gpioPortB

#define LOCK_H  GPIO_PinOutSet(LOCK_PORT, LOCK)
#define LOCK_L  GPIO_PinOutClear(LOCK_PORT, LOCK)

void lock_init(void){
	/* Enable GPIO clock */
	//CMU_ClockEnable(cmuClock_GPIO, true);

	/* Configure INTR/nOE as a push pull */
	GPIO_PinModeSet(LOCK_PORT, LOCK, gpioModePushPull, 1);
	GPIO_PinOutClear(LOCK_PORT, LOCK);

}

void dalay(void) {
	int i;
	for (i = 0; i <= 50; i++)
		;
}


void dalay_us(int times) {
	int i;
	for (i = 0; i <= times; i++)
		;
}

void delay(int times) {
	int i;
	for (i = 0; i <= times; i++)
		;
}

void Delay_Us(uint16_t time)
{
	uint16_t i,j;
	for(i=0;i<time;i++)
  		{for(j=0;j<9;j++)
			  {;}
			}
}



void Delay1ms()		//@76.8MHz
{
	unsigned char i, j;

	i = 75;
	j = 178;
	do
	{
		while (--j);
	} while (--i);
}
void dalay_ms(unsigned int ms)		//@76.8MHz
{
	unsigned int i, j,k;

	for(k=0;k<ms;k++)
	{
		for(i=0;i<140;i++)
		{
			for(j=0;j<10;j++)
				{GPIO_PinOutSet(gpioPortB,1);
				GPIO_PinOutClear(gpioPortB,1);
				}
		}
	}
}
void gpio_pwm_test(void){
	GPIO_PinOutSet(gpioPortB,1);
	GPIO_PinOutSet(gpioPortB,2);
	dalay_ms(2);
	GPIO_PinOutClear(gpioPortB,1);
	GPIO_PinOutClear(gpioPortB,2);
	dalay_ms(2);
	GPIO_PinOutSet(gpioPortB,1);
	GPIO_PinOutSet(gpioPortB,2);
	dalay_ms(2);
	GPIO_PinOutClear(gpioPortB,1);
	GPIO_PinOutClear(gpioPortB,2);
	dalay_ms(2);
	GPIO_PinOutSet(gpioPortB,1);
	GPIO_PinOutSet(gpioPortB,2);
	dalay_ms(2);
	GPIO_PinOutClear(gpioPortB,1);
	GPIO_PinOutClear(gpioPortB,2);
	dalay_ms(2);
	GPIO_PinOutSet(gpioPortB,1);
	GPIO_PinOutSet(gpioPortB,2);
	dalay_ms(2);
	GPIO_PinOutClear(gpioPortB,1);
	GPIO_PinOutClear(gpioPortB,2);
	dalay_ms(2);
}
unsigned char xset_val,xset_clk,xset_clk_old;
unsigned char lol,lol_old,los,los_old,reg_val;
unsigned char sel0_val,sel1_val,sel2_val,rs0_val,rs1_val;
unsigned char nENdata,oldnENdata;
unsigned char seldata,oldseldata;

int main(void)
{
  /* Chip errata */
  CHIP_Init();

  xset_val=20;
  xset_clk=20;xset_clk_old=0x3f;reg_val=0;
  lol=0;los=0;los_old=0x3f;
  sel0_val=0;sel1_val=0;sel2_val=0;
  rs0_val=0;rs1_val=0;
  nENdata = 1;
  oldnENdata = 1;
  seldata = 1;
  oldseldata =1;
  unsigned char reg=0x00;
  unsigned char reg1=0x00;

  //------GPIO INIT-----------
  pll_init();
  sel_init();
  rs_init();
  lock_init();
  //-----i2c init---------------
  //dalay_ms(10);
  i2c_gpio_init_A();
  initUsart0();
  //dalay_ms(200);
  gpio_pwm_test();
  //--------------------------------------


  //----------------------------------------
  moni_IIC_Write_A(cSi5338_addr,230,0x10);//Disable Outputs
 // dalay_ms(200);
 // reg = moni_IIC_Read_A(cSi5338_addr,241);//Pause LOL
  moni_IIC_Write_A(cSi5338_addr,241,0xe5);
 // dalay_ms(200);

 // config_init_si5338();
#ifdef AS511
  config_si5338_100M_98M();
#else
  config_si5338_10M_90M();
#endif

  dalay_ms(200);
  reg = moni_IIC_Read_A(cSi5338_addr,218);//Validate input clock status

  	while(reg != 0){
  		reg = moni_IIC_Read_A(cSi5338_addr,218) & LOS_MASK;
  		USART_Tx(USART0, 0xbb);USART_Tx(USART0, reg);USART_Tx(USART0, 0xbb);
  	}

  dalay_ms(200);
  reg = moni_IIC_Read_A(cSi5338_addr,49);//Configure PLL for locking
  moni_IIC_Write_A(cSi5338_addr,49,reg&0x7f);
  dalay_ms(200);
  //reg = moni_IIC_Read_A(cSi5338_addr,246);//Initiate Locking of PLL
  moni_IIC_Write_A(cSi5338_addr,246,0x02);
  dalay_ms(200);
  dalay_ms(200);
  moni_IIC_Write_A(cSi5338_addr,241,0x65);
  dalay_ms(200);

  reg = moni_IIC_Read_A(cSi5338_addr,218);//Validate input clock status

  while(reg != 0){
    		reg = moni_IIC_Read_A(cSi5338_addr,218) & LOCK_MASK;
    		 USART_Tx(USART0, 0xaa);USART_Tx(USART0, reg);USART_Tx(USART0, 0xaa);
    	}

  reg1 = moni_IIC_Read_A(cSi5338_addr,237);
  //moni_IIC_Write_A(cSi5338_addr,47,reg|0x03);
  reg = moni_IIC_Read_A(cSi5338_addr,236);
  moni_IIC_Write_A(cSi5338_addr,46,reg);
  reg = moni_IIC_Read_A(cSi5338_addr,235);
  moni_IIC_Write_A(cSi5338_addr,45,reg);
  reg = moni_IIC_Read_A(cSi5338_addr,47);
  moni_IIC_Write_A(cSi5338_addr,47,(reg&0xfc)|(reg1&0x03));



  reg = moni_IIC_Read_A(cSi5338_addr,49);//Set PLL to use FCAL values
  moni_IIC_Write_A(cSi5338_addr,49,reg|0x80);
  dalay_ms(200);
#ifdef AS511
  moni_IIC_Write_A(cSi5338_addr,230,0x00);//Enable Outputs
#else
  moni_IIC_Write_A(cSi5338_addr,230,0x1f);//Enable Outputs
#endif
  dalay_ms(200);
 while(1){
#ifdef AS511
	 reg =  GPIO_PinInGet(PLL_CTR_PORT, PLL_SEL);
	 seldata = reg&0x01;delay(50);
	 if(oldseldata != seldata)
	 {
		 oldseldata = seldata;
		 moni_IIC_Write_A(cSi5338_addr,230,0x10);//Disable Outputs
		 // dalay_ms(200);
		 // reg = moni_IIC_Read_A(cSi5338_addr,241);//Pause LOL
		  moni_IIC_Write_A(cSi5338_addr,241,0xe5);
		 // dalay_ms(200);

		 // config_init_si5338();
		if(seldata ==1)
			config_si5338_100M_98M();
		else
			config_si5338_100M_90M();

		  dalay_ms(200);
		  reg = moni_IIC_Read_A(cSi5338_addr,218);//Validate input clock status

		  	while(reg != 0){
		  		reg = moni_IIC_Read_A(cSi5338_addr,218) & LOS_MASK;
		  		USART_Tx(USART0, 0xbb);USART_Tx(USART0, reg);USART_Tx(USART0, 0xbb);
		  	}

		  dalay_ms(200);
		  reg = moni_IIC_Read_A(cSi5338_addr,49);//Configure PLL for locking
		  moni_IIC_Write_A(cSi5338_addr,49,reg&0x7f);
		  dalay_ms(200);
		  //reg = moni_IIC_Read_A(cSi5338_addr,246);//Initiate Locking of PLL
		  moni_IIC_Write_A(cSi5338_addr,246,0x02);
		  dalay_ms(200);
		  dalay_ms(200);
		  moni_IIC_Write_A(cSi5338_addr,241,0x65);
		  dalay_ms(200);

		  reg = moni_IIC_Read_A(cSi5338_addr,218);//Validate input clock status

		  while(reg != 0){
		    		reg = moni_IIC_Read_A(cSi5338_addr,218) & LOCK_MASK;
		    		 USART_Tx(USART0, 0xaa);USART_Tx(USART0, reg);USART_Tx(USART0, 0xaa);
		    	}

		  reg1 = moni_IIC_Read_A(cSi5338_addr,237);
		  //moni_IIC_Write_A(cSi5338_addr,47,reg|0x03);
		  reg = moni_IIC_Read_A(cSi5338_addr,236);
		  moni_IIC_Write_A(cSi5338_addr,46,reg);
		  reg = moni_IIC_Read_A(cSi5338_addr,235);
		  moni_IIC_Write_A(cSi5338_addr,45,reg);
		  reg = moni_IIC_Read_A(cSi5338_addr,47);
		  moni_IIC_Write_A(cSi5338_addr,47,(reg&0xfc)|(reg1&0x03));



		  reg = moni_IIC_Read_A(cSi5338_addr,49);//Set PLL to use FCAL values
		  moni_IIC_Write_A(cSi5338_addr,49,reg|0x80);
		  dalay_ms(200);

		  moni_IIC_Write_A(cSi5338_addr,230,0x00);//Enable Outputs

		  dalay_ms(200);
	 }
#else
	 reg =  GPIO_PinInGet(nEN_PORT, nEN);
	 nENdata = reg&0x01;delay(50);
	 if(oldnENdata != nENdata)
	 {
		 oldnENdata = nENdata;
		 if(nENdata == 0){
			 moni_IIC_Write_A(cSi5338_addr,230,0x00);//Enable Outputs
			 USART_Tx(USART0, 0xcc);USART_Tx(USART0, nENdata);USART_Tx(USART0, 0xcc);
		 }
		 else
		 {
			 moni_IIC_Write_A(cSi5338_addr,230,0x1f);//Enable Outputs
			 USART_Tx(USART0, 0xdd);USART_Tx(USART0, nENdata);USART_Tx(USART0, 0xdd);
		 }
	 }
#endif
	 dalay_ms(20);
		        reg_val = moni_IIC_Read_A(cSi5356B_addr,218);

		        dalay_ms(20);
		        los = reg_val&0x08;
		        if(los_old!=los)
		          {
		      	  los_old=los;
		      	  xset_clk_old=0x3f;
		          }
		        lol = reg_val&0x10;
		        if(lol == 0x10)
		        	{LOCK_L;}
		        else
		        	{LOCK_H;}

 };

}

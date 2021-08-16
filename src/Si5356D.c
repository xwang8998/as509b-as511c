



#include  "Si5338-10M-90M-Registers.h"
#include  "Si5338-10M-98M-Registers.h"
#include  "Si5338-100M-90M-Registers.h"
#include  "Si5338-100M-98M-Registers.h"


#include "em_usart.h"
#include "moni_I2C_A.h"


#define cSi5356B_addr 0xe0
#define cSi5338_addr 0xe0
extern void dalay(void);



//----------------------------------------------------------------------------

void config_init_si5338(void)
{
	unsigned int i;
	unsigned char xaddr;
	unsigned char xchar_val,xchar_mask;
	unsigned char curr_val,clear_curr_val,clear_new_val,combined;
	unsigned char xtemp1,xtemp2;
	curr_val=0;clear_curr_val=0;clear_new_val=0;combined=0;xtemp1=0;xtemp2=0;
	for(i=0;i<NUM_REGS_MAX;i++)//NUM_REGS_MAX
		{

	        xchar_mask= Reg_Store_10M_98M[i].Reg_Mask;
			if(xchar_mask!=0)
			{
			  xaddr = Reg_Store_10M_98M[i].Reg_Addr;
		      xchar_val = Reg_Store_10M_98M[i].Reg_Val;

			  if(xchar_mask==0xff)
			    {
				  dalay();
				  moni_IIC_Write_A(cSi5338_addr,xaddr,xchar_val);
				  dalay();
				  xtemp1=moni_IIC_Read_A(cSi5338_addr,xaddr);
				  dalay();
				  USART_Tx(USART0, xaddr);USART_Tx(USART0, xtemp1);
			    }
			  else
			   {
				  dalay();
				  curr_val=moni_IIC_Read_A(cSi5338_addr,xaddr);
				  clear_curr_val=curr_val&(~xchar_mask);
				  clear_new_val=xchar_val&xchar_mask;
				  combined=clear_curr_val|clear_new_val;
				  dalay();
				  moni_IIC_Write_A(cSi5338_addr,xaddr,combined);
				  dalay();
				  xtemp2=moni_IIC_Read_A(cSi5338_addr,xaddr);
				  dalay();
				  USART_Tx(USART0, xaddr);USART_Tx(USART0, xtemp2);
			   }
		  }
     }
}
//--------------------------------------------------------------------------

void config_si5338_10M_90M(void)
{
	unsigned int i;
	unsigned char xaddr;
	unsigned char xchar_val,xchar_mask;
	unsigned char curr_val,clear_curr_val,clear_new_val,combined;
	unsigned char xtemp1,xtemp2;
	curr_val=0;clear_curr_val=0;clear_new_val=0;combined=0;xtemp1=0;xtemp2=0;
	for(i=0;i<NUM_REGS_MAX;i++)//NUM_REGS_MAX
		{

	        xchar_mask= Reg_Store_10M_90M[i].Reg_Mask;
			if(xchar_mask!=0)
			{
			  xaddr = Reg_Store_10M_90M[i].Reg_Addr;
		      xchar_val = Reg_Store_10M_90M[i].Reg_Val;

			  if(xchar_mask==0xff)
			    {
				  dalay();
				  moni_IIC_Write_A(cSi5338_addr,xaddr,xchar_val);
				  dalay();
				  xtemp1=moni_IIC_Read_A(cSi5338_addr,xaddr);
				  dalay();
			    }
			  else
			   {
				  dalay();
				  curr_val=moni_IIC_Read_A(cSi5338_addr,xaddr);
				  clear_curr_val=curr_val&(~xchar_mask);
				  clear_new_val=xchar_val&xchar_mask;
				  combined=clear_curr_val|clear_new_val;
				  dalay();
				  moni_IIC_Write_A(cSi5338_addr,xaddr,combined);
				  dalay();
				  xtemp2=moni_IIC_Read_A(cSi5338_addr,xaddr);
				  dalay();

			   }
		  }
     }
}

//----------------------------------------------------------------------------

void config_si5338_10M_98M(void)
{
	unsigned int i;
	unsigned char xaddr;
	unsigned char xchar_val,xchar_mask;
	unsigned char curr_val,clear_curr_val,clear_new_val,combined;
	unsigned char xtemp1,xtemp2;
	curr_val=0;clear_curr_val=0;clear_new_val=0;combined=0;xtemp1=0;xtemp2=0;
	for(i=0;i<NUM_REGS_MAX;i++)//NUM_REGS_MAX
		{

	        xchar_mask= Reg_Store_10M_98M[i].Reg_Mask;
			if(xchar_mask!=0)
			{
			  xaddr = Reg_Store_10M_98M[i].Reg_Addr;
		      xchar_val = Reg_Store_10M_98M[i].Reg_Val;

			  if(xchar_mask==0xff)
			    {
				  dalay();
				  moni_IIC_Write_A(cSi5338_addr,xaddr,xchar_val);
				  dalay();
				  xtemp1=moni_IIC_Read_A(cSi5338_addr,xaddr);
				  dalay();
			    }
			  else
			   {
				  dalay();
				  curr_val=moni_IIC_Read_A(cSi5338_addr,xaddr);
				  clear_curr_val=curr_val&(~xchar_mask);
				  clear_new_val=xchar_val&xchar_mask;
				  combined=clear_curr_val|clear_new_val;
				  dalay();
				  moni_IIC_Write_A(cSi5338_addr,xaddr,combined);
				  dalay();
				  xtemp2=moni_IIC_Read_A(cSi5338_addr,xaddr);
				  dalay();
			   }
		  }
     }
}

//----------------------------------------------------------------------------

void config_si5338_100M_90M(void)
{
	unsigned int i;
	unsigned char xaddr;
	unsigned char xchar_val,xchar_mask;
	unsigned char curr_val,clear_curr_val,clear_new_val,combined;
	unsigned char xtemp1,xtemp2;
	curr_val=0;clear_curr_val=0;clear_new_val=0;combined=0;xtemp1=0;xtemp2=0;
	for(i=0;i<NUM_REGS_MAX;i++)//NUM_REGS_MAX
		{

	        xchar_mask= Reg_Store_100M_90M[i].Reg_Mask;
			if(xchar_mask!=0)
			{
			  xaddr = Reg_Store_100M_90M[i].Reg_Addr;
		      xchar_val = Reg_Store_100M_90M[i].Reg_Val;

			  if(xchar_mask==0xff)
			    {
				  dalay();
				  moni_IIC_Write_A(cSi5338_addr,xaddr,xchar_val);
				  dalay();
				  xtemp1=moni_IIC_Read_A(cSi5338_addr,xaddr);
				  dalay();
			    }
			  else
			   {
				  dalay();
				  curr_val=moni_IIC_Read_A(cSi5338_addr,xaddr);
				  clear_curr_val=curr_val&(~xchar_mask);
				  clear_new_val=xchar_val&xchar_mask;
				  combined=clear_curr_val|clear_new_val;
				  dalay();
				  moni_IIC_Write_A(cSi5338_addr,xaddr,combined);
				  dalay();
				  xtemp2=moni_IIC_Read_A(cSi5338_addr,xaddr);
				  dalay();
			   }
		  }
     }
}

//----------------------------------------------------------------------------

void config_si5338_100M_98M(void)
{
	unsigned int i;
	unsigned char xaddr;
	unsigned char xchar_val,xchar_mask;
	unsigned char curr_val,clear_curr_val,clear_new_val,combined;
	unsigned char xtemp1,xtemp2;
	curr_val=0;clear_curr_val=0;clear_new_val=0;combined=0;xtemp1=0;xtemp2=0;
	for(i=0;i<NUM_REGS_MAX;i++)//NUM_REGS_MAX
		{

	        xchar_mask= Reg_Store_100M_98M[i].Reg_Mask;
			if(xchar_mask!=0)
			{
			  xaddr = Reg_Store_100M_98M[i].Reg_Addr;
		      xchar_val = Reg_Store_100M_98M[i].Reg_Val;

			  if(xchar_mask==0xff)
			    {
				  dalay();
				  moni_IIC_Write_A(cSi5338_addr,xaddr,xchar_val);
				  dalay();
				  xtemp1=moni_IIC_Read_A(cSi5338_addr,xaddr);
				  dalay();
			    }
			  else
			   {
				  dalay();
				  curr_val=moni_IIC_Read_A(cSi5338_addr,xaddr);
				  clear_curr_val=curr_val&(~xchar_mask);
				  clear_new_val=xchar_val&xchar_mask;
				  combined=clear_curr_val|clear_new_val;
				  dalay();
				  moni_IIC_Write_A(cSi5338_addr,xaddr,combined);
				  dalay();
				  xtemp2=moni_IIC_Read_A(cSi5338_addr,xaddr);
				  dalay();
			   }
		  }
     }
}

//----------------------------------------------------------------------------















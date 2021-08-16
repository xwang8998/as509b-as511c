
#ifndef __ES_I2C_H
#define __ES_I2C_H	 


#define I2C_SDA 6
#define I2C_SCL 5
#define I2C_PORT  gpioPortA


#define read_i2c_slave        moni_IIC_Read_A
#define set_i2c_slave 	      moni_IIC_Write_A

#define myi2cTIMEOUT  8000//00


typedef struct _addr_data {
	unsigned char addr;
	unsigned char data;
}addr_data;


void i2c_gpio_init_A(void);

void moni_IIC_Write_A(unsigned char chip,unsigned char  addr,unsigned char value);
unsigned char moni_IIC_Read_A(unsigned char chip,unsigned char addr );

unsigned char tset_eeprom_A(void);

#endif

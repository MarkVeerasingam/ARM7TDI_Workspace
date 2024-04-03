
#include <bios\ADuC7126Bits.h>

#include <Drivers\LCDDriver.h>

#define LCD_CLR_RS() GP3CLR_bit.DATA = 0x80
#define LCD_SET_RS() GP3SET_bit.DATA = 0x80

#define LCD_CLR_RW() GP4CLR_bit.DATA = 0x1
#define LCD_SET_RW() GP4SET_bit.DATA = 0x1

#define LCD_CLR_E() GP4CLR_bit.DATA = 0x2
#define LCD_SET_E() GP4SET_bit.DATA = 0x2

#define LCD_SET_DIR_IN() GP1DAT_bit.DIR = 0x0
#define LCD_SET_DIR_OUT() GP1DAT_bit.DIR = 0xff

#define LCD_DATA_IN GP1DAT_bit.INPUT
#define LCD_DATA_OUT GP1DAT_bit.OUTPUT

inline void Delay(const unsigned int &uTime)
{
	for (int iCount=uTime; iCount!=0; iCount--);
}

unsigned char LCDReadRegister(void)
{
	LCD_CLR_RS();
	LCD_SET_RW();
	LCD_SET_DIR_IN();
	LCD_SET_E();
	Delay(10);
	unsigned char byData = LCD_DATA_IN;
	LCD_CLR_E();
	Delay(10);
	return byData;
}

unsigned char LCDReadData(void)
{
	while((LCDReadRegister()&0x80)!=0);
	LCD_SET_RS();
	LCD_SET_E();
	Delay(10);
	unsigned char byData = LCD_DATA_IN;
	LCD_CLR_E();
	Delay(10);
	return byData;
}

void LCDWriteData(const unsigned char byData)
{
	while((LCDReadRegister()&0x80)!=0);
	LCD_SET_RS();
	LCD_CLR_RW();
	LCD_SET_DIR_OUT();
	LCD_DATA_OUT = byData;
	LCD_SET_E();
	Delay(10);
	LCD_CLR_E();
	Delay(10);
}

void LCDWriteRegister(const unsigned char &byData)
{
	while((LCDReadRegister()&0x80)!=0);
	LCD_CLR_RW();
	LCD_SET_DIR_OUT();
	LCD_DATA_OUT = byData;
	LCD_SET_E();
	Delay(10);
	LCD_CLR_E();
	Delay(10);
}

static unsigned char byDisplayRegister = 0x08;

void InitialLCD(void)
{
	LCDWriteRegister(0x38);//function set: 8bit data, two line display, 5*8 dot
	LCDWriteRegister(0x38);//function set: 8bit data, two line display, 5*8 dot
	LCDWriteRegister(0x38);//function set: 8bit data, two line display, 5*8 dot
	LCDWriteRegister(0x38);//function set: 8bit data, two line display, 5*8 dot
	
	byDisplayRegister &= 0xfb;
	LCDWriteRegister(byDisplayRegister);//display off
	
	LCDWriteRegister(0x01);//display clear
	LCDWriteRegister(0x06);//entry mode set: increment, not shift
	
	byDisplayRegister |= 0x04;
	LCDWriteRegister(byDisplayRegister);//display on
}

void SetCursorOn(void)
{
	byDisplayRegister |= 0x02;
	LCDWriteRegister(byDisplayRegister);
}

void SetCursorOff(void)
{
	byDisplayRegister &= 0xfd;
	LCDWriteRegister(byDisplayRegister);
}

void SetBlinkOn(void)
{
	byDisplayRegister |= 0x01;
	LCDWriteRegister(byDisplayRegister);
}

void SetBlinkOff(void)
{
	byDisplayRegister &= 0xfe;
	LCDWriteRegister(byDisplayRegister);
}

void MoveCursor(const unsigned char x, const unsigned char y)
{
	while ((x>=16)||(y>=2));//assert
	LCDWriteRegister(0x80|(y<<6)|x);
}

void LCDClear(void)
{
	LCDPrintf(0, 0, "                ");
	LCDPrintf(0, 1, "                ");
}

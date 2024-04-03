#include <ADuC7126.H>
#include <bios\ADuC7126Bits.h>

#include <bios\Initial.h>
#include <bios\Interrupt.h>

#include <bios\UART.h>
#include <applications\Options.h>
#include <Options.h>

#define __USE_C99_MATH //for round
#include <cmath>

using namespace std;

void InitialClock(void)
{
	unsigned long ulTemp = T2VAL;
	
	T2LD = 30;//free running mode, only load once
	
	T2CON_bit.PRESCALER = 0x0;//clock/1
	T2CON_bit.FORMAT = 0x0;//binary
	T2CON_bit.PERIODIC_MODE = false;//free running
	T2CON_bit.COUNT_UP = false;//count down
	T2CON_bit.CLOCK = 0x2;//internal 32.768k oscillator
	T2CON_bit.ENABLE = true;
	
	T2CLRI = 0x0;//clear interrupt
	
	IRQCONN_bit.IRQ_NESTING = false;//uninstall VIC
	
	while ((T2VAL==ulTemp) || (T2VAL>20));//make sure timer2 running and have more than 600us time to wakeup, enough time for pll setup
	
	IRQEN_bit.TIMER2 = true;//enable timer2 interrupt
	
	PLLKEY1 = 0xaa;
	PLLCON = 0x01;//external crystal, pll mode
	PLLKEY2 = 0x55;
	
	POWKEY1 = 0x01;
	POWCON0 = 0x20;//Set Core into Nap, HCLK = 32768*1275 = 41.7792MHz
	POWKEY2 = 0xf4;
	
	POWKEY3 = 0x76;
	POWCON1 = 0x800;//power on PWM, PWMCLKDIV = 0, PWM UCLK = 32768*1275 = 41.7792MHz
	POWKEY4 = 0xb1;
}

void InitialPWM(void)
{
	PWM0COM0 = 0xffff;
	PWM0COM1 = round((PWM_FREQUENCY_COUNTS/2.f)-0.5);
	PWM0COM2 = 0xffff;
	PWM0LEN = PWM_FREQUENCY_COUNTS;
	
	PWMCON0_bit.SYNCHRONIC = false;
	PWMCON0_bit.PWM3_INVERT = true;
	PWMCON0_bit.PWM1_INVERT = true;
	PWMCON0_bit.TRIP = false;
	PWMCON0_bit.CLOCK_PRESCALE = 0x0;//UCLK/2
	PWMCON0_bit.H_BRIDGE_MODE = false;//standard mode
	PWMCON0_bit.OUTPUT_ENABLE = false;//disable output
}

void InitialUART(void)
{
	COM0CON0_bit.WORD_LENGTH = 0x3;//8bits data
	COM0CON0_bit.STOP = true;//two stop bits
	COM0CON0_bit.PARITY_ENABLE = false;
	COM0CON0_bit.STICK_PARITY = false;
	COM0CON0_bit.BREAK = false;
	COM0CON0_bit.DIVISOR_ACCESS = true;//access DIV register
	
	COM0CON1_bit.STOP = true;//two stop bits
	COM0CON1_bit.PARITY_ENABLE = false;
	COM0CON1_bit.LOOP_BACK = false;

	unsigned short wN;
	union
	{
		unsigned short wDL;
		unsigned char abyDL[2];
	};
	unsigned char byM;
	
	FindDivider(GetOptions().m_ulBaudRate, wDL, byM, wN);
	
	COM0DIV0 = abyDL[0];
	COM0DIV1 = abyDL[1];
	
	COM0DIV2_bit.M = byM;
	COM0DIV2_bit.N = wN;
	COM0DIV2_bit.FRACT_ENABLE = true;
	
	COM0FCR = 0;//non fifo mode
	
	COM0CON0_bit.DIVISOR_ACCESS = false;//access Tx and Rx register
	
	COM0IEN0_bit.RX_BUFFER_FULL = true;
	COM0IEN0_bit.TX_BUFFER_EMPTY = true;
	
	IRQEN_bit.UART0 = true;
}

void InitialTimer1(void)//use for capture transceiver event
{
	T1CON_bit.CAPTURE_ENABLE = true;
	T1CON_bit.EVENT_SELECT = (21-2);//PLA IRQ0
	T1CON_bit.CLOCK = 0x2;//UCLK = 32768*1275 = 41.7792MHz
	T1CON_bit.COUNT_UP = true;
	T1CON_bit.PERIODIC_MODE = false;
	T1CON_bit.FORMAT = 0x0;
	T1CON_bit.PRESCALE = 0x0;//clock = UCLK/1 = 32768*1275 = 41.7792MHz
	T1CON_bit.ENABLE = true;
}

void InitialTimer0(void)//system tick 1ms
{
	T0LD = 41778ul;//UCLK = 32768*1275 = 41.7792MHz, 1ms period
	
	T0CON_bit.PERIODIC_MODE = true;
	T0CON_bit.CLOCK = 0x1;//UCLK = 32768*1275 = 41.7792MHz
	T0CON_bit.PRESCALE = 0x0;//UCLK/1
	T0CON_bit.ENABLE = true;
	
	T0CLRI = 0x0;//clear interrupt, this must be running at timer0 enabled status
	
	T0CON_bit.ENABLE = false;
	
	IRQEN_bit.TIMER0 = true;
	
	T0CON_bit.ENABLE = true;
}

void InitialTimer2(void)//use for blanking timer
{
	T2LD = 0xffffffff;
	
	T2CON_bit.CLOCK = 0x3;//HCLK = 32768*1275 = 41.7792MHz
	T2CON_bit.COUNT_UP = false;
	T2CON_bit.PERIODIC_MODE = true;
	T2CON_bit.FORMAT = 0x0;//binary
	T2CON_bit.PRESCALER = 0x0;//HCLK/1
	
	T2CLRI = 0x0;//clear interrupt
	
	IRQEN_bit.TIMER2 = true;
}

void InitialADC(void)
{
	ADCCON_bit.EDGE_TRIGGER = true;
	ADCCON_bit.CLOCK = 0x5;//fadc/32
	ADCCON_bit.ACQUISITION_TIME = 0x3;//16 clocks
	ADCCON_bit.BUSY_ENABLE = false;
	ADCCON_bit.POWER = true;
	ADCCON_bit.CONVERT_MODE = 0x0;//single ended mode
	ADCCON_bit.CONVERT_TYPE = 0x3;//single software conversion
	
	TSCON = 0x1;//enable temperature sensor chop
	
	ADCCP = 0x10;//input is temperature sensor
	ADCCN = 0x11;//negative is AGND
	
	REFCON_bit.POWER_DOWN = false;
	REFCON_bit.REFERENCE_OUTPUT = true;
	
	IRQEN_bit.ADC = true;
}

void InitialPLA(void)
{
	PLACLK_bit.BLOCK1 = 0x6;//block1 use UCLK = 32768*1275 = 41.7792MHz
	
	PLAELM8_bit.MUX3 = true;//PWM0 interrupt use for counting PWM cycles
	PLAELM8_bit.LUT = 0x5;
	PLAELM8_bit.MUX4 = false;
	/*
	always_ff @ (posedge UCLK)
			PLAO[8] <= (!PLAI[8]);
	*/

	PLAELM9_bit.MUX3 = true;//PWM1 interrupt use for counting PWM cycles
	PLAELM9_bit.LUT = 0x5;
	PLAELM9_bit.MUX4 = false;
	/*
	always_ff @ (posedge UCLK)
			PLAO[9] <= (!PLAI[9]);
	*/

	PLAIRQ_bit.IRQ1_SOURCE = 9;
	PLAIRQ_bit.IRQ1_ENABLE = true;
	
	IRQCONE_bit.PLA_IRQ1_TRIGGER = 0x2;//trigger on rising edge
	/*
	always_ff @ (posedge PLAO[9])
		PLA_IRQ1 <= 1'b1;
	*/
	
	FIQEN_bit.PLA_IRQ1 = true;//enable PLA IRQ1 for PWM0 counting
	
	PLAELM10_bit.MUX3 = true;//echo interrupt
	PLAELM10_bit.LUT = 0x5;
	PLAELM10_bit.MUX4 = false;
	/*
	always_ff @ (posedge UCLK)
			PLAO[10] <= (!PLAI[10]);
	*/
	
	PLAIRQ_bit.IRQ0_SOURCE = 10;
	PLAIRQ_bit.IRQ0_ENABLE = true;
	
	IRQCONE_bit.PLA_IRQ0_TRIGGER = 0x2;//trigger on rising edge
	/*
	always_ff @ (posedge PLAO[10])
		PLA_IRQ0 <= 1'b1;
	*/
}

void InitialGPIO(void)
{
	GP0CON_bit.BIT1 = 0x0;//GPIO for buzzer
	GP0CON_bit.BIT4 = 0x0;//GPIO for key0
	GP0CON_bit.BIT5 = 0x0;//GPIO for key1
	GP0CON_bit.BIT7 = 0x02;//SIN0
	
	GP0PAR = 0x44444444;//all high drive strength with pull up
	
	GP0SET_bit.DATA = 0x2;//buzzer turn off
	GP0DAT_bit.DIR_BIT1 = true;//buzzer output
	
	GP0DAT_bit.DIR_BIT4 = false;//key0 input
	GP0DAT_bit.DIR_BIT5 = false;//key1 input
	GP0DAT_bit.OUTPUT_BIT4 = false;//key0 = 0, when output
	GP0DAT_bit.OUTPUT_BIT5 = false;//key1 = 0, when output
	
	IRQCONE_bit.GPIO_IRQ0_TRIGGER = 0x3;//falling edge trigger
	IRQCONE_bit.GPIO_IRQ1_TRIGGER = 0x3;//falling edge trigger
	
	IRQEN_bit.GPIO_IRQ0 = true;//key0
	IRQEN_bit.GPIO_IRQ1 = true;//key1
	
	GP1CON = 0x00000000;//all GPIO for LCD data bus
	GP1PAR = 0x44444444;//all high drive strength with pull up
	GP1DAT_bit.DIR = 0x0;//all input
	
	GP2CON_bit.BIT0 = 0x2;//SOUT0
	GP2CON_bit.BIT5 = 0x0;//GPIO for key2
	GP2CON_bit.BIT6 = 0x0;//GPIO for key3
	GP2CON_bit.BIT7 = 0x0;//GPIO for ADM3483 control
	
	GP2PAR = 0x44444444;//all high drive strength with pull up
	
	GP2DAT_bit.OUTPUT_BIT5 = false;//key2 = 0, when output
	GP2DAT_bit.OUTPUT_BIT6 = false;//key3 = 0, when output
	GP2DAT_bit.OUTPUT_BIT7 = false;//ADM3483 receive status
	
	GP2DAT_bit.DIR_BIT5 = true;//output for key2
	GP2DAT_bit.DIR_BIT6 = true;//output for key3
	GP2DAT_bit.DIR_BIT7 = true;//output for ADM3483 control
	
	GP3CON_bit.BIT0 = 0x1;//PWM0
	GP3CON_bit.BIT1 = 0x1;//PWM1
	GP3CON_bit.BIT2 = 0x3;//PLAI[10] for interrupt
	GP3CON_bit.BIT5 = 0x0;//GPIO for key4
	GP3CON_bit.BIT7 = 0x0;//GPIO for LCD_RS
	
	GP3PAR = 0x44444444;//all high drive strength with pull up
	
	GP3DAT_bit.OUTPUT_BIT5 = false;//key4 = 0, when output
	GP3DAT_bit.OUTPUT_BIT7 = false;//LCD_RS = 0
	
	GP3DAT_bit.DIR_BIT5 = true;//output for key4
	GP3DAT_bit.DIR_BIT7 = true;//output for LCD_RS
	
	GP4CON_bit.BIT0 = 0x0;//GPIO for LCD_RW
	GP4CON_bit.BIT1 = 0x0;//GPIO for LCD_E
	
	GP4PAR = 0x44444444;//all high drive strength with pull up
	
	GP4DAT_bit.OUTPUT_BIT0 = false;//LCD_RW = 0
	GP4DAT_bit.OUTPUT_BIT1 = false;//LCD_E = 0
	
	GP4DAT_bit.DIR_BIT0 = true;//output for LCD_RW
	GP4DAT_bit.DIR_BIT1 = true;//output for LCD_E
}

void InitialVIC(void)
{
	IRQBASE = (((unsigned long)apInterruptFunction)>>7);
	
	IRQCONN_bit.IRQ_NESTING = true;
	IRQCONN_bit.FIQ_NESTING = true;
}

void InitialCPU(void)
{
	InitialClock();
	InitialGPIO();
	InitialPWM();
	//InitialVIC(); if you want to use the VIC, you should be modify IRQ_Handler and FIQ_Handler in ADuC712x.s
	InitialPLA();
	InitialADC();
	InitialUART();
	InitialTimer1();
	InitialTimer2();
	InitialTimer0();
}



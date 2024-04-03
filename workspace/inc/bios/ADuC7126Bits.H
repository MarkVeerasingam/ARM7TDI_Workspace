#ifndef __ADUC7126BITS_H__
#define __ADUC7126BITS_H__
#define __attribute__(x) // may not be optimised enough

#pragma anon_unions

struct __gpiocon_bits
{
	unsigned long BIT0: 2;
	unsigned long : 2;
	unsigned long BIT1: 2;
	unsigned long : 2;
	unsigned long BIT2: 2;
	unsigned long : 2;
	unsigned long BIT3: 2;
	unsigned long : 2;
	unsigned long BIT4: 2;
	unsigned long : 2;
	unsigned long BIT5: 2;
	unsigned long : 2;
	unsigned long BIT6: 2;
	unsigned long : 2;
	unsigned long BIT7: 2;
	unsigned long : 2;
};

extern volatile __gpiocon_bits GP0CON_bit;
extern volatile __gpiocon_bits GP1CON_bit;
extern volatile __gpiocon_bits GP2CON_bit;
extern volatile __gpiocon_bits GP3CON_bit;
extern volatile __gpiocon_bits GP4CON_bit;

struct __gpiopar_bits
{
	unsigned long PULL_UP_DISABLE0: 1;
	unsigned long DRIVE_STRENGTH0: 2;
	unsigned long : 1;
	unsigned long PULL_UP_DISABLE1: 1;
	unsigned long DRIVE_STRENGTH1: 2;
	unsigned long : 1;
	unsigned long PULL_UP_DISABLE2: 1;
	unsigned long DRIVE_STRENGTH2: 2;
	unsigned long : 1;
	unsigned long PULL_UP_DISABLE3: 1;
	unsigned long DRIVE_STRENGTH3: 2;
	unsigned long : 1;
	unsigned long PULL_UP_DISABLE4: 1;
	unsigned long DRIVE_STRENGTH4: 2;
	unsigned long : 1;
	unsigned long PULL_UP_DISABLE5: 1;
	unsigned long DRIVE_STRENGTH5: 2;
	unsigned long : 1;
	unsigned long PULL_UP_DISABLE6: 1;
	unsigned long DRIVE_STRENGTH6: 2;
	unsigned long : 1;
	unsigned long PULL_UP_DISABLE7: 1;
	unsigned long DRIVE_STRENGTH7: 2;
	unsigned long : 1;
};

extern volatile __gpiopar_bits GP0PAR_bit;
extern volatile __gpiopar_bits GP1PAR_bit;
extern volatile __gpiopar_bits GP2PAR_bit;
extern volatile __gpiopar_bits GP3PAR_bit;
extern volatile __gpiopar_bits GP4PAR_bit;

struct __gpiodat_bits
{
	union
	{
		unsigned char INPUT;
		struct
		{
			unsigned long INPUT_BIT0: 1;
			unsigned long INPUT_BIT1: 1;
			unsigned long INPUT_BIT2: 1;
			unsigned long INPUT_BIT3: 1;
			unsigned long INPUT_BIT4: 1;
			unsigned long INPUT_BIT5: 1;
			unsigned long INPUT_BIT6: 1;
			unsigned long INPUT_BIT7: 1;
		}__attribute__((packed));
	}__attribute__((packed));
	union
	{
		unsigned char RST_VAL;
		struct
		{
			unsigned long RST_VAL_BIT0: 1;
			unsigned long RST_VAL_BIT1: 1;
			unsigned long RST_VAL_BIT2: 1;
			unsigned long RST_VAL_BIT3: 1;
			unsigned long RST_VAL_BIT4: 1;
			unsigned long RST_VAL_BIT5: 1;
			unsigned long RST_VAL_BIT6: 1;
			unsigned long RST_VAL_BIT7: 1;
		}__attribute__((packed));
	}__attribute__((packed));
	union
	{
		unsigned char OUTPUT;
		struct
		{
			unsigned long OUTPUT_BIT0: 1;
			unsigned long OUTPUT_BIT1: 1;
			unsigned long OUTPUT_BIT2: 1;
			unsigned long OUTPUT_BIT3: 1;
			unsigned long OUTPUT_BIT4: 1;
			unsigned long OUTPUT_BIT5: 1;
			unsigned long OUTPUT_BIT6: 1;
			unsigned long OUTPUT_BIT7: 1;
		}__attribute__((packed));
	}__attribute__((packed));
	union
	{
		unsigned char DIR;
		struct
		{
			unsigned long DIR_BIT0: 1;
			unsigned long DIR_BIT1: 1;
			unsigned long DIR_BIT2: 1;
			unsigned long DIR_BIT3: 1;
			unsigned long DIR_BIT4: 1;
			unsigned long DIR_BIT5: 1;
			unsigned long DIR_BIT6: 1;
			unsigned long DIR_BIT7: 1;
		}__attribute__((packed));
	}__attribute__((packed));
};

extern volatile __gpiodat_bits GP0DAT_bit;
extern volatile __gpiodat_bits GP1DAT_bit;
extern volatile __gpiodat_bits GP2DAT_bit;
extern volatile __gpiodat_bits GP3DAT_bit;
extern volatile __gpiodat_bits GP4DAT_bit;

struct __gpiosetclr_bits
{
	unsigned long : 16;
	unsigned long DATA: 8;
	unsigned long : 8;
};

extern volatile __gpiosetclr_bits GP0SET_bit;
extern volatile __gpiosetclr_bits GP1SET_bit;
extern volatile __gpiosetclr_bits GP2SET_bit;
extern volatile __gpiosetclr_bits GP3SET_bit;
extern volatile __gpiosetclr_bits GP4SET_bit;

extern volatile __gpiosetclr_bits GP0CLR_bit;
extern volatile __gpiosetclr_bits GP1CLR_bit;
extern volatile __gpiosetclr_bits GP2CLR_bit;
extern volatile __gpiosetclr_bits GP3CLR_bit;
extern volatile __gpiosetclr_bits GP4CLR_bit;

struct __irqfiq_bits
{
	unsigned long FIQ: 1;
	unsigned long SWI: 1;
	unsigned long TIMER0: 1;
	unsigned long TIMER1: 1;
	unsigned long TIMER2: 1;
	unsigned long TIMER3: 1;
	unsigned long FLASH0: 1;
	unsigned long FLASH1: 1;
	unsigned long ADC: 1;
	unsigned long UART0: 1;
	unsigned long UART1: 1;
	unsigned long PLL_LOCK: 1;
	unsigned long I2C0MASTER: 1;
	unsigned long I2C0SLAVE: 1;
	unsigned long I2C1MASTER: 1;
	unsigned long I2C1SLAVE: 1;
	unsigned long SPI: 1;
	unsigned long GPIO_IRQ0: 1;
	unsigned long COMPARATOR: 1;
	unsigned long POWER_SUPPLY: 1;
	unsigned long GPIO_IRQ1: 1;
	unsigned long PLA_IRQ0: 1;
	unsigned long GPIO_IRQ2: 1;
	unsigned long GPIO_IRQ3: 1;
	unsigned long PLA_IRQ1: 1;
	unsigned long PWM: 1;
	unsigned long : 6;
};

extern volatile __irqfiq_bits IRQSTA_bit;
extern volatile __irqfiq_bits IRQSIG_bit;
extern volatile __irqfiq_bits IRQEN_bit;
extern volatile __irqfiq_bits IRQCLR_bit;
extern volatile __irqfiq_bits FIQSTA_bit;
extern volatile __irqfiq_bits FIQSIG_bit;
extern volatile __irqfiq_bits FIQEN_bit;
extern volatile __irqfiq_bits FIQCLR_bit;

struct __irqconn_bits
{
	unsigned long IRQ_NESTING: 1;
	unsigned long FIQ_NESTING: 1;
	unsigned long : 30;
};

extern volatile __irqconn_bits IRQCONN_bit;

struct __irqcone_bits
{
	unsigned long GPIO_IRQ0_TRIGGER: 2;
	unsigned long GPIO_IRQ1_TRIGGER: 2;
	unsigned long PLA_IRQ0_TRIGGER: 2;
	unsigned long GPIO_IRQ2_TRIGGER: 2;
	unsigned long GPIO_IRQ3_TRIGGER: 2;
	unsigned long PLA_IRQ1_TRIGGER: 2;
	unsigned long : 20;
};

extern volatile __irqcone_bits IRQCONE_bit;

struct __irqclre_bits
{
	unsigned long : 17;
	unsigned long GPIO_IRQ0_CLEAR: 1;
	unsigned long : 2;
	unsigned long GPIO_IRQ1_CLEAR: 1;
	unsigned long PLA_IRQ0_CLEAR: 1;
	unsigned long GPIO_IRQ2_CLEAR: 1;
	unsigned long GPIO_IRQ3_CLEAR: 1;
	unsigned long PLA_IRQ1_CLEAR: 1;
	unsigned long : 7;
};

extern volatile __irqclre_bits IRQCLRE_bit;

struct __pwmcon0_bits
{
	unsigned long OUTPUT_ENABLE: 1;
	unsigned long H_BRIDGE_MODE: 1;
	unsigned long DIRECTION: 1;
	unsigned long LOAD_COMPARE: 1;
	unsigned long HIGH_SIDE_OFF: 1;
	unsigned long INVERT: 1;
	unsigned long CLOCK_PRESCALE: 3;
	unsigned long H_OUTPUT_ENABLE: 1;
	unsigned long TRIP: 1;
	unsigned long PWM1_INVERT: 1;
	unsigned long PWM3_INVERT: 1;
	unsigned long PWM5_INVERT: 1;
	unsigned long SYNCHRONIC: 1;
	unsigned long : 17;
};

extern volatile __pwmcon0_bits PWMCON0_bit;

struct __plaelm_bits
{
	unsigned long MUX4: 1;
	unsigned long LUT: 4;
	unsigned long MUX3: 1;
	unsigned long MUX2: 1;
	unsigned long MUX1: 2;
	unsigned long MUX0: 2;
	unsigned long : 21;
};

extern volatile __plaelm_bits PLAELM0_bit;
extern volatile __plaelm_bits PLAELM1_bit;
extern volatile __plaelm_bits PLAELM2_bit;
extern volatile __plaelm_bits PLAELM3_bit;
extern volatile __plaelm_bits PLAELM4_bit;
extern volatile __plaelm_bits PLAELM5_bit;
extern volatile __plaelm_bits PLAELM6_bit;
extern volatile __plaelm_bits PLAELM7_bit;
extern volatile __plaelm_bits PLAELM8_bit;
extern volatile __plaelm_bits PLAELM9_bit;
extern volatile __plaelm_bits PLAELM10_bit;
extern volatile __plaelm_bits PLAELM11_bit;
extern volatile __plaelm_bits PLAELM12_bit;
extern volatile __plaelm_bits PLAELM13_bit;
extern volatile __plaelm_bits PLAELM14_bit;
extern volatile __plaelm_bits PLAELM15_bit;

struct __placlk_bits
{
	unsigned long BLOCK0: 3;
	unsigned long : 1;
	unsigned long BLOCK1: 3;
	unsigned long : 25;
};

extern volatile __placlk_bits PLACLK_bit;

struct __plairq_bits
{
	unsigned long IRQ0_SOURCE: 4;
	unsigned long IRQ0_ENABLE: 1;
	unsigned long : 3;
	unsigned long IRQ1_SOURCE: 4;
	unsigned long IRQ1_ENABLE: 1;
	unsigned long : 19;
};

extern volatile __plairq_bits PLAIRQ_bit;

struct __adccon_bits
{
	unsigned long CONVERT_TYPE: 3;
	unsigned long CONVERT_MODE: 2;
	unsigned long POWER: 1;
	unsigned long BUSY_ENABLE: 1;
	unsigned long START: 1;
	unsigned long ACQUISITION_TIME: 2;
	unsigned long CLOCK: 3;
	unsigned long EDGE_TRIGGER: 1;
	unsigned long : 18;
};

extern volatile __adccon_bits ADCCON_bit;

struct __adcdat_bits
{
	unsigned long : 16;
	unsigned long DATA: 12;
	unsigned long SIGN: 4;
};

extern volatile __adcdat_bits ADCDAT_bit;

struct __tempref_bits
{
	unsigned long OFFSET: 8;
	unsigned long SIGN: 1;
	unsigned long : 23;
};

extern volatile __tempref_bits TEMPREF_bit;

struct __refcon_bits
{
	unsigned long REFERENCE_OUTPUT: 1;
	unsigned long POWER_DOWN: 1;
	unsigned long : 30;
};

extern volatile __refcon_bits REFCON_bit;

struct __comien0_bits
{
	unsigned long RX_BUFFER_FULL: 1;
	unsigned long TX_BUFFER_EMPTY: 1;
	unsigned long RX_STATUS: 1;
	unsigned long MODEM_STATUS: 1;
	unsigned long : 28;
};

extern volatile __comien0_bits COM0IEN0_bit;
extern volatile __comien0_bits COM1IEN0_bit;

struct __comiid0_bits
{
	unsigned long INT_DISABLED: 1;
	unsigned long INT_STATUS: 3;
	unsigned long : 2;
	unsigned long FIFO_MODE: 2;
	unsigned long : 24;
};

extern volatile __comiid0_bits COM0IID0_bit;
extern volatile __comiid0_bits COM1IID0_bit;

//because this is write only register
//struct __comfcr_bits
//{
//	unsigned long DISABLE_INT: 1;
//	unsigned long STATUS: 3;
//	unsigned long : 2;
//	unsigned long FIFO_MODE: 2;
//	unsigned long : 24;
//};

//extern volatile __comfcr_bits COM0FCR_bit;
//extern volatile __comfcr_bits COM1FCR_bit;

struct __comcon0_bits
{
	unsigned long WORD_LENGTH: 2;
	unsigned long STOP: 1;
	unsigned long PARITY_ENABLE: 1;
	unsigned long EVEN_PARITY: 1;
	unsigned long STICK_PARITY: 1;
	unsigned long BREAK: 1;
	unsigned long DIVISOR_ACCESS: 1;
	unsigned long : 24;
};

extern volatile __comcon0_bits COM0CON0_bit;
extern volatile __comcon0_bits COM1CON0_bit;

struct __comcon1_bits
{
	unsigned long DATA_TERMINAL_READY: 1;
	unsigned long REQUEST_TO_SEND: 1;
	unsigned long STOP: 1;
	unsigned long PARITY_ENABLE: 1;
	unsigned long LOOP_BACK: 1;
	unsigned long : 27;
};

extern volatile __comcon1_bits COM0CON1_bit;
extern volatile __comcon1_bits COM1CON1_bit;

struct __comsta0_bits
{
	unsigned long DATA_READY: 1;
	unsigned long OVERRUN_ERROR: 1;
	unsigned long PARITY_ERROR: 1;
	unsigned long FRAMING_ERROR: 1;
	unsigned long BREAK_ERROR: 1;
	unsigned long TX_EMPTY: 1;
	unsigned long TX_SHIFT_EMPTY: 1;
	unsigned long TX_HALF_EMPTY: 1;
	unsigned long TX_FULL: 1;
	unsigned long RX_TRIGGERED: 1;
	unsigned long RX_TIMEOUT: 1;
	unsigned long RX_ERROR: 1;
	unsigned long : 20;
};

extern volatile __comsta0_bits COM0STA0_bit;
extern volatile __comsta0_bits COM1STA0_bit;

struct __comsta1_bits
{
	unsigned long DELTA_CTS: 1;
	unsigned long DELTA_DSR: 1;
	unsigned long TRAILING_EDGE_RI: 1;
	unsigned long DELTA_DCD: 1;
	unsigned long CLEAR_TO_SEND: 1;
	unsigned long DATA_SET_READY: 1;
	unsigned long RING_INDICATOR: 1;
	unsigned long DATA_CARRIER_DETECT: 1;
	unsigned long : 24;
};

extern volatile __comsta1_bits COM0STA1_bit;
extern volatile __comsta1_bits COM1STA1_bit;

struct __comdiv2_bits
{
	unsigned long N: 11;
	unsigned long M: 2;
	unsigned long : 2;
	unsigned long FRACT_ENABLE: 1;
	unsigned long : 16;
};

extern volatile __comdiv2_bits COM0DIV2_bit;
extern volatile __comdiv2_bits COM1DIV2_bit;

struct __t0con_bits
{
	unsigned long : 2;
	unsigned long PRESCALE: 2;
	unsigned long CLOCK: 2;
	unsigned long PERIODIC_MODE: 1;
	unsigned long ENABLE: 1;
	unsigned long : 24;
};

extern volatile __t0con_bits T0CON_bit;

struct __t1con_bits
{
	unsigned long PRESCALE: 4;
	unsigned long FORMAT: 2;
	unsigned long PERIODIC_MODE: 1;
	unsigned long ENABLE: 1;
	unsigned long COUNT_UP: 1;
	unsigned long CLOCK: 3;
	unsigned long EVENT_SELECT: 5;
	unsigned long CAPTURE_ENABLE: 1;
	unsigned long : 14;
};

extern volatile __t1con_bits T1CON_bit;

struct __t2con_bits
{
	unsigned long PRESCALER: 4;
	unsigned long FORMAT: 2;
	unsigned long PERIODIC_MODE: 1;
	unsigned long ENABLE: 1;
	unsigned long COUNT_UP: 1;
	unsigned long CLOCK: 2;
	unsigned long : 21;
};

extern volatile __t2con_bits T2CON_bit;

struct __t3con_bits
{
	unsigned long : 1;
	unsigned long IRQ_MODE: 1;
	unsigned long PRESCALER: 2;
	unsigned long SECURE_CLEAR: 1;
	unsigned long WATCHDOG_MODE: 1;
	unsigned long PERIODIC_MODE: 1;
	unsigned long ENABLE: 1;
	unsigned long COUNT_UP: 1;
	unsigned long : 23;
};

extern volatile __t3con_bits T3CON_bit;

struct __feeadr_bits
{
	unsigned long ADDRESS: 16;
	unsigned long : 16;
};

extern volatile __feeadr_bits FEE0ADR_bit;
extern volatile __feeadr_bits FEE1ADR_bit;

struct __feemod_bits
{
	unsigned long WAIT_STATES: 2;
	unsigned long : 1;
	unsigned long WRITE_ENABLE: 1;
	unsigned long INTERRUPT_ENABLE: 1;
	unsigned long : 1;
	unsigned long KEY_PROTECTION: 1;
	unsigned long : 25;
};

extern volatile __feemod_bits FEE0MOD_bit;
extern volatile __feemod_bits FEE1MOD_bit;

struct __feesta_bits
{
	unsigned long COMMAND_COMPLETE: 1;
	unsigned long COMMAND_FAIL: 1;
	unsigned long FLASH_BUSY: 1;
	unsigned long INTERRUPT_STATUS: 1;
	unsigned long : 28;
};

extern volatile __feesta_bits FEE0STA_bit;
extern volatile __feesta_bits FEE1STA_bit;

#endif


#include <bios\ADuC7126Bits.h>
#include <Drivers\PWMDriver.h>
#include "ADuC7126.H"

volatile unsigned long g_ulTransmitCycles;

volatile unsigned long g_ulTransmitCapture, g_ulReceiveCapture;

void PWMTransmit(const unsigned long &ulCycles)
{
	g_ulTransmitCycles = ulCycles;
	
	if (ulCycles == 1)
	{
		T2LD = BLANKING_BASE_COUNT;
	}
	else
	{
		T2LD = BLANKING_BASE_COUNT*2;
	}
	
	IRQCLRE_bit.PLA_IRQ0_CLEAR = true;//clear edge trigger
	
	IRQEN_bit.PLA_IRQ0 = true;//enable echo interrupt
	
	PWMCON0_bit.OUTPUT_ENABLE = true;
}

unsigned long GetInterval(void)
{
	if (g_ulReceiveCapture > g_ulTransmitCapture)
	{
		return (g_ulReceiveCapture-g_ulTransmitCapture);
	}
	else
	{
		return (((0xffffffff-g_ulTransmitCapture)+g_ulReceiveCapture)+1);
	}
}

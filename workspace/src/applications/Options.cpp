#include <bios\ADuC7126Bits.h>
#include <ADuC7126.H>

#include <applications\Options.h>
#include <math.h>
#include <climits>

#pragma push
#pragma arm

union alignas(512) UOptions
{
	volatile unsigned short m_avwPadding[256]; // 512-byte per page
	SOptions m_Options;
} OptionsToSave;

const UOptions Options __attribute__((section("options_section"))) = {};

volatile signed int iWriteCount = INT_MAX;

void SetOptions(const SOptions &OptionsToSet)
{
	iWriteCount = INT_MAX;
	OptionsToSave.m_Options = OptionsToSet;
	iWriteCount = -1;
	
	if ((unsigned long)(Options.m_avwPadding) < 0x90000)//flash block 1 address 0x00080000~0x0008ffff
	{
		FEE1MOD_bit.WRITE_ENABLE = true;
		FEE1MOD_bit.INTERRUPT_ENABLE = true;
		IRQEN_bit.FLASH1 = true;
		if (!FEE1STA_bit.FLASH_BUSY)
		{
			FEE1CON = 0xf;//trigger interrupt
		}
	}
	else//flash block 0 range 0x00090000~0x0009f7ff
	{
		FEE0MOD_bit.WRITE_ENABLE = true;
		FEE0MOD_bit.INTERRUPT_ENABLE = true;
		IRQEN_bit.FLASH0 = true;
		if (!FEE0STA_bit.FLASH_BUSY)
		{
			FEE0CON = 0xf;//trigger interrupt
		}
	}
}

void WriteFlash0(void)
{
	if (iWriteCount == -1)
	{
		FEE0ADR_bit.ADDRESS = (unsigned long)(Options.m_avwPadding);
		
		FEE0CON = 0x5;//erase page
	}
	else
	{
		if (iWriteCount < ceil(sizeof(SOptions)/2.f))
		{
			FEE0ADR_bit.ADDRESS = (unsigned long)(&Options.m_avwPadding[iWriteCount]);
			FEE0DAT = OptionsToSave.m_avwPadding[iWriteCount];
			FEE0CON = 0x2;//single write
		}
		else
		{
			IRQCLR_bit.FLASH0 = true;
			FEE0MOD_bit.WRITE_ENABLE = false;
			FEE0MOD_bit.INTERRUPT_ENABLE = false;
		}
	}
	
	iWriteCount++;
}

void WriteFlash1(void)
{
	if (iWriteCount == -1)
	{
		FEE1ADR_bit.ADDRESS = (unsigned long)(Options.m_avwPadding);
		
		FEE1CON = 0x5;//erase page
	}
	else
	{
		if (iWriteCount < ceil(sizeof(SOptions)/2.f))
		{
			FEE1ADR_bit.ADDRESS = (unsigned long)(&Options.m_avwPadding[iWriteCount]);
			FEE1DAT = OptionsToSave.m_avwPadding[iWriteCount];
			FEE1CON = 0x2;//single write
		}
		else
		{
			IRQCLR_bit.FLASH1 = true;
			FEE1MOD_bit.WRITE_ENABLE = false;
			FEE1MOD_bit.INTERRUPT_ENABLE = false;
		}
	}
	
	iWriteCount++;
}

SOptions GetOptions(void)
{
	if (isnan(Options.m_Options.m_fTemperatureOffset) ||
			Options.m_Options.m_fTemperatureOffset < MINIMUM_TEMPERATURE_OFFSET ||
			Options.m_Options.m_fTemperatureOffset > MAXIMUM_TEMPERATURE_OFFSET ||
			Options.m_Options.m_ulBaudRate < MINIMUM_BAUD_RATE ||
			Options.m_Options.m_ulBaudRate > MAXIMUM_BAUD_RATE ||
			Options.m_Options.m_byAddress < MINIMUM_ADDRESS ||
			Options.m_Options.m_byAddress > MAXIMUM_ADDRESS)//uninitiated
	{
		UOptions DefaultOptions;
		DefaultOptions.m_Options.m_fTemperatureOffset = DEFAULT_TEMPERATURE_OFFSET;
		DefaultOptions.m_Options.m_ulBaudRate = DEFAULT_BAUD_RATE;
		DefaultOptions.m_Options.m_byAddress = DEFAULT_ADDRESS;
		
		SetOptions(DefaultOptions.m_Options);
		
		return DefaultOptions.m_Options;
	}
	
	return Options.m_Options;
}

#pragma pop

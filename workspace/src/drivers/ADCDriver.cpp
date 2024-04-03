
#include <ADuC7126.H>
#include <bios\ADuC7126Bits.h>
#include <Drivers\ADCDriver.h>

#pragma push
#pragma arm

static volatile unsigned char byAcquisitionCount = 0;

static volatile unsigned short wADCData[AVERAGE_NUMBER];

void AcquisitionData(void)
{
	if (byAcquisitionCount < (AVERAGE_NUMBER-1))
	{
		wADCData[byAcquisitionCount] = ADCDAT_bit.DATA;
		byAcquisitionCount++;
		StartADC();
	}
	else
	{
		wADCData[byAcquisitionCount] = ADCDAT_bit.DATA;
		byAcquisitionCount = 0;
	}
}

float GetTemperature(void)
{
	signed long lAverageData = 0;
	for (int iCount = 0; iCount < AVERAGE_NUMBER; iCount++)
	{
		lAverageData += wADCData[iCount];
	}
	
	lAverageData /= AVERAGE_NUMBER;
	
	lAverageData -= (TEMPREF_bit.SIGN ? (0x83b-TEMPREF_bit.OFFSET) : (0x83b+TEMPREF_bit.OFFSET));
	
	return lAverageData/7.40376f;
}

void StartADC(void)
{
	ADCCON_bit.CONVERT_TYPE = 0x3;//single software conversion
	ADCCON_bit.START = true;
	
	ADCCON_bit.START = false;
}
#pragma pop


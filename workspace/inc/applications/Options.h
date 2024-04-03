#ifndef __OPTIONS_H__
#define __OPTIONS_H__

struct SOptions
{
	volatile float m_fTemperatureOffset;
	volatile unsigned long m_ulBaudRate;
	volatile unsigned char m_byAddress;
};

extern SOptions GetOptions(void);

extern void SetOptions(const SOptions &OptionsToSet);

extern void WriteFlash0(void);
extern void WriteFlash1(void);

#define MAXIMUM_TEMPERATURE_OFFSET 50
#define MINIMUM_TEMPERATURE_OFFSET -50
#define DEFAULT_TEMPERATURE_OFFSET 0

#define MINIMUM_BAUD_RATE 75
#define MAXIMUM_BAUD_RATE 250000
#define DEFAULT_BAUD_RATE 115200

#define MAXIMUM_ADDRESS 255
#define MINIMUM_ADDRESS 1
#define DEFAULT_ADDRESS 1

#endif

#ifndef __PWMDRIVER_H__
#define __PWMDRIVER_H__

extern volatile unsigned long g_ulTransmitCycles;

extern volatile unsigned long g_ulTransmitCapture, g_ulReceiveCapture;

extern volatile bool g_bTransmitFlag;

extern void PWMTransmit(const unsigned long &ulCycles);
extern unsigned long GetInterval(void);

#define MAX_PWM_CYCLES 15

#define BLANKING_BASE_COUNT 83557ul//clock = 41.7792MHz, blanking 2ms

#endif

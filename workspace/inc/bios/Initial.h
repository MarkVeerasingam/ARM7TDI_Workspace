#ifndef __INITIAL_H__
#define __INITIAL_H__

extern void InitialCPU(void);
extern void InitialUART(void);//used in baud rate setting

#define PWM_FREQUENCY_COUNTS 521//((32768*1275)/2)/522 = 40.018390804597701149425287356322kHz, notice: Divider = (PWMxLEN+1)

#endif

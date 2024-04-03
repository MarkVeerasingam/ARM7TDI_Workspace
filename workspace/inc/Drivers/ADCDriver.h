#ifndef __ADCDRIVER_H__
#define __ADCDRIVER_H__

extern void AcquisitionData(void);
extern float GetTemperature(void);
extern void StartADC(void);

#define AVERAGE_NUMBER 8//AVERAGE_NUMBER must be even number for chopping


#endif

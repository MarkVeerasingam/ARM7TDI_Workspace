#ifndef __LCDDRIVER_H__
#define __LCDDRIVER_H__

#include <cstdio>
#include <bios\Retarget.h>

extern void InitialLCD(void);

extern void SetCursorOn(void);
extern void SetCursorOff(void);

extern void SetBlinkOn(void);
extern void SetBlinkOff(void);

extern void MoveCursor(const unsigned char x, const unsigned char y);

extern void LCDWriteData(const unsigned char byData);

#define LCDPrintf(x, y, ...) {g_ulStdOut = STDOUT_LCD; MoveCursor(x, y); printf(__VA_ARGS__);}

extern void LCDClear(void);

#ifdef __cplusplus
using namespace std;//needed by printf
#endif

#endif

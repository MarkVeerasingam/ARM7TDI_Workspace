#ifndef __UARTDRIVER_H__
#define __UARTDRIVER_H__

#include <bios\Retarget.h>
#include <cstdio>

extern void UARTTransmit(void);

extern void UARTTransmit(const unsigned char byData);

extern void UARTReceive(void);

extern void OnUARTReceiveFrame(void);

#define UARTPrintf(...) {g_ulStdOut = STDOUT_UART; printf(__VA_ARGS__);}

#endif

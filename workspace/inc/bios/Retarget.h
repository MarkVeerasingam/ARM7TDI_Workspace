#ifndef __RETARGET_H__
#define __RETARGET_H__

#ifdef __cplusplus
extern "C"
{
#endif

extern unsigned long g_ulStdOut;

#ifdef __cplusplus
}
#endif

#define STDOUT_LCD 0x0
#define STDOUT_UART 0x1

#endif

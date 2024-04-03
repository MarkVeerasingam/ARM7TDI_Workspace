#ifndef __BUZZERDRIVER_H__
#define __BUZZERDRIVER_H__

extern void beep(const unsigned long ulTime, ...);

#define Beep(...) beep(__VA_ARGS__, 0)

#endif

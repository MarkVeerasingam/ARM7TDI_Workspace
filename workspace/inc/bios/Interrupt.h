#ifndef __INTERRUPT_H__
#define __INTERRUPT_H__

//#define HARDWARE_VIC

#ifdef HARDWARE_VIC
	#define IRQ_FUNCTION __irq
#else
	#define IRQ_FUNCTION//use software VIC, the __irq already definited on IRQ_Handler and FIQ_Handler, __irq function could not be call by other function directly
#endif

extern void (*apInterruptFunction[])(void) IRQ_FUNCTION  __attribute__((aligned(128)));

#endif

#ifndef __MESSAGE_H__
#define __MESSAGE_H__

#define ON_KEYUP_DOWN 0x0200
#define ON_KEYUP_UP 0x0201

#define ON_KEYDOWN_DOWN 0x0202
#define ON_KEYDOWN_UP  0x0203

#define ON_KEYLEFT_DOWN 0x0204
#define ON_KEYLEFT_UP 0x0205

#define ON_KEYRIGHT_DOWN 0x0206
#define ON_KEYRIGHT_UP 0x0207

#define ON_KEYOK_DOWN 0x0208
#define ON_KEYOK_UP 0x0209

#define ON_KEYCANCEL_DOWN 0x020a
#define ON_KEYCANCEL_UP 0x020b

#define MSG_RTOS_TIMER 0x0300

#define MSG_ECHO 0x0400

#define MSG_UART_RX_FRAME 0x500

extern void PostMessage(const unsigned short &wMessage);
extern unsigned short GetMessage(void);
extern void DispatchMessage(const unsigned short &wMessage);

#endif

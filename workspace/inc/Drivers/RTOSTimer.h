// #ifndef __RTOSTIMER_H__
// #define __RTOSTIMER_H__

// struct STimer
// {
// 	volatile unsigned long m_ulTime;
// 	void (* volatile m_pF)(void);
// };

// #define MAX_TIMER_SIZE 64

// class CTimer
// {
// public:
// 	CTimer(void);
	
// 	void OnRTOSTimer(void);
	
// 	void AddTimer(const unsigned long &ulTime, void (*pF)(void));
	
// 	void RemoveTimer(void (*pF)(void));
	
// 	void UpdateUARTTimer(const unsigned int &uBytes, void (*pF)(void));
	
// private:
// 	STimer m_asTimer[MAX_TIMER_SIZE];
	
// 	void AddUARTTimer(const unsigned int &uBytes, void (*pF)(void));
// };

// extern CTimer Timer;

// #endif

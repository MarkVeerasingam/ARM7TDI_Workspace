#ifndef __HOMEDIALOG_H__
#define __HOMEDIALOG_H__

#include <applications\dialog\Wnd.h>
#include <deque>

#ifdef __cplusplus
using namespace std;//needed by printf
#endif

class CHomeDialog: public CWnd
{
public:
	virtual void OnCreate(void);
	
	virtual void OnKeyOkDown(void);

	virtual void OnEcho(void);
	
	virtual void OnKeyUpDown(void);
	virtual void OnKeyDownDown(void);
	virtual void OnKeyLeftDown(void);
	virtual void OnKeyRightDown(void);
	
	virtual void OnKeyCancelDown(void);
	
	static void OnTime(void);
	
	float GetDistance(void);
	
private:
	void OnDraw(void);
	
	bool m_bHaltDisplay;
	
	deque<unsigned char> m_KeyQueue;
	
	unsigned long m_ulInterval;
	
	unsigned long m_ulPWMCycles;
	
};

extern CHomeDialog HomeDialog;

#endif


#ifndef __BAUDRATEDIALOG_H__
#define __BAUDRATEDIALOG_H__

#include <applications\dialog\Wnd.h>

class CBaudRateDialog: public CWnd
{
public:
	CBaudRateDialog(void);
	
	virtual void OnCreate(void);
	
	virtual void OnKeyOkDown(void);
	
	virtual void OnKeyUpDown(void);
	virtual void OnKeyDownDown(void);
	virtual void OnKeyLeftDown(void);
	virtual void OnKeyRightDown(void);
	
	virtual void OnKeyCancelDown(void);
	
private:
	void OnDraw(void);
	
	unsigned long m_ulBaudRate;
	
	signed char m_cCursorDigital;
};

extern CBaudRateDialog BaudRateDialog;

#endif

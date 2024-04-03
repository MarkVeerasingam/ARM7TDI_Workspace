#ifndef __SETDIALOG_H__
#define __SETDIALOG_H__

#include <applications\dialog\Wnd.h>

enum ESetting
{
	CalibrateTemperatureSetting,
	BaudRateSetting,
	AddressSetting
};

class CSetDialog: public CWnd
{
public:
	CSetDialog(void);
	
	virtual void OnCreate(void);
	
	virtual void OnKeyOkDown(void);
	
	virtual void OnKeyUpDown(void);
	virtual void OnKeyDownDown(void);
	virtual void OnKeyLeftDown(void);
	virtual void OnKeyRightDown(void);
	
	virtual void OnKeyCancelDown(void);
	
private:
	void OnDraw(void);
	ESetting m_Setting;
};

extern CSetDialog SetDialog;

#endif

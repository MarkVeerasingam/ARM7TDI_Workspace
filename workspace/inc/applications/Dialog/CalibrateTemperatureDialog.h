#ifndef __CALIBRATETEMPERATUREDIALOG_H__
#define __CALIBRATETEMPERATUREDIALOG_H__

#include <applications\dialog\Wnd.h>

class CCalibrateTemperatureDialog: public CWnd
{
public:
	CCalibrateTemperatureDialog(void);
	
	virtual void OnCreate(void);
	
	virtual void OnKeyOkDown(void);
	
	virtual void OnKeyUpDown(void);
	virtual void OnKeyDownDown(void);
	virtual void OnKeyLeftDown(void);
	virtual void OnKeyRightDown(void);
	
	virtual void OnKeyCancelDown(void);
	
	static void OnTime(void);
	
private:
	void OnDraw(void);
	
	float m_fTemperature;
	signed char m_cCursorDigital;
};

extern CCalibrateTemperatureDialog CalibrateTemperatureDialog;



#endif

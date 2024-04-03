#ifndef __ADDRESSDIALOG_H__
#define __ADDRESSDIALOG_H__

#include <applications\dialog\Wnd.h>

class CAddressDialog: public CWnd
{
public:
	
	CAddressDialog(void);
	
	virtual void OnCreate(void);
	
	virtual void OnKeyOkDown(void);
	
	virtual void OnKeyUpDown(void);
	virtual void OnKeyDownDown(void);
	virtual void OnKeyLeftDown(void);
	virtual void OnKeyRightDown(void);
	
	virtual void OnKeyCancelDown(void);
	
private:
	void OnDraw(void);
	
	signed char m_cCursorDigital;
	signed short m_nAddress;
};

extern CAddressDialog AddressDialog;



#endif

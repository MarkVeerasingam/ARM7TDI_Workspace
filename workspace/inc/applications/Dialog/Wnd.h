#ifndef __CWIND_H__
#define __CWIND_H__

class CWnd
{
public:
	virtual void OnCreate(void);
	
	virtual void OnKeyUpDown(void);
	virtual void OnKeyUpUp(void);
	
	virtual void OnKeyDownDown(void);
	virtual void OnKeyDownUp(void);
	
	virtual void OnKeyLeftDown(void);
	virtual void OnKeyLeftUp(void);
	
	virtual void OnKeyRightDown(void);
	virtual void OnKeyRightUp(void);
	
	virtual void OnKeyOkDown(void);
	virtual void OnKeyOkUp(void);
	
	virtual void OnKeyCancelDown(void);
	virtual void OnKeyCancelUp(void);
	
	virtual void OnEcho(void);
	
protected:
	CWnd(void);
};

extern CWnd *g_pWnd;

#endif

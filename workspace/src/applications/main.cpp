#include <bios\Initial.h>
#include <Drivers\LCDDriver.h>

int main(void)
{
	
	InitialCPU();
	
	InitialLCD();
	
	//LCDPrintf(0, 0, "�ANALOG DEVICES�");
	//LCDPrintf(0, 1, "EVAL-CN0343-EB1Z");
	
	// for (unsigned int iCount=0; iCount<3000; iCount++)//wait welcome screen for about 3s
	// {
	// 	GetMessage();
	// }
	
	// g_pWnd = &HomeDialog;
	// g_pWnd->OnCreate();
	
	// while (true)
	// {
	// 	DispatchMessage(GetMessage());
	// }
}


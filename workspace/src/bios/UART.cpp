#include <bios\UART.h>

#define __USE_C99_MATH //for round
#include <cmath>

using namespace std;

void FindDivider(const float &fBaudRate, unsigned short &wDLResult, unsigned char &byMResult, unsigned short &wNResult)
{
	double dDivider = 2673868800./fBaudRate;//Divider = DL*(2048M+N), DL M N is integer
	unsigned long ulCeilDivider = ceil(dDivider), ulFloorDivider = floor(dDivider), ulDivider = round(dDivider);
	
	unsigned short wMinimumDL = ceil(ulDivider/8191.), wMaximumDL = floor(ulDivider/2048.), wDL;//NOTICE: M value MUST NOT be 4!!!
	
	while (true)//run to death
	{
		for (wDL = wMinimumDL; wDL <= wMaximumDL; wDL++)
		{
			if ((ulDivider % wDL) == 0)//(ulDivider/wDL) == integer
			{
				wNResult = (ulDivider/wDL)%2048;
				byMResult = floor((ulDivider/wDL)/2048.f);
				wDLResult = wDL;
				return;
			}
		}
		
		if (ulDivider == ulCeilDivider)//ping pong diffuse
		{
			ulCeilDivider++;
			ulDivider = ulFloorDivider;
		}
		else
		{
			ulFloorDivider--;
			ulDivider = ulCeilDivider;
		}
		
		wMinimumDL = ceil(ulDivider/8191.f);//NOTICE: M value MUST NOT be 4!!!
		wMaximumDL = floor(ulDivider/2048.f);
	}
}

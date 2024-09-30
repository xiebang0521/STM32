#include "stm32f10x.h"
#include "SysDelay.h"
#include "OLED.h"
#include "Timer.h"

uint16_t i;
int main()	
{

	OLED_Init();
	OLED_Clear();
	Timer_Init();
	OLED_ShowString(1,1,"CNT:");
	while(1)
	{
		OLED_ShowNum(1,6,Timer_GetCount(),5);

		for ( i= 0; i < 100; i++)
		{
			Timer_SetCompare1(i);
			Delaynms(10);
		}

		for ( i = 100; i > 0; i--)
		{
			/* code */
			Timer_SetCompare1(i);
			Delaynms(10);
		}	
	}
	
}

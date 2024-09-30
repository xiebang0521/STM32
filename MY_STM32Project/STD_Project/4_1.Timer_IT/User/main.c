#include "stm32f10x.h"
#include "SysDelay.h"
#include "OLED.h"
#include "Timer.h"

int32_t Num;
int main()	
{

	OLED_Init();
	OLED_Clear();
	Timer_Init();
	OLED_ShowString(1,1,"Time:");
	while(1)
	{

		OLED_ShowNum(1,7,Num,5);
		OLED_ShowNum(2,7,TIM_GetCounter(TIM2),5);
	}
	
}

#include "stm32f10x.h"
#include "SysDelay.h"
#include "OLED.h"
#include "Timer.h"
#include "TIM_Encode.h"

int16_t speed;
int main()	
{

	OLED_Init();
	OLED_Clear();
	Timer_Init();
	TIM_Encode_Init();
	
	OLED_ShowString(1,1,"site:");
	while(1)
	{
		//speed =TIM_Encode_GetNum();
		OLED_ShowSignedNum(1,7, speed,5);
		//Delaynms(1000);		
	}
	
}

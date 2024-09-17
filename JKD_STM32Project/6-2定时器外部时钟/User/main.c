#include "stm32f10x.h"
#include "OLED.h"
#include "Timer.h"

int16_t Num;

int main(void)
{
	OLED_Init();
	Timer_Config();
	OLED_ShowString(1,1,"Num:");
	OLED_ShowString(2,1,"Cnt:");
	while(1)
	{
		OLED_ShowSignedNum(1,5,Num,5);
		OLED_ShowSignedNum(2,5,TimCountGet(),5);
	}
}

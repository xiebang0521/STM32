#include "stm32f10x.h"
#include "OLED.h"
#include "Delay.h"
#include "PWM.h"
#include "Ic.h"

int main(void)
{
	OLED_Init();
	PWM_Config();
	IC_Init();

	PWM_SetCompare2(50);
	PWM_SetPrescaler(7200 - 1);

	OLED_ShowString(1,1,"Freq:00000Hz");
	OLED_ShowNum(2,1,TIM_GetPrescaler(TIM3),5);
	
	while(1)
	{
		OLED_ShowNum(1, 6, IC_GetFreq(), 5);
	}
}

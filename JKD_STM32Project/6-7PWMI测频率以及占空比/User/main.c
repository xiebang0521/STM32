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

	PWM_SetCompare2(10);
	PWM_SetPrescaler(720 - 1);

	OLED_ShowString(1,1,"Freq:00000Hz");
	OLED_ShowString(2,1,"Duty:000%");
	while(1)
	{
		OLED_ShowNum(1, 6, IC_GetFreq(), 5);
		OLED_ShowNum(2, 6, IC_GetDuty(), 3);
	}
}

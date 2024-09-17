#include "stm32f10x.h"
#include "OLED.h"
#include "PWM.h"
#include "Delay.h"
uint8_t i;
int main(void)
{
	OLED_Init();

	PWM_Config();
	while(1)
	{
		for(int i = 0; i <= 100; i++)
		{
			PWM_SetCompare1(i);
			Delay_ms(10);
		}

		for(int i = 0; i <= 100; i++)
		{
			PWM_SetCompare1(100 - i);
			Delay_ms(10);
		}
	}
}

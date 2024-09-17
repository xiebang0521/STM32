#include "stm32f10x.h"
#include "OLED.h"
#include "Motor.h"
#include "Delay.h"
#include "KEY.h"

int16_t speed;
int main(void)
{
	OLED_Init();
	Gpio_Key_Config();
	Motor_Config();

	OLED_ShowString(1,1,"Speed:");
	while(1)
	{
		switch (Key_Scan())
		{
		case 1:
			speed += 20;
			if(speed > 100)
			{
				speed = 0;
			}	
			break;
		case 2:
			speed -= 20;
			if(speed < -100)
			{
				speed = 0;
			}	
			break;
		
		default:
			break;
		}
		Delay_ms(20);
		if (speed > 0)
		{
			GPIO_SetBits(GPIOA, GPIO_Pin_5);
			GPIO_ResetBits(GPIOA, GPIO_Pin_4);
			Motor_SetSpeed(speed);
		}
		else
		{
			GPIO_SetBits(GPIOA, GPIO_Pin_4);
			GPIO_ResetBits(GPIOA, GPIO_Pin_5);
			Motor_SetSpeed(-speed);
		}
		OLED_ShowSignedNum(1,7,speed,3);
		
		
	}
}

#include "stm32f10x.h"
#include "SysDelay.h"
#include "OLED.h"
#include "Morto.h"
#include "Encode.h"


int32_t speed;
int main()	
{

	OLED_Init();
	OLED_Clear();
	Morto_Init();
	Encode_Init();
	OLED_ShowString(1,1,"Speed:");

	while(1)
	{	
		speed += Get_Encode_Count();
		if (speed >= 100)
		{
			speed = 99;
		}

		if (speed <= -100)
		{
			speed = -99;
		}
		
		if (speed > 0)
		{
			GPIO_SetBits(GPIOF, GPIO_Pin_8);
			GPIO_ResetBits(GPIOF, GPIO_Pin_9);
			Morto_SetSpeed(speed);
		}
		else{
			GPIO_ResetBits(GPIOF, GPIO_Pin_8);
			GPIO_SetBits(GPIOF, GPIO_Pin_9);
			Morto_SetSpeed(-speed);
		}
		OLED_ShowSignedNum(1,7,speed,3);
		
	}
	
}

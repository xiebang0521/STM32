#include "stm32f10x.h"
#include "SysDelay.h"
#include "OLED.h"
#include "Morto.h"
#include "Encode.h"
#include "IC.h"
#include "Timer.h"
int32_t autoreload;
int main()	
{

	OLED_Init();
	OLED_Clear();
	Morto_Init();
	Encode_Init();
	IC_Init();
	//OLED_ShowString(1,1,"value:");
	OLED_ShowString(2,1,"Freq:");
	OLED_ShowString(3,1,"Duty:00%");
	while(1)
	{	
//		autoreload += Get_Encode_Count();
//		if (autoreload >= 1000)
//		{
//			autoreload = 999;
//		}

//		if (autoreload <= 0)
//		{
//			autoreload = 0;
//		}
		
		//GPIO_SetBits(GPIOF, GPIO_Pin_8);
		//GPIO_ResetBits(GPIOF, GPIO_Pin_9);
		//PWM_SetFreq(autoreload);
		//PWM_SetPresacler(1000);
		//OLED_ShowSignedNum(1,7,autoreload,5);
		OLED_ShowNum(2,6,IC_Freq(),7);
		OLED_ShowNum(3,6,IC_GetDuty(),2);

		
	}
	
}

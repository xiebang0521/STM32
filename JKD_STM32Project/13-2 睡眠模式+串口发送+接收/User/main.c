#include "stm32f10x.h"
#include "OLED.h"
#include "Serial.h"
#include "Delay.h"
#include <stdio.h>


uint8_t RxData;
int main(void)
{
	OLED_Init();
	Serial_Init();
	OLED_ShowString(1,1,"RxData:");
                 
	while(1)
	{
		if (Serial_GetRxFlag() == 1)
		{
			RxData = Serial_GetRxData();
			Serial_SendByte(RxData);
			OLED_ShowHexNum(1,8,RxData,2);
		}

		OLED_ShowString(2, 1, "Running");
		Delay_ms(100);
		OLED_ShowString(2, 1, "       ");
		Delay_ms(100);

		//SCB->SCR = 0x10; SEVONPEND = 1 SLEEPDEEP = 0 , SLEEPONEXIT = 0
		__WFI();
		//
	}
}

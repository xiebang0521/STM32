#include "stm32f10x.h"
#include "OLED.h"
#include "Serial.h"
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
			
	}
}

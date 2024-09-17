#include "stm32f10x.h"
#include "OLED.h"
#include "Serial.h"
#include <stdio.h>


uint8_t RxData;

int main(void)
{
	OLED_Init();
	Serial_Init();

	OLED_ShowString(1,1,"TxPacket");
	OLED_ShowString(3,1,"RxPacket");
                 
	while(1)
	{
		if(Serial_GetRxFlag() == 1)
		{
			OLED_ShowString(4,1,Serial_RxPacket);
		}
	}
}

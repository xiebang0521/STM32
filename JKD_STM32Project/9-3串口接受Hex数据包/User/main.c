#include "stm32f10x.h"
#include "OLED.h"
#include "Serial.h"
#include "KEY.h"
#include <stdio.h>


uint8_t RxData;
extern uint8_t Serial_TxPacket[4];
extern uint8_t Serial_RxPacket[4];

int main(void)
{
	OLED_Init();
	Serial_Init();
	Gpio_Key_Config();

	Serial_TxPacket[0] = 0x01;
	Serial_TxPacket[1] = 0x02;
	Serial_TxPacket[2] = 0x03;
	Serial_TxPacket[3] = 0x04;
	OLED_ShowString(1, 1, "TxPacket:");
	OLED_ShowString(3, 1, "RxPacket:");
	while(1)
	{
		if (Key_Scan() == 1)
		{
			OLED_ShowHexNum(2, 1, Serial_TxPacket[0], 2); 
			OLED_ShowHexNum(2, 4, Serial_TxPacket[1], 2); 
			OLED_ShowHexNum(2, 7, Serial_TxPacket[2], 2); 
			OLED_ShowHexNum(2, 10, Serial_TxPacket[3], 2);
			Serial_SendPacket();
			Serial_TxPacket[0]++;
			Serial_TxPacket[1]++;
			Serial_TxPacket[2]++;
			Serial_TxPacket[3]++;
	
		}
		
		if(Serial_GetRxFlag() == 1)
		{
			OLED_ShowHexNum(4, 1, Serial_RxPacket[0], 2); 
			OLED_ShowHexNum(4, 4, Serial_RxPacket[1], 2); 
			OLED_ShowHexNum(4, 7, Serial_RxPacket[2], 2); 
			OLED_ShowHexNum(4, 10, Serial_RxPacket[3], 2); 
		}
	}
}

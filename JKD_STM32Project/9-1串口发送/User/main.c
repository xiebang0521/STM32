#include "stm32f10x.h"
#include "OLED.h"
#include "Serial.h"
#include <stdio.h>
int main(void)
{
	uint8_t Array[4] = {0x42,0x43,0x44,0x45};
	OLED_Init();
	Serial_Init();
	Serial_SendByte(0x41);
	Serial_SendArray(Array, 4);
	Serial_SendString("\r\nNum1=");
	Serial_SendNumber(111,3);

	printf("\r\nNum2=%d", 222);

	char String[100];
	sprintf(String, "\r\nNum3=%d", 333);
	Serial_SendString(String);

	Serial_Printf("\r\nNum4=%d", 444);
	Serial_Printf("\r\n");                       
	while(1)
	{
		
	}
}

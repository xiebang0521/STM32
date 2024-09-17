#include "stm32f10x.h"
#include "OLED.h"
#include "Delay.h"
#include "MyRTC.h"
#include "Key.h"

uint8_t KeyNum;
uint16_t ArrayWrite[] = {0x1234, 0x5678};
uint16_t ArrayRead[2];


int main(void)
{
	OLED_Init();
	MyRTC_Init();

	OLED_ShowString(1,1, "Date:xxxx-xx-xx");
	OLED_ShowString(2,1, "Time:xx:xx:xx");
	OLED_ShowString(3,1, "Cnt :");
	while(1)
	{
		MyRTC_ReadTime();
		OLED_ShowNum(1 , 6, Time1.year, 4) ;
		OLED_ShowNum(1 , 11, Time1.month, 2);
		OLED_ShowNum(1 , 14, Time1.day, 2);
		OLED_ShowNum(2 , 6, Time1.hour, 2) ;
		OLED_ShowNum(2 , 9, Time1.min, 2);
		OLED_ShowNum(2 , 12, Time1.s, 2);
		OLED_ShowNum(3 , 6, RTC_GetCounter(),10);
	}
}

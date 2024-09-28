#include "stm32f10x.h"
#include "SysDelay.h"
#include "OLED.h"
#include "Count_Sensor.h"
#include "Encode.h"

int32_t Num;
int main()	
{
	CountSenor_Init();
	Encode_Init();
	OLED_Init();
	OLED_Clear();

	while(1)
	{
		OLED_ShowString(1,1,"count:");
		OLED_ShowNum(1,7,GetCount(),5);

		OLED_ShowString(2,1,"encode:");
		Num += Get_Encode_Count();
		OLED_ShowSignedNum(2,8,Num,5);

	}
	
}

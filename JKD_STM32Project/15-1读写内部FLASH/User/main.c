#include "stm32f10x.h"
#include "OLED.h"
#include "Store.h"
#include "Delay.h"
#include "KEY.h"

uint8_t KeyNum;
int main(void)
{
	OLED_Init();
	Gpio_Key_Config();
	Store_Init();
	EXTI_KEY_INIT();
	OLED_ShowString(1, 1, "Flag:");
	OLED_ShowString(2, 1, "Data:");
	while(1)
	{
		KeyNum = Key_Scan();
		if(KeyNum == 1)
		{
			Store_Data[1]++;
			Store_Data[2] += 2;
			Store_Data[3] += 3;
			Store_Data[4] += 4;
			Store_Save();
			
			
			
		}
		
		if(KeyNum == 2)
		{
			Store_Clear();
		}
		
		OLED_ShowHexNum(1, 6, Store_Data[0], 4);
		OLED_ShowHexNum(3, 1, Store_Data[1], 4);
		OLED_ShowHexNum(3, 6, Store_Data[2], 4);
		OLED_ShowHexNum(4, 1, Store_Data[3], 4);
		OLED_ShowHexNum(4, 6, Store_Data[4], 4);


		OLED_ShowString(2, 12, "Run");
		Delay_ms(1000);
		OLED_ShowString(2, 12, "   ");
		Delay_ms(1000);
		PWR_EnterSTOPMode(PWR_Regulator_ON, PWR_STOPEntry_WFI);
		SystemInit();
	}
}

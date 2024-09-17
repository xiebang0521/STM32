#include "stm32f10x.h"
#include "OLED.h"
#include "AD.h"
#include "Delay.h"
uint16_t ADVlaue;
float Voltage;
int main(void)
{
	OLED_Init();
	AD_Init();
	OLED_ShowString(1,1,"ADValue:");
	OLED_ShowString(2,1,"Voltage:0.00V");
	while(1)
	{

		ADVlaue = AD_GetValue();
		Voltage = (float)ADVlaue / 4096 * 3.3;
		OLED_ShowNum(1,9,ADVlaue, 4);
		OLED_ShowNum(2,9,Voltage, 1);
		OLED_ShowNum(2,11,(uint16_t)(Voltage * 100) % 100 , 2);
		Delay_ms(100);
	}
}

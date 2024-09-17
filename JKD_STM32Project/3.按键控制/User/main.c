#include "stm32f10x.h"
#include "bsp_led.h"
#include "LED.h"
#include "KEY.h"
void delay(uint32_t i)
{
	for(;i>0;i--);
}
uint8_t KeyNum;
int main(void)
{
	GPIO_LEDConfig();
	Gpio_Key_Config();
	
	while(1)
	{
		KeyNum = Key_Scan();
		if(KeyNum == 1)
		{
			LED1_TURN();
		}

		if (KeyNum == 2)
		{
			LED2_TURN();
		}
		

	}
}

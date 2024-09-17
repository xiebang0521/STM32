#include "stm32f10x.h"
#include "bsp_led.h"

void delay(uint32_t i)
{                 
	for(  ;i>0;i--);
}
int main(void)
{
	GPIO_LEDConfig();
	while(1)
	{
		LED_ON
		delay(0xfffff);
		LED_OFF
		delay(0xfffff);
	}
}

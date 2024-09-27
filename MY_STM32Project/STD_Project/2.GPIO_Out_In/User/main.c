#include "stm32f10x.h"
#include "SysDelay.h"
#include "led_gpio.h"
#include "key_gpio.h"

int main()	
{
	LED_GPIO_Config();
	KEY_GPIO_Config();
	
	while(1)
	{
		if (Key_Scan(KEY1_GOIO_PORT, KEY1_GOIO_PIN) == KEY_ON)
		{
			LED1Toggle();
		}

		if (Key_Scan(KEY2_GOIO_PORT, KEY2_GOIO_PIN) == KEY_ON)
		{
			LED2Toggle();
		}
		
	}
	
}

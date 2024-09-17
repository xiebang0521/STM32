#include "stm32f10x.h"
#include "bsp_led.h"
#include "LED.h"
#include "KEY.h"
#include "PhotoElectricSensor.h"
void delay(uint32_t i)
{
	for(;i>0;i--);
}
uint8_t KeyNum;
int main(void)
{
	GPIO_LEDConfig();
	GPIO_PESConfig();
	
	while(1)
	{
		if(SCAN_PES() == 1)
		{
			LED1_ON();
		}
		else
		{
			LED1_OFF();
		}

	}
} 

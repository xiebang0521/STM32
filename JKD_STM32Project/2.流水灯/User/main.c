#include "stm32f10x.h"
#include "bsp_led.h"

void delay(uint32_t i)
{
	for(;i>0;i--);
}
int main(void)
{
	GPIO_LEDConfig();
	GPIO_FmqConfig();
	while(1)
	{
		GPIO_Write(GPIOA,0X00001);
		delay(0xfffff);
		GPIO_Write(GPIOA,0X00002);
		delay(0xfffff);
		GPIO_Write(GPIOA,0X00004);
		delay(0xfffff);
		GPIO_Write(GPIOA,0X00008);
		delay(0xfffff);
		GPIO_Write(GPIOA,0X00010);
		delay(0xfffff);	
		GPIO_Write(GPIOA,0X00020);
		delay(0xfffff);
		GPIO_Write(GPIOA,0X00040);
		delay(0xfffff);
		GPIO_Write(GPIOA,0X00080);
		delay(0xfffff);		
		GPIO_SetBits(GPIO);
	}
}

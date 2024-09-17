#include "stm32f10x.h"

int main()	
{
	//1.使能时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	while(1)
	{
//		//1.使能时钟
//		RCC->APB2ENR = 1 << 4;
//		
//		//2.GPIOC 的配置出入输出的模式
//		GPIOC->CRH = (0011) << (4*5);
//		//3.控制引脚输出
//		GPIOC->BRR = 0 << 13;	
		GPIO_InitTypeDef GPIO_InitStruct;
		GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
		GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0;
		GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
		//2.GPIOC 的配置出入输出的模式
		GPIO_Init(GPIOA,&GPIO_InitStruct);
		GPIO_SetBits(GPIOA,GPIO_Pin_0);
		GPIO_ResetBits(GPIOA,GPIO_Pin_0);
	}
}

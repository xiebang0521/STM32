#include "KeyExti.h"


void Key_Exti_NVIC_Config(void)
{
	NVIC_InitTypeDef NVIV_InitStruct;
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	NVIV_InitStruct.NVIC_IRQChannel = EXTI1_IRQn;
	NVIV_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIV_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;
	NVIV_InitStruct.NVIC_IRQChannelSubPriority = 1;
	
	NVIC_Init(&NVIV_InitStruct);
}


void EXTI_KEY_INIT(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	EXTI_InitTypeDef EXTI_InitStruct;
	
	RCC_APB2PeriphClockCmd(GPIO_KEY_CLK, ENABLE);
	RCC_APB2PeriphClockCmd(EXTI_KEY_CLK, ENABLE);
	
	
	GPIO_InitStruct.GPIO_Pin = GPIO_KEY_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIO_KEY_PORT, &GPIO_InitStruct);
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource1);
	
	
	EXTI_InitStruct.EXTI_Line = EXTI_Line1;
	EXTI_InitStruct.EXTI_LineCmd = ENABLE;
	EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Rising_Falling;
	EXTI_Init(&EXTI_InitStruct);
	Key_Exti_NVIC_Config();
	
}
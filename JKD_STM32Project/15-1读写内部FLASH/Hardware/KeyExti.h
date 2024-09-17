#ifndef __KEYEXTI_H
#define __KEYEXTI_H

#include "stm32f10x.h"

#define GPIO_KEY_CLK 	RCC_APB2Periph_GPIOB
#define GPIO_KEY_PORT  	GPIOB
#define GPIO_KEY_PIN 	GPIO_Pin_0

#define EXTI_KEY_CLK	RCC_APB2Periph_AFIO
void Key_Exti_NVIC_Config(void);
void EXTI_KEY_INIT(void);

#endif

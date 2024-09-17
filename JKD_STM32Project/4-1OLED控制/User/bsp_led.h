#ifndef __BSP_LED_H
#define __BSP_LED_H
#include "stm32f10x.h"

void GPIO_LEDConfig(void);

#define LED_ON  GPIO_ResetBits(GPIOA,GPIO_Pin_1);
#define LED_OFF GPIO_SetBits(GPIOA,GPIO_Pin_1);
#endif


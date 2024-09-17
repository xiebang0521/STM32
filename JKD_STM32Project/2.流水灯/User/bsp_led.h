#ifndef __BSP_LED_H
#define __BSP_LED_H
#include "stm32f10x.h"

void GPIO_LEDConfig(void);
void GPIO_FmqConfig(void);

#define LED0_ON  GPIO_ResetBits(GPIOA,GPIO_Pin_0);
#define LED0_OFF GPIO_SetBits(GPIOA,GPIO_Pin_0);
#define LED1_ON  GPIO_ResetBits(GPIOA,GPIO_Pin_1);
#define LED1_OFF GPIO_SetBits(GPIOA,GPIO_Pin_1);
#define LED2_ON  GPIO_ResetBits(GPIOA,GPIO_Pin_2);
#define LED2_OFF GPIO_SetBits(GPIOA,GPIO_Pin_2);
#define LED3_ON  GPIO_ResetBits(GPIOA,GPIO_Pin_3);
#define LED3_OFF GPIO_SetBits(GPIOA,GPIO_Pin_3);
#define LED4_ON  GPIO_ResetBits(GPIOA,GPIO_Pin_4);
#define LED4_OFF GPIO_SetBits(GPIOA,GPIO_Pin_4);
#define LED5_ON  GPIO_ResetBits(GPIOA,GPIO_Pin_5);
#define LED5_OFF GPIO_SetBits(GPIOA,GPIO_Pin_5);
#define LED6_ON  GPIO_ResetBits(GPIOA,GPIO_Pin_6);
#define LED6_OFF GPIO_SetBits(GPIOA,GPIO_Pin_6);
#define LED7_ON  GPIO_ResetBits(GPIOA,GPIO_Pin_7);
#define LED7_OFF GPIO_SetBits(GPIOA,GPIO_Pin_7);
#define FMQ_ON  GPIO_ResetBits(GPIOA,GPIO_Pin_8);
#define FMQ_OFF GPIO_SetBits(GPIOA,GPIO_Pin_8);
#endif


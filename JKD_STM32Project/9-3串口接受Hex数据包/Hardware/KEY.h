#ifndef __KEY_H
#define __KEY_H

#include "stm32f10x.h"

#define KEY1_GPIO_PIN       GPIO_Pin_6
#define KEY1_GPIO_PORT      GPIOA3
#define KEY1_GPIO_CLK       RCC_APB2Periph_GPIOA
#define KEY1_GPIO_CLOCKCMD  RCC_APB2PeriphClockCmd

#define KEY2_GPIO_PIN       GPIO_Pin_4
#define KEY2_GPIO_PORT      GPIOA
#define KEY2_GPIO_CLK       RCC_APB2Periph_GPIOA
#define KEY2_GPIO_CLOCKCMD  RCC_APB2PeriphClockCmd


void  Gpio_Key_Config(void);
uint8_t Key_Scan(void);
#endif

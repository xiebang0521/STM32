#ifndef __LED_H
#define __LED_H

#include "stm32f10x.h"

#define LED_GPIO_PORT       GPIOA
#define LED_GPIO_CLK        RCC_APB2Periph_GPIOA
#define LED_GPIO_CLOCKCMD   RCC_APB2PeriphClockCmd
#define LED_GPIO_PIN1        GPIO_Pin_0
#define LED_GPIO_PIN2        GPIO_Pin_1

void GPIO_LEDConfig(void);
void LED1_ON(void);
void LED1_OFF(void);
void LED2_ON(void);
void LED2_OFF(void);
void LED1_TURN(void);
void LED2_TURN(void);

#endif

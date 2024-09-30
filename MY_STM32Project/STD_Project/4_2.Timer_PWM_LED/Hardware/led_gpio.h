#ifndef __BSP_GPIO_H__
#define __BSP_GPIO_H__

#include "stm32f10x.h"

#define LED1_GOIO_PORT  GPIOB
#define LED1_GOIO_PIN   GPIO_Pin_5

#define LED2_GOIO_PORT  GPIOE
#define LED2_GOIO_PIN   GPIO_Pin_5

#define LEDON 1
#define LEDOFF 0

void LED_GPIO_Config(void);
void LED1ON(void);
void LED1OFF(void);
void LED1Toggle(void);

void LED2ON(void);
void LED2OFF(void);
void LED2Toggle(void); 
#endif

#ifndef __KEY_GPIO_H__
#define __KEY_GPIO_H__
#include "stm32f10x.h"

#define KEY1_GOIO_PORT  GPIOE
#define KEY1_GOIO_PIN   GPIO_Pin_2

#define KEY2_GOIO_PORT  GPIOE
#define KEY2_GOIO_PIN   GPIO_Pin_3

#define KEY3_GOIO_PORT  GPIOE
#define KEY3_GOIO_PIN   GPIO_Pin_4

#define KEY_ON 1 //按键按下
#define KEY_OFF 0 //按键未按下
void KEY_GPIO_Config(void);
uint32_t Key_Scan(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
#endif


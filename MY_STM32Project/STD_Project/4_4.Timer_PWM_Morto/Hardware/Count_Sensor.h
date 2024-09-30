#ifndef __COUNT_SENSOR_H__
#define __COUNT_SENSOR_H__
#include "stm32f10x.h"

#define COUNT_SENSOR_PIN GPIO_Pin_11
#define COUNT_SENSOR_PORT GPIOA
#define COUNT_SENSOR_PORT_SOURCE GPIO_PortSourceGPIOA
#define COUNT_SENSOR_PIN_SOURCE GPIO_PinSource11

void CountSenor_Init(void);
uint32_t GetCount(void);
#endif


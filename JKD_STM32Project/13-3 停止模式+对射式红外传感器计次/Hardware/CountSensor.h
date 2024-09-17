#ifndef __COUNTSENSOR_H
#define __COUNTSENSOR_H

#include "stm32f10x.h"
#define COUNTSENSOR_GPIO_PORT           GPIOB
#define COUNTSENSOR_GPIO_PIN            GPIO_Pin_14
#define COUNTSENSOR_GPIO_CLK            RCC_APB2Periph_GPIOB
#define COUNTSENSOR_GPIO_PORTSORTCE     GPIO_PortSourceGPIOB
#define COUNTSENSOR_GPIO_PINTSORTCE     GPIO_PinSource14
#define COUNTSENSOR_AFIO_CLK            RCC_APB2Periph_AFIO
#define COUNTSENSOR_EXTIX_LINE          EXTI_Line14

void EXTI_COUNTSensorConfig(void);
uint16_t CountSensor_Get(void);
#endif

#ifndef __PHOTOELECTRICSENSOR_H
#define __PHOTOELECTRICSENSOR_H

#include "stm32f10x.h"

#define GPIO_PES_PIN            GPIO_Pin_8
#define GPIO_PES_PORT           GPIOA
#define GPIO_PES_CLK            RCC_APB2Periph_GPIOA
#define GPIO_PES_CLOCKCMD       RCC_APB2PeriphClockCmd
void GPIO_PESConfig(void);
uint8_t SCAN_PES(void);

#endif

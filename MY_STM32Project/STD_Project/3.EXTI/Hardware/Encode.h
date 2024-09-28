#ifndef __ENCODE_H__
#define __ENCODE_H__
#include "stm32f10x.h"

#define ENCODE_PHASEA_PIN GPIO_Pin_6
#define ENCODE_PHASEA_PORT GPIOA
#define ENCODE_PHASEA_PORT_SOURCE GPIO_PortSourceGPIOA
#define ENCODE_PHASEA_PIN_SOURCE GPIO_PinSource6
#define ENCODE_PHASEA_EXTI_LINE EXTI_Line6

#define ENCODE_PHASEB_PIN GPIO_Pin_7
#define ENCODE_PHASEB_PORT GPIOA
#define ENCODE_PHASEB_PORT_SOURCE GPIO_PortSourceGPIOA
#define ENCODE_PHASEB_PIN_SOURCE GPIO_PinSource7
#define ENCODE_PHASEB_EXTI_LINE EXTI_Line7

int32_t Get_Encode_Count(void);
void Encode_Init(void);
#endif

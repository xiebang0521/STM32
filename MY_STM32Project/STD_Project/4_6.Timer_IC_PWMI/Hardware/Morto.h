#ifndef __MORTO_H__
#define __MORTO_H__
#include "stm32f10x.h"
#include "Timer.h"


void Morto_Init(void);

void Morto_SetSpeed(uint16_t speed);
void PWM_SetPresacler(uint16_t Presacler);
#endif

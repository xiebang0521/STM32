#ifndef __TIMER_H__
#define __TIMER_H__
#include "stm32f10x.h"

void Timer_Init(void);
uint32_t Timer_GetCount(void);
void Timer_SetCompare3(uint16_t compare);
#endif

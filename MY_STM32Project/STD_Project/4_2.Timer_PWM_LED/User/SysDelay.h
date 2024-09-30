#ifndef __SYSDELAY_H__
#define __SYSDELAY_H__
#include "stm32f10x.h"
#include "core_cm3.h"

#define SYSTICK_COUNTFLAG ((SysTick->CTRL >> 16) & 0x01)
void Delaynms(uint32_t ms);
void Delaynus(uint32_t us);
#endif

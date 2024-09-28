#include "SysDelay.h"


void Delaynus(uint32_t us)
{
	uint32_t i = 0;
	SysTick_Config(72);
	for(i = 0; i < us; i++)
	{
		while(!SYSTICK_COUNTFLAG);
	}
	// 失能systick
	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
}


void Delaynms(uint32_t ms)
{
	uint32_t i = 0;
	SysTick_Config(72000);
	
	for(i = 0; i < ms; i++)
	{
		while(!SYSTICK_COUNTFLAG);
	}
	// 失能systick
	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
}

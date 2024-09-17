#ifndef __MYFALSH_H
#define __MYFALSH_H

#include "stm32f10x.h"
uint32_t MyFlash_ReadWord(uint32_t Address);
uint16_t MyFlash_ReadHalfWord(uint32_t Address);
uint8_t MyFlash_ReadByte(uint32_t Address);
void MyFlash_EarseAllPages(void);
void MyFalsh_EarsePages(uint32_t PagesAddress);
void MyFlash_ProgramWord(uint32_t Address, uint32_t Data);
void MyFlash_ProgramHalfWord(uint32_t Address, uint16_t Data);
#endif


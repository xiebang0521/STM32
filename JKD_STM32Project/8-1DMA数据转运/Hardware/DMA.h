#ifndef __DMA_H
#define __DMA_H

#include "stm32f10x.h"

void DMA_Config(uint32_t AddrSrc, uint32_t AddrDes, uint16_t size);
void DMA_Transfer(void);
#endif

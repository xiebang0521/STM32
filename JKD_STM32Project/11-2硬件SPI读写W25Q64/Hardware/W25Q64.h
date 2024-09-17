#ifndef	__W25Q64_H
#define __W25Q64_H

#include "stm32f10x.h"
#include "MySPI.h"
void W25Q64_Init(void);
void W25Q64_ReadID(uint8_t* ManufacturerID, uint16_t* MemoryID);
void W25Q64_PageProgram(uint32_t Address, uint8_t* DataArray, uint16_t Count);
void W25Q64_SectorErase(uint32_t Address);
void W25Q64_ReadData(uint32_t Address, uint8_t* DataArray, uint32_t Count);
#endif


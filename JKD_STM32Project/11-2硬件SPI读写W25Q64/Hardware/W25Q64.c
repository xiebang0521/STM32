#include "W25Q64.h"
#include "W25Q64_Ins.h"

void W25Q64_Init(void)
{
	MySPI_Init();
}

void W25Q64_ReadID(uint8_t* ManufacturerID, uint16_t* MemoryID)
{
	MySPI_Start();
	//读取ID号的指令
	MySPI_SwapByte(W25Q64_JEDEC_ID);
	*ManufacturerID = MySPI_SwapByte(W25Q64_DUMMY_BYTE);
	*MemoryID = MySPI_SwapByte(W25Q64_DUMMY_BYTE);
	*MemoryID <<= 8;
	*MemoryID |= MySPI_SwapByte(W25Q64_DUMMY_BYTE);
	MySPI_Stop();
}

void W25Q64_WriteEnable(void)
{
	MySPI_Start();
	MySPI_SwapByte(W25Q64_WRITE_ENABLE);
	MySPI_Stop();
}

//读状态寄存器1
void W25Q64_WaitBusy(void)
{	
	uint32_t TimeOut;
	MySPI_Start();
	MySPI_SwapByte(W25Q64_READ_STATUS_REGISTER_1);
	TimeOut = 100000;
	while((MySPI_SwapByte(W25Q64_DUMMY_BYTE) & 0x01) == 1)
	{
		TimeOut--;
		if (TimeOut == 0)
		{
			break;
		}
		
	}
	MySPI_Stop();
}

void W25Q64_PageProgram(uint32_t Address, uint8_t* DataArray, uint16_t Count)
{
	W25Q64_WriteEnable();
	MySPI_Start();
	MySPI_SwapByte(W25Q64_PAGE_PROGRAM);
	MySPI_SwapByte(Address >> 16);
	MySPI_SwapByte(Address >> 8);
	MySPI_SwapByte(Address);

	for(uint32_t i = 0; i < Count; i++)
	{
		MySPI_SwapByte(DataArray[i]);	
	}

	MySPI_Stop();
	W25Q64_WaitBusy();
}

void W25Q64_SectorErase(uint32_t Address)
{
	W25Q64_WriteEnable();
	MySPI_Start();
	MySPI_SwapByte(W25Q64_SECTOR_ERASE_4KB);
	MySPI_SwapByte(Address >> 16);
	MySPI_SwapByte(Address >> 8);
	MySPI_SwapByte(Address);
	MySPI_Stop();
	W25Q64_WaitBusy();
}


void W25Q64_ReadData(uint32_t Address, uint8_t* DataArray, uint32_t Count)
{
	MySPI_Start();
	MySPI_SwapByte(W25Q64_READ_DATA);
	MySPI_SwapByte(Address >> 16);
	MySPI_SwapByte(Address >> 8);
	MySPI_SwapByte(Address);
	for(uint32_t i = 0 ; i < Count; i++)
	{
		DataArray[i] = MySPI_SwapByte(W25Q64_DUMMY_BYTE);
	}
	MySPI_Stop();
}

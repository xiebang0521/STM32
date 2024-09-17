#include "MyFlash.h"

uint32_t MyFlash_ReadWord(uint32_t Address)
{
	return	*((__IO uint32_t *)(Address));
}


uint16_t MyFlash_ReadHalfWord(uint32_t Address)
{
	return	*((__IO uint16_t *)(Address));
}

uint8_t MyFlash_ReadByte(uint32_t Address)
{
	return	*((__IO uint8_t *)(Address));
}

// ȫ����
void MyFlash_EarseAllPages(void)
{
	//1���Ƚ���
	FLASH_Unlock();
	// 2��д���ֵ
	FLASH_EraseAllPages();
	FLASH_Lock();
}

// ҳ����

void MyFalsh_EarsePages(uint32_t PagesAddress)
{
	//1���Ƚ���
	FLASH_Unlock();
	//2�����в������
	FLASH_ErasePage(PagesAddress);
	//3������
	FLASH_Lock();
}


void MyFlash_ProgramWord(uint32_t Address, uint32_t Data)
{
		//1���Ƚ���
	FLASH_Unlock();
	//2�����б��
	FLASH_ProgramWord(Address, Data);
	//3������
	FLASH_Lock();
}

void MyFlash_ProgramHalfWord(uint32_t Address, uint16_t Data)
{
		//1���Ƚ���
	FLASH_Unlock();
	//2�����б��
	FLASH_ProgramHalfWord(Address, Data);
	//3������
	FLASH_Lock();
}

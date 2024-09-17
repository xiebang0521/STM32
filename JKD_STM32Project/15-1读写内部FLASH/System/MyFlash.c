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

// È«²Á³ı
void MyFlash_EarseAllPages(void)
{
	//1¡¢ÏÈ½âËø
	FLASH_Unlock();
	// 2¡¢Ğ´Èë¼üÖµ
	FLASH_EraseAllPages();
	FLASH_Lock();
}

// Ò³²Á³ı

void MyFalsh_EarsePages(uint32_t PagesAddress)
{
	//1¡¢ÏÈ½âËø
	FLASH_Unlock();
	//2¡¢½øĞĞ²Á³ı²Ù×
	FLASH_ErasePage(PagesAddress);
	//3¡¢¼ÓËø
	FLASH_Lock();
}


void MyFlash_ProgramWord(uint32_t Address, uint32_t Data)
{
		//1¡¢ÏÈ½âËø
	FLASH_Unlock();
	//2¡¢½øĞĞ±à³Ì
	FLASH_ProgramWord(Address, Data);
	//3¡¢¼ÓËø
	FLASH_Lock();
}

void MyFlash_ProgramHalfWord(uint32_t Address, uint16_t Data)
{
		//1¡¢ÏÈ½âËø
	FLASH_Unlock();
	//2¡¢½øĞĞ±à³Ì
	FLASH_ProgramHalfWord(Address, Data);
	//3¡¢¼ÓËø
	FLASH_Lock();
}

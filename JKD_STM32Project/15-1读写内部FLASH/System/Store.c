#include "Store.h"
#include "MyFlash.h"
uint16_t Store_Data[512];

void Store_Init(void)
{
	if(MyFlash_ReadHalfWord(0x0800fc00) != 0xa5a5)
	{
		MyFalsh_EarsePages(0x0800fc00);
		MyFlash_ProgramHalfWord(0x0800fc00, 0xa5a5);
		for(uint16_t i = 1; i < 512; i++)
		{
			MyFlash_ProgramHalfWord(0x0800fc00 + i * 2, 0x0000);
		}
	}
	
	for(uint16_t i = 0; i < 512; i++)
	{
		Store_Data[i] = MyFlash_ReadHalfWord(0x0800fc00 + i * 2);
	}
}

void Store_Save(void)
{
	MyFalsh_EarsePages(0x0800fc00);
	for(uint16_t i = 0; i < 512; i++)
	{
		MyFlash_ProgramHalfWord(0x0800fc00 + i * 2, Store_Data[i]);
	}
}

void Store_Clear(void)
{
	for(uint16_t i = 1; i < 512; i++)
	{
		Store_Data[i] = 0x0000;
	}
	
	Store_Save();
}

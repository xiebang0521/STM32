#include "stm32f10x.h"
#include "OLED.h"

int main(void)
{
	OLED_Init();
	
	OLED_ShowString(1, 1, "F_SIZE:");
	OLED_ShowHexNum(1, 8, *((__IO uint16_t*)(0x1ffff7e0)), 4);
	OLED_ShowString(2, 1, "U_ID:");
	OLED_ShowHexNum(2, 6, *((__IO uint16_t*)(0x1ffff7e8)), 4);
	OLED_ShowHexNum(2, 11, *((__IO uint16_t*)((0x1ffff7e8) + 0X02)), 4);
	OLED_ShowHexNum(3, 1, *((__IO uint32_t*)((0x1ffff7e8) + 0X04)), 8);
	OLED_ShowHexNum(4, 1, *((__IO uint32_t*)((0x1ffff7e8) + 0X08)), 8);
	while(1)
	{
		
	}
}

#include "stm32f10x.h"
#include "OLED.h"
#include "DMA.h"
#include "Delay.h"
uint8_t DataSrc[4] = {0x01,0x02,0x03,0x04};
uint8_t DataDes[4] = {0,0,0,0};


int main(void)
{
	OLED_Init();
	DMA_Config((uint32_t)DataSrc,(uint32_t)DataDes,4);
	OLED_ShowString(1,1,"DataS");
	OLED_ShowString(3,1,"DataD");
	OLED_ShowHexNum(1,8,(uint32_t)DataSrc,8);
	OLED_ShowHexNum(3,8,(uint32_t)DataDes,8);


	while(1)
	{
		DMA_Transfer();
		for(int i = 0; i < 4; i++)
		{
			DataSrc[i] = DataSrc[i]++;
		}
		Delay_s(1);
			OLED_ShowHexNum(2,1,DataSrc[0],2);
	OLED_ShowHexNum(2,4,DataSrc[1],2);
	OLED_ShowHexNum(2,7,DataSrc[2],2);
	OLED_ShowHexNum(2,10,DataSrc[3],2);
	OLED_ShowHexNum(4,1,DataDes[0],2);
	OLED_ShowHexNum(4,4,DataDes[1],2);
	OLED_ShowHexNum(4,7,DataDes[2],2);
	OLED_ShowHexNum(4,10,DataDes[3],2);
	}
}

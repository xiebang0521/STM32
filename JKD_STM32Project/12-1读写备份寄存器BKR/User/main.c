#include "stm32f10x.h"
#include "OLED.h"
#include "Delay.h"
#include "Key.h"

uint8_t KeyNum;
uint16_t ArrayWrite[] = {0x1234, 0x5678};
uint16_t ArrayRead[2];


int main(void)
{
	OLED_Init();
	Gpio_Key_Config();
	
	
	OLED_ShowString(1, 1, "W:");
	OLED_ShowString(2, 1, "R:");
	
	//����PWR��BKP��ʱ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_BKP, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR, ENABLE);
	
	
	PWR_BackupAccessCmd(ENABLE);
	
	//BKP_WriteBackupRegister(BKP_DR1, 0x1234);
	//OLED_ShowHexNum(1,1,BKP_ReadBackupRegister(BKP_DR1), 4);
	while(1)
	{
		KeyNum = Key_Scan();
		
		if(KeyNum == 1)
		{
			ArrayWrite[0]++;
			ArrayWrite[1]++;
			BKP_WriteBackupRegister(BKP_DR1, ArrayWrite[0]);
			BKP_WriteBackupRegister(BKP_DR2, ArrayWrite[1]);
			
			OLED_ShowHexNum(1, 3, ArrayWrite[0], 4);
			OLED_ShowHexNum(1, 8, ArrayWrite[1], 4);
		}
		ArrayRead[0] =  BKP_ReadBackupRegister(BKP_DR1);
		ArrayRead[1] =  BKP_ReadBackupRegister(BKP_DR2);
		
		OLED_ShowHexNum(2, 3, ArrayRead[0], 4);
		OLED_ShowHexNum(2, 8, ArrayRead[1], 4);
		
	}
}

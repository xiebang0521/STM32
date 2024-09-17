#include "stm32f10x.h"
#include "OLED.h"
#include "Delay.h"
#include "Key.h"
int main(void)
{
	OLED_Init();
	Gpio_Key_Config();
	OLED_ShowString(1, 1, "IWDG TEST");
	
	if(RCC_GetFlagStatus(RCC_FLAG_IWDGRST) == SET)
	{
		OLED_ShowString(2, 1, "IWDGRST");
		Delay_ms(500);
		OLED_ShowString(2, 1, "       ");
		Delay_ms(500);
		RCC_ClearFlag();
	}else
	{
		OLED_ShowString(3, 1, "RST");
		Delay_ms(500);
		OLED_ShowString(3, 1, "       ");
		Delay_ms(500);
		RCC_ClearFlag();
	}
	//1.����LSIʱ��
	//2.���д����
	IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);
	//3.д��Ԥ��Ƶ��������װֵ ����1000ms
	IWDG_SetPrescaler(IWDG_Prescaler_16);
	IWDG_SetReload(2499);
	IWDG_ReloadCounter();
	//4.�����������Ź�
	IWDG_Enable();
	//5.ι������
	
	while(1)
	{
		Key_Scan();
		IWDG_ReloadCounter();
		
		
		OLED_ShowString(4, 1, "FEED");
		Delay_ms(200);
		OLED_ShowString(4, 1, "    ");
		Delay_ms(600);
//		Delay_ms(1015);
//		IWDG_SetPrescaler();
//		IWDG_SetReload();
//		IWDG_ReloadCounter();
	}
}

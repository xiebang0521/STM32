#include "stm32f10x.h"
#include "OLED.h"
#include "Delay.h"
#include "Key.h"
int main(void)
{
	OLED_Init();
	Gpio_Key_Config();
	OLED_ShowString(1, 1, "IWDG TEST");
	
	if(RCC_GetFlagStatus(RCC_FLAG_WWDGRST) == SET)
	{
		OLED_ShowString(2, 1, "WWDGRST");
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
	//1.����APB1ʱ��
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_WWDG, ENABLE);
	//3.д��Ԥ��Ƶ��������װֵ ����1000ms
	WWDG_SetPrescaler(WWDG_Prescaler_8);
	//���ô���ֵ
	WWDG_SetWindowValue( 0x40 | 21);
	// 0x40 �ǰѵ���λ��1
	WWDG_Enable(54 | 0x40);
	
	
	while(1)
	{
		Key_Scan();

		
//		OLED_ShowString(4, 1, "FEED");
//		Delay_ms(20);
//		OLED_ShowString(4, 1, "    ");
//		Delay_ms(20);
		
		//ι������
		Delay_ms(49);
		WWDG_SetCounter(54 | 0x40);
//		Delay_ms(1015);
//		IWDG_SetPrescaler();
//		IWDG_SetReload();
//		IWDG_ReloadCounter();
	}
}

#include "stm32f10x.h"
#include "OLED.h"
#include "CountSensor.h"
#include "Delay.h"
int main(void)
{
	OLED_Init();
	OLED_ShowString(1,1,"Count");


	EXTI_COUNTSensorConfig();
	while(1)
	{
		OLED_ShowNum(1,7,CountSensor_Get(),6);
		
		OLED_ShowString(2, 1, "Running");
		Delay_ms(100);
		OLED_ShowString(2, 1, "       ");
		Delay_ms(100);
		
		PWR_EnterSTOPMode(PWR_Regulator_ON, PWR_STOPEntry_WFI);
		SystemInit();
	}
}

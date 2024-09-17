#include "stm32f10x.h"
#include "OLED.h"
#include "CountSensor.h"
int main(void)
{
	OLED_Init();
	OLED_ShowString(1,1,"Count");


	EXTI_COUNTSensorConfig();
	while(1)
	{
		OLED_ShowNum(2,1,CountSensor_Get(),6);
	}
}

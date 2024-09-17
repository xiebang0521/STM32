#include "stm32f10x.h"
#include "OLED.h"
#include "Timer.h"
#include "Delay.h"
#include "Encoder.h"
int16_t speed;

int main(void)
{
	OLED_Init();
	Timer_Config();
	Encoder_Init();
	OLED_ShowString(1,1,"Speed:");

	while(1)
	{
		OLED_ShowSignedNum(1,7,speed,5);
	}
}
// void TIM2_IRQHandler(void)
// {
//     if(TIM_GetITStatus(TIM2, TIM_IT_Update) == SET)
//     {
//       speed = Encoder_Get();
//       TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
//     }
// }
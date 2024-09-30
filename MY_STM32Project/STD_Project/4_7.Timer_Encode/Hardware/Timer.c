#include "Timer.h"
#include "TIM_Encode.h"

extern int16_t speed;
void NVIC_Config(void)
{
    NVIC_InitTypeDef NVIC_InitStruct;
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

    NVIC_InitStruct.NVIC_IRQChannel = TIM2_IRQn;
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
    NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;
    NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;

    NVIC_Init(&NVIC_InitStruct);
}

void Timer_Init(void)
{
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
    TIM_InternalClockConfig(TIM2);

    TIM_TimeBaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInitStruct.TIM_Period = 10000 - 1;
    TIM_TimeBaseInitStruct.TIM_Prescaler = 7200 -1;
    TIM_TimeBaseInitStruct.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStruct);

    TIM_ClearFlag(TIM2, TIM_IT_Update);
    TIM_ITConfig(TIM2,TIM_IT_Update, ENABLE);
    NVIC_Config();

    TIM_Cmd(TIM2,ENABLE);
}

void TIM2_IRQHandler(void)
{

    if(TIM_GetITStatus(TIM2, TIM_IT_Update) == SET)
    {
		speed = TIM_Encode_GetNum();
        TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
        
    }
}

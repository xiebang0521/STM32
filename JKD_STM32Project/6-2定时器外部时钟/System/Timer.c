#include "Timer.h"

void NVIC_Config(void)
{
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

    NVIC_InitTypeDef  NVIC_InitStruct;
    NVIC_InitStruct.NVIC_IRQChannel = TIM2_IRQn;
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
    NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 2;
    NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;
    NVIC_Init(&NVIC_InitStruct);
}

void Timer_Config(void)
{
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    TIM_ETRClockMode2Config(TIM2, TIM_ExtTRGPSC_OFF, TIM_ExtTRGPolarity_Inverted, 0X00);

    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0;
    GPIO_Init(GPIOA, &GPIO_InitStruct);
    
    TIM_TimeBaseInitTypeDef TIM_TimerBaseInitStruct;
    TIM_TimerBaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimerBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimerBaseInitStruct.TIM_Period = 10 - 1;
    TIM_TimerBaseInitStruct.TIM_Prescaler = 1 - 1;
    TIM_TimerBaseInitStruct.TIM_RepetitionCounter = 0;

    
    TIM_TimeBaseInit(TIM2, &TIM_TimerBaseInitStruct);
    //解除刚更新完就进入中断的问题
    TIM_ClearFlag(TIM2, TIM_FLAG_Update);
    TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
    NVIC_Config();
    TIM_Cmd(TIM2, ENABLE);
}

int16_t TimCountGet(void)
{
    return TIM_GetCounter(TIM2);
}

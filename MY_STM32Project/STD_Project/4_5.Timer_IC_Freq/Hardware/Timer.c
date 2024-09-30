#include "Timer.h"

// int32_t Num;


void Timer_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct;
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
    TIM_OCInitTypeDef TIM_OCInitStruct;
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
    TIM_InternalClockConfig(TIM2);
    
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_2;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_10MHz;
    GPIO_Init(GPIOA, &GPIO_InitStruct);

    TIM_TimeBaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInitStruct.TIM_Period = 2000;//  1KHZ
    TIM_TimeBaseInitStruct.TIM_Prescaler = 72;// 1 MHZ
    TIM_TimeBaseInitStruct.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStruct);

    TIM_OCStructInit(&TIM_OCInitStruct);
    TIM_OCInitStruct.TIM_OCMode = TIM_OCMode_PWM1;
    TIM_OCInitStruct.TIM_OCPolarity = TIM_OCPolarity_High;
    TIM_OCInitStruct.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStruct.TIM_Pulse = 50;
    TIM_OC3Init(TIM2, &TIM_OCInitStruct);

    TIM_Cmd(TIM2,ENABLE);
}

uint32_t Timer_GetCount(void)
{
    return TIM_GetCounter(TIM2);
}

void Timer_SetCompare3(uint16_t compare)
{
     TIM_SetCompare3(TIM2, compare);
}

void Timer_PrescalerConfig(uint16_t Presacler)
{
     TIM_PrescalerConfig(TIM2, Presacler, TIM_PSCReloadMode_Update);
}

// void TIM2_IRQHandler(void)
// {

//     if(TIM_GetITStatus(TIM2, TIM_IT_Update) == SET)
//     {
//         TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
//         Num++;
//     }
// }

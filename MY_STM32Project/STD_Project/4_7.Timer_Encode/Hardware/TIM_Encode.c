#include "TIM_Encode.h"


void TIM_Encode_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitTStruct;
    TIM_ICInitTypeDef TIM_ICInitStructure;

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPD;
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_10MHz;
    GPIO_Init(GPIOA, &GPIO_InitStruct);

    TIM_InternalClockConfig(TIM3);

    TIM_TimeBaseInitTStruct.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseInitTStruct.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInitTStruct.TIM_Period= 65536 - 1;
    TIM_TimeBaseInitTStruct.TIM_Prescaler = 72 - 1;
    TIM_TimeBaseInitTStruct.TIM_RepetitionCounter = 0;
    TIM_TimeBaseStructInit(&TIM_TimeBaseInitTStruct);

    TIM_ICStructInit(&TIM_ICInitStructure);
    TIM_ICInitStructure.TIM_ICFilter = 0xf;
    TIM_ICInit(TIM3, &TIM_ICInitStructure);

    TIM_EncoderInterfaceConfig(TIM3,TIM_EncoderMode_TI12,TIM_ICPolarity_Rising,TIM_ICPolarity_Rising);

    TIM_Cmd(TIM3, ENABLE);
}

//int16_t TIM_Encode_GetNum(void)
//{
//    return (int16_t)TIM_GetCounter(TIM3);
//}
int16_t TIM_Encode_GetNum(void)
{
	int16_t temp = TIM_GetCounter(TIM3);
	TIM_SetCounter(TIM3, 0);
    return temp;
}

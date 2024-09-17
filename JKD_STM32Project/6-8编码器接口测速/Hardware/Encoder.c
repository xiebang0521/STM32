#include "Encoder.h"

void Encoder_Init(void)
{
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    GPIO_InitTypeDef GPIO_InitStrcut;
    GPIO_InitStrcut.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;
    GPIO_InitStrcut.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOA, &GPIO_InitStrcut);

    TIM_InternalClockConfig(TIM3);

    TIM_TimeBaseInitTypeDef TIM_TimBaseInitStrcut;
    TIM_TimBaseInitStrcut.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimBaseInitStrcut.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimBaseInitStrcut.TIM_Period = 65536 - 1;
    TIM_TimBaseInitStrcut.TIM_Prescaler = 1 - 1 ;
    TIM_TimBaseInitStrcut.TIM_RepetitionCounter = 0;
    TIM_TimeBaseStructInit(&TIM_TimBaseInitStrcut);

    TIM_ICInitTypeDef TIM_ICInitSturct;
    TIM_ICStructInit(&TIM_ICInitSturct);
    TIM_ICInitSturct.TIM_Channel = TIM_Channel_1;
    TIM_ICInitSturct.TIM_ICFilter = 0xF;
    TIM_ICInit(TIM3, &TIM_ICInitSturct);
    TIM_ICInitSturct.TIM_Channel = TIM_Channel_2;
    TIM_ICInitSturct.TIM_ICFilter = 0xF;
    TIM_ICInit(TIM3, &TIM_ICInitSturct);

    TIM_EncoderInterfaceConfig(TIM3, TIM_EncoderMode_TI12,TIM_ICPolarity_Rising,TIM_ICPolarity_Rising);

    TIM_Cmd(TIM3, ENABLE);
}

int16_t Encoder_Get(void)
{
    int tmp = TIM_GetCounter(TIM3);
    TIM_SetCounter(TIM3, 0);
    return tmp;
}

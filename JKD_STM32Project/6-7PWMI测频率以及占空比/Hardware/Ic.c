#include "Ic.h"

void IC_Init(void)
{
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    GPIO_InitTypeDef GOIO_InitStruct;
    GOIO_InitStruct.GPIO_Pin = GPIO_Pin_6;
    GOIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_Init(GPIOA, &GOIO_InitStruct);

    TIM_InternalClockConfig(TIM3);

    TIM_TimeBaseInitTypeDef TIM_TimeBaseStruct;
    TIM_TimeBaseStruct.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseStruct.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseStruct.TIM_Period = 65536 - 1;// ARR -1
    TIM_TimeBaseStruct.TIM_Prescaler = 72 - 1;//PSC
    TIM_TimeBaseStruct.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStruct);

    TIM_ICInitTypeDef TIM_ICInitSturct;
    TIM_ICInitSturct.TIM_Channel = TIM_Channel_1;
    TIM_ICInitSturct.TIM_ICFilter = 0xF;
    TIM_ICInitSturct.TIM_ICPolarity = TIM_ICPolarity_Rising;
    TIM_ICInitSturct.TIM_ICPrescaler = TIM_ICPSC_DIV1;
    TIM_ICInitSturct.TIM_ICSelection = TIM_ICSelection_DirectTI;
    TIM_PWMIConfig(TIM3, &TIM_ICInitSturct);
    //TIM_ICInit(TIM3, &TIM_ICInitSturct);

    // TIM_ICInitSturct.TIM_Channel = TIM_Channel_2;
    // TIM_ICInitSturct.TIM_ICFilter = 0xF;
    // TIM_ICInitSturct.TIM_ICPolarity = TIM_ICPolarity_Falling;
    // TIM_ICInitSturct.TIM_ICPrescaler = TIM_ICPSC_DIV1;
    // TIM_ICInitSturct.TIM_ICSelection = TIM_ICSelection_IndirectTI;
    // TIM_ICInit(TIM3, &TIM_ICInitSturct);

    TIM_SelectInputTrigger(TIM3, TIM_TS_TI1FP1);
    TIM_SelectSlaveMode(TIM3, TIM_SlaveMode_Reset);
    TIM_Cmd(TIM3, ENABLE);
}

uint32_t IC_GetFreq(void)  
{
    return 1000000 / (TIM_GetCapture1(TIM3)+1) ;
}

uint8_t IC_GetDuty(void)
{
    return (TIM_GetCapture2(TIM3)+1) * 100 / (TIM_GetCapture1(TIM3) + 1);
}
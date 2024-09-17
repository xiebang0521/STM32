#include "PWM.h"

void PWM_Config(void)
{
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	//RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);

    //GPIO_PinRemapConfig(GPIO_PartialRemap1_TIM2, ENABLE);
    //GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);

    GPIO_InitTypeDef GOIO_InitStruct;
    GOIO_InitStruct.GPIO_Pin = GPIO_Pin_0;
    GOIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
    GOIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GOIO_InitStruct);

    // 频率为 1000HZ 占空比为 50的PWM波形
    TIM_InternalClockConfig(TIM2);
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
    TIM_TimeBaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInitStruct.TIM_Period = 20000 - 1;//ARR
    TIM_TimeBaseInitStruct.TIM_Prescaler = 72 - 1;//PSC
    TIM_TimeBaseInitStruct.TIM_RepetitionCounter = 0X00;
    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStruct);
    /*
        72M / CRR +1  / ARR+1  = 500
        CNN / ARR+ 1 = 0.025*20000 = 500
        1 / ARR + 1 = 1%;
    */    

    TIM_OCInitTypeDef TIM_OCInitStruct;
    //先把结构体赋初始值
    TIM_OCStructInit(&TIM_OCInitStruct);
    //设置输出的模式
    TIM_OCInitStruct.TIM_OCMode = TIM_OCMode_PWM1;
    //设置输出的极性
    TIM_OCInitStruct.TIM_OCPolarity = TIM_OCPolarity_High;
    //设置输出使能
    TIM_OCInitStruct.TIM_OutputState = TIM_OutputState_Enable;
    //设置CCR
    TIM_OCInitStruct.TIM_Pulse = 500;
    
    TIM_OC1Init(TIM2, &TIM_OCInitStruct);

    TIM_Cmd(TIM2, ENABLE);

}

void PWM_SetCompare1(uint16_t Compare)
{
    TIM_SetCompare1(TIM2, Compare);
}


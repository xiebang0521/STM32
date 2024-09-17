#include "CountSensor.h"
uint16_t CountSensor_Count ;
void NVICConfig(void)
{
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    NVIC_InitTypeDef NVIC_InitStruct;

    NVIC_InitStruct.NVIC_IRQChannel = EXTI15_10_IRQn;
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
    NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;
    NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;
    NVIC_Init(&NVIC_InitStruct);
}
/*
    1.打开外设的时钟
    2.配置GPIO,设置为输入模式
    3.配置AFIO,选择要用的那一路
    4.配置EXTI
    5.配置NVIC
    3.外设初始化使能
*/
void EXTI_COUNTSensorConfig(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
    
    GPIO_InitTypeDef GPIO_InitStruct;
    EXTI_InitTypeDef EXTI_InitStruct;
    GPIO_InitStruct.GPIO_Pin = COUNTSENSOR_GPIO_PIN;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(COUNTSENSOR_GPIO_PORT, &GPIO_InitStruct);
    //数据选择器的配置
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, COUNTSENSOR_GPIO_PINTSORTCE);

    EXTI_InitStruct.EXTI_Line = EXTI_Line14;
    EXTI_InitStruct.EXTI_LineCmd = ENABLE;
    EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Rising_Falling;
    EXTI_Init(&EXTI_InitStruct);
    NVICConfig();
}



uint16_t CountSensor_Get(void)
{
    return CountSensor_Count;
}


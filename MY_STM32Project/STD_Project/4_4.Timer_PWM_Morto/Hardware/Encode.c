#include "Encode.h"
int32_t encode_count;
void NVIC_Config(void)
{
    NVIC_InitTypeDef NVIC_InitStruct;
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

    NVIC_InitStruct.NVIC_IRQChannel = EXTI9_5_IRQn;
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE; 
    NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;
    NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;
    NVIC_Init(&NVIC_InitStruct);
}


void Encode_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct;
    EXTI_InitTypeDef EXTI_InitStruct;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);


    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_InitStruct.GPIO_Pin = ENCODE_PHASEA_PIN;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_10MHz;
    GPIO_Init(ENCODE_PHASEA_PORT, &GPIO_InitStruct);

    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_InitStruct.GPIO_Pin = ENCODE_PHASEB_PIN;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_10MHz;
    GPIO_Init(ENCODE_PHASEB_PORT, &GPIO_InitStruct);

    GPIO_EXTILineConfig(ENCODE_PHASEA_PORT_SOURCE , ENCODE_PHASEA_PIN_SOURCE);
    GPIO_EXTILineConfig(ENCODE_PHASEB_PORT_SOURCE , ENCODE_PHASEB_PIN_SOURCE);

    EXTI_InitStruct.EXTI_Line = ENCODE_PHASEA_EXTI_LINE;
    EXTI_InitStruct.EXTI_LineCmd = ENABLE;
    EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Falling;
    EXTI_Init(&EXTI_InitStruct);

    EXTI_InitStruct.EXTI_Line = ENCODE_PHASEB_EXTI_LINE;
    EXTI_InitStruct.EXTI_LineCmd = ENABLE;
    EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Falling;
    EXTI_Init(&EXTI_InitStruct);

    NVIC_Config();
}

void EXTI9_5_IRQHandler(void)
{


    if (EXTI_GetITStatus(ENCODE_PHASEB_EXTI_LINE) == SET)
    {
        EXTI_ClearITPendingBit(ENCODE_PHASEB_EXTI_LINE);
        if(GPIO_ReadInputDataBit(ENCODE_PHASEA_PORT,ENCODE_PHASEA_PIN) == RESET)
        {
            encode_count++;
        }
    }

    if (EXTI_GetITStatus(ENCODE_PHASEA_EXTI_LINE) == SET)
    {
        EXTI_ClearITPendingBit(ENCODE_PHASEA_EXTI_LINE);
        if(GPIO_ReadInputDataBit(ENCODE_PHASEB_PORT,ENCODE_PHASEB_PIN) == RESET)
        {
            encode_count--;
        }
    }
}

int32_t Get_Encode_Count(void)
{
    int32_t temp = encode_count;
    encode_count = 0;
    return temp;
}


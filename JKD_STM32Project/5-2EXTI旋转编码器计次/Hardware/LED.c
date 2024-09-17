#include "LED.h"
void GPIO_LEDConfig(void)
{
    LED_GPIO_CLOCKCMD(LED_GPIO_CLK,ENABLE);

    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.GPIO_Pin = LED_GPIO_PIN1 | LED_GPIO_PIN2;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;

    GPIO_Init(LED_GPIO_PORT,&GPIO_InitStruct);
}

void LED1_ON(void)
{
    GPIO_ResetBits(LED_GPIO_PORT,LED_GPIO_PIN1);
}
void LED1_OFF(void)
{
    GPIO_SetBits(LED_GPIO_PORT,LED_GPIO_PIN1);
}
void LED1_TURN(void)
{
    if(GPIO_ReadInputDataBit(LED_GPIO_PORT,LED_GPIO_PIN1) == 0)
    {
         GPIO_SetBits(LED_GPIO_PORT,LED_GPIO_PIN1);
    }
    else
    {
        GPIO_ResetBits(LED_GPIO_PORT,LED_GPIO_PIN1);
    }
}

void LED2_ON(void)
{
    GPIO_ResetBits(LED_GPIO_PORT,LED_GPIO_PIN2);
}
void LED2_OFF(void)
{
    GPIO_SetBits(LED_GPIO_PORT,LED_GPIO_PIN2);
}
void LED2_TURN(void)
{
    if(GPIO_ReadInputDataBit(LED_GPIO_PORT,LED_GPIO_PIN2) == 0)
    {
         GPIO_SetBits(LED_GPIO_PORT,LED_GPIO_PIN2);
    }
    else
    {
        GPIO_ResetBits(LED_GPIO_PORT,LED_GPIO_PIN2);
    }
}
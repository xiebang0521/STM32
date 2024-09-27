#include "led_gpio.h"

void LED_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);
	
    GPIO_InitStruct.GPIO_Pin = LED1_GOIO_PIN;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_10MHz;
    GPIO_Init(LED1_GOIO_PORT, &GPIO_InitStruct);

    GPIO_InitStruct.GPIO_Pin = LED2_GOIO_PIN;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_10MHz;
    GPIO_Init(LED2_GOIO_PORT, &GPIO_InitStruct);
}


void LED1ON(void)
{
    GPIO_ResetBits(LED1_GOIO_PORT, LED1_GOIO_PIN);
}

void LED1OFF(void)
{
    GPIO_SetBits(LED1_GOIO_PORT, LED1_GOIO_PIN);
}

void LED1Toggle(void)
{
    if (GPIO_ReadOutputDataBit(LED1_GOIO_PORT, LED1_GOIO_PIN) == LEDON)
    {
        GPIO_ResetBits(LED1_GOIO_PORT, LED1_GOIO_PIN);
    }else
    {
        GPIO_SetBits(LED1_GOIO_PORT, LED1_GOIO_PIN);
    }
}

void LED2ON(void)
{
    GPIO_ResetBits(LED2_GOIO_PORT, LED2_GOIO_PIN);
}

void LED2OFF(void)
{
    GPIO_SetBits(LED2_GOIO_PORT, LED2_GOIO_PIN);
}

void LED2Toggle(void)
{
    if (GPIO_ReadOutputDataBit(LED2_GOIO_PORT, LED2_GOIO_PIN) == LEDON)
    {
        GPIO_ResetBits(LED2_GOIO_PORT, LED2_GOIO_PIN);
    }else
    {
        GPIO_SetBits(LED2_GOIO_PORT, LED2_GOIO_PIN);
    }  
}

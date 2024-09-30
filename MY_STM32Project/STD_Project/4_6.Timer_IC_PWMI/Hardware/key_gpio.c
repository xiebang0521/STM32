#include "key_gpio.h"
#include "SysDelay.h"

void KEY_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);

    GPIO_InitStruct.GPIO_Pin = KEY1_GOIO_PIN;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_Init(KEY1_GOIO_PORT, &GPIO_InitStruct);

    GPIO_InitStruct.GPIO_Pin = KEY2_GOIO_PIN;
    GPIO_Init(KEY2_GOIO_PORT, &GPIO_InitStruct);

}


uint32_t Key_Scan(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
    if (GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == DISABLE)
    {
        Delaynms(10);
        if (GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == DISABLE)
        {
            //等待按键松开
            while (GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == DISABLE);
            return KEY_ON;
        }    
    }

    return KEY_OFF;    
}

#include "KEY.h"
#include "Delay.h"
void  Gpio_Key_Config(void)
{
    KEY1_GPIO_CLOCKCMD(KEY1_GPIO_CLK | KEY2_GPIO_CLK, ENABLE);

    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.GPIO_Pin = KEY1_GPIO_PIN | KEY2_GPIO_PIN;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_Init(KEY1_GPIO_PORT, &GPIO_InitStruct);
}

uint8_t Key_Scan(void)
{
    uint8_t Key_Num = 0;
    if(GPIO_ReadInputDataBit(KEY1_GPIO_PORT,KEY1_GPIO_PIN) == 0)
    {
      
        while (GPIO_ReadInputDataBit(KEY1_GPIO_PORT,KEY1_GPIO_PIN) == 0)
        {
            /* code */
        }
        Key_Num = 1;
    }

    if(GPIO_ReadInputDataBit(KEY2_GPIO_PORT,KEY2_GPIO_PIN) == 0)
    {

        while (GPIO_ReadInputDataBit(KEY2_GPIO_PORT,KEY2_GPIO_PIN) == 0)
        {
            /* code */
        }
        Key_Num = 2;
    }
    return Key_Num;
}

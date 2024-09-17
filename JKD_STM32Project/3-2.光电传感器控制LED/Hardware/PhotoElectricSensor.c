#include "PhotoElectricSensor.h"

void GPIO_PESConfig(void)
{
    GPIO_PES_CLOCKCMD(GPIO_PES_CLK, ENABLE);

    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.GPIO_Pin = GPIO_PES_PIN;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;

    GPIO_Init(GPIO_PES_PORT, &GPIO_InitStruct);
}

uint8_t SCAN_PES(void)
{
    return GPIO_ReadInputDataBit(GPIO_PES_PORT,GPIO_PES_PIN);
}

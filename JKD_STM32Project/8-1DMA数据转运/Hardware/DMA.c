#include "DMA.h"
uint16_t Mysize;
void DMA_Config(uint32_t AddrSrc, uint32_t AddrDes, uint16_t size)
{
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
    Mysize = size;
    DMA_InitTypeDef DMA_InitStrcut;
    DMA_InitStrcut.DMA_BufferSize = size;
    DMA_InitStrcut.DMA_DIR = DMA_DIR_PeripheralSRC;
    DMA_InitStrcut.DMA_M2M = DMA_M2M_Enable;
    DMA_InitStrcut.DMA_MemoryBaseAddr = AddrDes;
    DMA_InitStrcut.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
    DMA_InitStrcut.DMA_MemoryInc = DMA_MemoryInc_Enable;
    DMA_InitStrcut.DMA_Mode = DMA_Mode_Normal;
    DMA_InitStrcut.DMA_PeripheralBaseAddr = AddrSrc;
    DMA_InitStrcut.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
    DMA_InitStrcut.DMA_PeripheralInc = DMA_PeripheralInc_Enable;
    DMA_InitStrcut.DMA_Priority = DMA_Priority_High;
    DMA_Init(DMA1_Channel1, &DMA_InitStrcut);

    DMA_Cmd(DMA1_Channel1, ENABLE);
}

void DMA_Transfer(void)
{
    DMA_Cmd(DMA1_Channel1, DISABLE);
    DMA_SetCurrDataCounter(DMA1_Channel1, Mysize);
    DMA_Cmd(DMA1_Channel1, ENABLE);

    while(DMA_GetFlagStatus(DMA1_FLAG_TC1) == RESET);
    DMA_ClearFlag(DMA1_FLAG_TC1);
}
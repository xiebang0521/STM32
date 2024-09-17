#include "MySPI.h"

void MySPI_W_SS(uint8_t BitValue)
{
    GPIO_WriteBit(GPIOA, GPIO_Pin_4,(BitAction) BitValue);
}

void MySPI_W_MOSI(uint8_t BitValue)
{
    GPIO_WriteBit(GPIOA, GPIO_Pin_7,(BitAction) BitValue);
}

void MySPI_W_SCK(uint8_t BitValue)
{
    GPIO_WriteBit(GPIOA, GPIO_Pin_5,(BitAction) BitValue);
}

uint8_t MySPI_R_MISO(void)
{
   return GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_6);
}


void MySPI_Init(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_7 | GPIO_Pin_5 | GPIO_Pin_4;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStruct);

    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_6;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStruct);

    MySPI_W_SS(1);
    MySPI_W_SCK(0);
}

void MySPI_Start(void)
{
    MySPI_W_SS(0);
}

void MySPI_Stop(void)
{
    MySPI_W_SS(1);
}

uint8_t MySPI_SwapByte(uint8_t ByteSend)
{
    uint8_t ByteReceive = 0X00;
    uint8_t i = 0;
    for(i = 0 ;i < 8; i++)
    {
        MySPI_W_MOSI(ByteSend & (0x80 >> i));
        MySPI_W_SCK(1);
        if (MySPI_R_MISO() == 1)
        {
            ByteReceive |= (0x80 >> i);
        }
        MySPI_W_SCK(0);
    }
    return ByteReceive;
}

uint8_t MySPI_SwapByte1(uint8_t ByteSend)
{
    uint8_t i = 0;
    for(i = 0 ;i < 8; i++)
    {
        MySPI_W_MOSI(ByteSend & 0x80);
        ByteSend <<= 0x01;
        MySPI_W_SCK(1);
        if (MySPI_R_MISO() == 1)
        {
            ByteSend |= 0x01;
        }
        MySPI_W_SCK(0);
    }
    return ByteSend;
}

// SPI1 CPOL = 0 CPHA = 1
uint8_t MySPI_SwapByte2(uint8_t ByteSend)
{
    uint8_t i = 0;
    for(i = 0 ;i < 8; i++)
    {
        MySPI_W_SCK(1);
        MySPI_W_MOSI(ByteSend & 0x80);
        ByteSend <<= 0x01;
        MySPI_W_SCK(0);
        if (MySPI_R_MISO() == 1)
        {
            ByteSend |= 0x01;
        }
    }
    return ByteSend;
}


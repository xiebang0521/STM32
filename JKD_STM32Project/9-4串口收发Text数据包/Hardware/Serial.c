#include "Serial.h"
#include <stdio.h>
#include <stdarg.h>

uint8_t Serial_RxFlag;
char Serial_RxPacket[100];
void NVIC_Config(void)
{
    NVIC_SetPriorityGrouping(NVIC_PriorityGroup_2);
    NVIC_InitTypeDef NVIC_InitStruct;
    NVIC_InitStruct.NVIC_IRQChannel = USART1_IRQn;
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
    NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;
    NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;
    NVIC_Init(&NVIC_InitStruct);
}

void Serial_Init(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);

    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStruct);

    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_10;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStruct);

    USART_InitTypeDef USART_InitStruct;
    USART_InitStruct.USART_BaudRate = 9600;
    USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStruct.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
    USART_InitStruct.USART_Parity = USART_Parity_No;
    USART_InitStruct.USART_StopBits = USART_StopBits_1;
    USART_InitStruct.USART_WordLength = USART_WordLength_8b;
    USART_Init(USART1, &USART_InitStruct);
    USART_ITConfig(USART1,USART_IT_RXNE, ENABLE);
    NVIC_Config();

    USART_Cmd(USART1, ENABLE);


}

void Serial_SendByte(uint8_t Data)
{
    USART_SendData(USART1, Data);
    while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);

}

void Serial_SendArray(uint8_t* Array,uint16_t Length)
{
    for(uint16_t i = 0; i < Length; i++)
    {
        Serial_SendByte(Array[i]);
    }
}

void Serial_SendString(char* String)
{
    while (*String != '\0')
    {
        Serial_SendByte((*String));
        String++;
    }
}

uint32_t Serial_Pow(uint32_t X, uint32_t Y)
{
    uint32_t Result = 1;
    while (Y--)
    {
        Result *= X;
    }
    return Result;
}

void Serial_SendNumber(uint32_t Number,uint32_t Length)
{
    uint8_t i;
    for(i = 0; i < Length; i++)
    {
        Serial_SendByte(Number / Serial_Pow(10, Length - i - 1) % 10 + '0');
    }
}

int fputc(int ch, FILE *f)
{
    Serial_SendByte(ch);
    return ch;
}

void Serial_Printf(char* format, ...)
{
    char String[100];
    va_list arg;
    va_start(arg, format);
    vsprintf(String, format, arg);
    va_end(arg);
    Serial_SendString(String);
}


void USART1_IRQHandler(void)
{
    static uint8_t RxState = 0;
    static uint8_t pRxPacket = 0;
    if(USART_GetFlagStatus(USART1, USART_IT_RXNE) == SET)
    {
        uint8_t RxData = USART_ReceiveData(USART1);
        if (RxState == 0)
        {
            if(RxData == '@' && Serial_RxFlag == 0)
            {
                 RxState = 1;
            }
        }
        else if (RxState == 1)
        {
			if (RxData == '\r')
            {
                RxState = 2;
                pRxPacket = 0;
			}
			else
			{
				Serial_RxPacket[pRxPacket] = RxData;
				pRxPacket++;
			}


        }
        else if (RxState == 2)
        {
            if (RxData == '\n')
            {
                RxState = 0;
				Serial_RxPacket[pRxPacket] = '\0';
                Serial_RxFlag = 1;
            }
        }
           
      USART_ClearITPendingBit(USART1, USART_IT_RXNE);
    }
}

uint8_t Serial_GetRxFlag(void)
{
    if (Serial_RxFlag == 1)
    {
      Serial_RxFlag = 0;
      return 1;
    }
    return 0;  
}




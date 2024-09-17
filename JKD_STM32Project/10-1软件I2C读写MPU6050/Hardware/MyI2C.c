#include "MyI2C.h"
#include "Delay.h"

void MyI2C_W_SCL(uint8_t BitValue)
{
    GPIO_WriteBit(SCL_PORT, SCL_PIN, (BitAction)BitValue);
    Delay_us(10);
}

void MyI2C_W_SDA(uint8_t BitValue)
{
    GPIO_WriteBit(SDA_PORT, SDA_PIN, (BitAction)BitValue);
    Delay_us(10);
}

uint8_t MyI2C_R_SDA(void)
{
    uint8_t BitValue;
    BitValue = GPIO_ReadInputDataBit(SDA_PORT, SDA_PIN);
    Delay_us(10);
    return BitValue;
}
void MyI2C_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_OD;
    GPIO_InitStruct.GPIO_Pin = SCL_PIN | SDA_PIN;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;

    GPIO_Init(SCL_PORT, &GPIO_InitStruct);

    GPIO_SetBits(SCL_PORT, SCL_PIN | SDA_PIN);
}

void MyI2C_Start(void)
{
    MyI2C_W_SDA(1);
    MyI2C_W_SCL(1);

    MyI2C_W_SDA(0);
    MyI2C_W_SCL(0);
}

void MyI2C_Stop(void)
{
    MyI2C_W_SDA(0);
    MyI2C_W_SCL(1);
    MyI2C_W_SDA(1);
}	

void MyI2C_SendByte(uint8_t Byte)
{
    for(uint8_t i = 0; i < 8; i++)
    {
        MyI2C_W_SDA(Byte & (0X80 >> i));
        MyI2C_W_SCL(1);
        MyI2C_W_SCL(0);
    }
}

uint8_t MyI2C_ReceiveByte1(void)
{
    MyI2C_W_SDA(1);
    uint8_t Value = 0;
    uint8_t i ;
    for(i = 0; i < 8; i++)
    {
        MyI2C_W_SCL(1);
        Value |= (MyI2C_R_SDA() << (0x80 >> i));
        MyI2C_W_SCL(0);
    }
    return Value;
}

uint8_t MyI2C_ReceiveByte(void)
{

    uint8_t byte = 0;
    uint8_t i ;
    MyI2C_W_SDA(1);
    for(i = 0; i < 8; i++)
    {
        MyI2C_W_SCL(1);
        if(MyI2C_R_SDA() == 1)
        {
            byte |= (0x80 >> i);
        }
        MyI2C_W_SCL(0);
    }
    return byte;
}

void MyI2C_SendAck(uint8_t AckBit)
{
    MyI2C_W_SDA(AckBit);
    MyI2C_W_SCL(1);
    MyI2C_W_SCL(0);
}

uint8_t MyI2C_ReceiveAck(void)
{

    uint8_t AckBit;
    MyI2C_W_SDA(1);
    MyI2C_W_SCL(1);
    AckBit = MyI2C_R_SDA(); 
    MyI2C_W_SCL(0);

    return AckBit;
}

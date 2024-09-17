#include "MPU6050.h"
#include "MPU6050_Reg.h"
void MPU6050_WriteReg(uint8_t RegAddress, uint8_t Data)
{
	I2C_GenerateSTART(I2C2, ENABLE);
    while(I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_MODE_SELECT) != SUCCESS);
    I2C_Send7bitAddress(I2C2, SLAVE_ADDRESS,I2C_Direction_Transmitter);
    while(I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED) != SUCCESS);
    I2C_SendData(I2C2, RegAddress);
    while(I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_BYTE_TRANSMITTING) != SUCCESS);
    
	I2C_SendData(I2C2, Data);
    while(I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_BYTE_TRANSMITTED) != SUCCESS);
    I2C_GenerateSTOP(I2C2, ENABLE);
    
//    MyI2C_Start();
//    MyI2C_SendByte(SLAVE_ADDRESS);
//    MyI2C_ReceiveAck();
//    MyI2C_SendByte(RegAddress);
//    MyI2C_ReceiveAck();
//    MyI2C_SendByte(Data);
//    MyI2C_ReceiveAck();
//    MyI2C_Stop(); 
}

uint8_t MPU6050_ReadReg(uint8_t RegAddress)
{
    uint8_t Data;
    I2C_GenerateSTART(I2C2, ENABLE);
    while(I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_MODE_SELECT) != SUCCESS);
    I2C_Send7bitAddress(I2C2, SLAVE_ADDRESS,I2C_Direction_Transmitter);
    while(I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED) != SUCCESS);
    I2C_SendData(I2C2, RegAddress);
    while(I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_BYTE_TRANSMITTED) != SUCCESS);
    I2C_GenerateSTART(I2C2, ENABLE);
    while(I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_MODE_SELECT) != SUCCESS);

    I2C_Send7bitAddress(I2C2, SLAVE_ADDRESS,I2C_Direction_Receiver);
    while(I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED) != SUCCESS);
    I2C_AcknowledgeConfig(I2C2, DISABLE);
    I2C_GenerateSTOP(I2C2, ENABLE);

    while(I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_BYTE_RECEIVED) != SUCCESS);
    Data = I2C_ReceiveData(I2C2);
    I2C_AcknowledgeConfig(I2C2, ENABLE);
//    MyI2C_Start();
//    MyI2C_SendByte(SLAVE_ADDRESS);
//    MyI2C_ReceiveAck();
//    MyI2C_SendByte(RegAddress);
//    MyI2C_ReceiveAck();
//    MyI2C_Start();
//    MyI2C_SendByte(SLAVE_ADDRESS | 0x01);
//    MyI2C_ReceiveAck();
//    Data = MyI2C_ReceiveByte();
//    MyI2C_SendAck(1);
//    MyI2C_Stop(); 
    return Data;
}

void MPU6050_Init(void)
{
    //MyI2C_Init();

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C2, ENABLE);

    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_OD;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStruct);

    I2C_InitTypeDef I2C_InitStruct;
    I2C_InitStruct.I2C_Ack = I2C_Ack_Enable;
    I2C_InitStruct.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
    I2C_InitStruct.I2C_ClockSpeed = 50000;
    I2C_InitStruct.I2C_DutyCycle = I2C_DutyCycle_2;
    I2C_InitStruct.I2C_Mode = I2C_Mode_I2C;
    I2C_InitStruct.I2C_OwnAddress1 = 0x00;
    I2C_Init(I2C2, &I2C_InitStruct);
	
	I2C_Cmd(I2C2, ENABLE);
    // 解除睡眠，使用陀螺仪时钟
    MPU6050_WriteReg(MPU6050_PWR_MGMT_1, 0x01);
    // 六轴均不待机
    MPU6050_WriteReg(MPU6050_PWR_MGMT_2, 0x00);
    // 采样分频为10
    MPU6050_WriteReg(MPU6050_SMPLRT_DIV, 0x09);
    // 滤波参数给最大
    MPU6050_WriteReg(MPU6050_CONFIG, 0x06);
    // 设置陀螺仪为最大量程
    MPU6050_WriteReg(MPU6050_GYRO_CONFIG, 0x18);
    // 设置加速度计为最大量程
    MPU6050_WriteReg(MPU6050_ACCEL_CONFIG, 0x18);
}


void MPU6050_GetData(int16_t* AccX, int16_t* AccY, int16_t* AccZ,
                    int16_t* GyroX, int16_t* GyroY, int16_t* GyroZ)
{
    uint8_t DataH, DataL;

    DataH = MPU6050_ReadReg(MPU6050_ACCEL_XOUT_H);
    DataL = MPU6050_ReadReg(MPU6050_ACCEL_XOUT_L);
    *AccX = (DataH << 8) | DataL;
    
    DataH = MPU6050_ReadReg(MPU6050_ACCEL_YOUT_H);
    DataL = MPU6050_ReadReg(MPU6050_ACCEL_YOUT_L);
    *AccY = (DataH << 8) | DataL;

    DataH = MPU6050_ReadReg(MPU6050_ACCEL_ZOUT_H);
    DataL = MPU6050_ReadReg(MPU6050_ACCEL_ZOUT_L);
    *AccZ = (DataH << 8) | DataL;

    DataH = MPU6050_ReadReg(MPU6050_GYRO_XOUT_H);
    DataL = MPU6050_ReadReg(MPU6050_GYRO_XOUT_L);
    *GyroX = (DataH << 8) | DataL;

    DataH = MPU6050_ReadReg(MPU6050_GYRO_YOUT_H);
    DataL = MPU6050_ReadReg(MPU6050_GYRO_YOUT_L);
    *GyroY = (DataH << 8) | DataL;

    DataH = MPU6050_ReadReg(MPU6050_GYRO_ZOUT_H);
    DataL = MPU6050_ReadReg(MPU6050_GYRO_ZOUT_L);
    *GyroZ = (DataH << 8) | DataL;
    
}

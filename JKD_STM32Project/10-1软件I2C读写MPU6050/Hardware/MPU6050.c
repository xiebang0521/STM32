#include "MPU6050.h"
#include "MyI2C.h"
#include "MPU6050_Reg.h"
void MPU6050_WriteReg(uint8_t RegAddress, uint8_t Data)
{
    MyI2C_Start();
    MyI2C_SendByte(SLAVE_ADDRESS);
    MyI2C_ReceiveAck();
    MyI2C_SendByte(RegAddress);
    MyI2C_ReceiveAck();
    MyI2C_SendByte(Data);
    MyI2C_ReceiveAck();
    MyI2C_Stop(); 
}

uint8_t MPU6050_ReadReg(uint8_t RegAddress)
{
    uint8_t Data;
    MyI2C_Start();
    MyI2C_SendByte(SLAVE_ADDRESS);
    MyI2C_ReceiveAck();
    MyI2C_SendByte(RegAddress);
    MyI2C_ReceiveAck();
    MyI2C_Start();
    MyI2C_SendByte(SLAVE_ADDRESS | 0x01);
    MyI2C_ReceiveAck();
    Data = MyI2C_ReceiveByte();
    MyI2C_SendAck(1);
    MyI2C_Stop(); 
    return Data;
}

void MPU6050_Init(void)
{
    MyI2C_Init();
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

#include "Servo.h"

void Servo_Config(void)
{
    PWM_Config();
}

void Servo_SetAngle(float Angle)
{
    PWM_SetCompare1(Angle / 180 * 2000 + 500);
}
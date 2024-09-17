#include "Servo.h"

void Servo_Config(void)
{
    PWM_Config();
}

void Servo_SetAngle(float Angle)
{
    PWM_SetCompare2(Angle / 180 * 2000 + 500);
}

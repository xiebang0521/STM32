#include "Servo.h"

void Servo_Init(void)
{
    Timer_Init();
}

void Servo_SetAngle(float Angle)
{
    Timer_SetCompare2((Angle / 180) * 2000 + 500);
}

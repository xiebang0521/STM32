#ifndef __MOTOR_H
#define __MOTOR_H

#include "stm32f10x.h"
#include "PWM.h"
void Motor_Config(void);
void Motor_SetSpeed(uint16_t speed);
#endif

#include "Morto.h"

void Morto_Init(void)
{
    Timer_Init();
}

void Morto_SetSpeed(uint16_t speed)
{
    Timer_SetCompare3(speed);
}

void PWM_SetPresacler(uint16_t Presacler)
{
  
   Timer_PrescalerConfig(Presacler);
}

#ifndef __ENCODE_H
#define __ENCODE_H

#include "stm32f10x.h"
void Encoder_Init(void);
int16_t Encoder_Get(void);
#endif

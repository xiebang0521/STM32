#ifndef __ENCODECOUNT_H
#define __ENCODECOUNT_H

#include "stm32f10x.h"
void Encoder_Init(void);
int16_t Encoder_Get(void);
#endif
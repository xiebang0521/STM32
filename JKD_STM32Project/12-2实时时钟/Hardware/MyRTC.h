#ifndef __MYRTC_H
#define __MYRTC_H

#include "stm32f10x.h"
#include "time.h"
typedef struct 
{
    uint16_t year;
    uint16_t month;
    uint16_t day;
    uint16_t hour;
    uint16_t min;
    uint16_t s;
}MyRTCTime;

extern MyRTCTime Time1; 
void MyRTC_Init(void);
void MyRTC_SetTime(void);
void MyRTC_ReadTime(void);
#endif

#include "MyRTC.h"

MyRTCTime Time1 = {2023, 1, 1, 23, 59, 55};

void Time_Init(uint16_t year, uint16_t month, uint16_t day, uint16_t hour, uint16_t min, uint16_t s)
{
    Time1.year = year;
    Time1.month = month;
    Time1.day  = day;
    Time1.hour = hour;
    Time1.min = min;
    Time1.s = s;
}
void Time_Init1(uint16_t year, uint16_t month, uint16_t day, uint16_t hour, uint16_t min, uint16_t s)
{
    Time1.year = year;
    Time1.month = month;
    Time1.day  = day;
    Time1.hour = hour;
    Time1.min = min;
    Time1.s = s;
}

  
void MyRTC_Init(void)
{
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR, ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_BKP, ENABLE);

    PWR_BackupAccessCmd(ENABLE);

    if (BKP_ReadBackupRegister(BKP_DR1) != 0xa5a5)
    {
        RCC_LSEConfig(RCC_LSE_ON);
        //等待时间准备好
        while(RCC_GetFlagStatus(RCC_FLAG_LSERDY) != SET);

        RCC_RTCCLKConfig(RCC_RTCCLKSource_LSE);//选择时钟
        RCC_RTCCLKCmd(ENABLE);//使能时钟

        //等带时钟同步
        RTC_WaitForSynchro();

        //等待上一次操作完成
        RTC_WaitForLastTask();

        RTC_SetPrescaler(32768 - 1);

        RTC_WaitForLastTask();

        MyRTC_SetTime();

        BKP_WriteBackupRegister(BKP_DR1, 0xa5a5);
    }
    else
    {
        RTC_WaitForLastTask();
        RTC_WaitForLastTask();
    }
    


}

void MyRTC_SetTime(void)
{
    time_t time_cnt;
    struct tm time_date;

    time_date.tm_year = Time1.year - 1900;
    time_date.tm_mon = Time1.month - 1;
    time_date.tm_mday = Time1.day;
    time_date.tm_hour = Time1.hour;
    time_date.tm_min = Time1.min;
    time_date.tm_sec = Time1.s;

    time_cnt = mktime(&time_date);
    RTC_SetCounter(time_cnt);
    RTC_WaitForLastTask();
}

void MyRTC_ReadTime(void)
{
    time_t time_cnt;
    struct tm time_date;

    time_cnt = RTC_GetCounter();

    time_date = *localtime(&time_cnt);
    Time_Init1(time_date.tm_year + 1900, time_date.tm_mon + 1, time_date.tm_mday,
              time_date.tm_hour, time_date.tm_min, time_date.tm_sec);
}

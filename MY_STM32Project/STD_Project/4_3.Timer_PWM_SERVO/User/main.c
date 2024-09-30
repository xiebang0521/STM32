#include "stm32f10x.h"
#include "SysDelay.h"
#include "OLED.h"
#include "Servo.h"
#include "key_gpio.h"
float Angle;
int main()	
{

	OLED_Init();
	OLED_Clear();
	KEY_GPIO_Config();
	Servo_Init();
	OLED_ShowString(1,1,"Angle:");
	Servo_SetAngle(Angle);
	while(1)
	{	
		if (KEY_ON == Key_Scan(KEY1_GOIO_PORT,KEY1_GOIO_PIN))
		{
			Angle += 10;
			if(Angle >= 180)
			{
				Angle = 0;
			}

			Servo_SetAngle(Angle);
		}
			OLED_ShowNum(1,7,Angle,3);
	}
	
}

#include "servo.h"




//void set_duty(float duty,uint8_t channel)  //设置占空比
//{
//	uint32_t  CompareValue;
//	CompareValue=32000-32000*duty;
//	if (channel==0)
//   DL_TimerA_setCaptureCompareValue(PWM_0_INST, CompareValue, DL_TIMER_CC_0_INDEX);
//	else if (channel==1)
//   DL_TimerA_setCaptureCompareValue(PWM_0_INST, CompareValue, DL_TIMER_CC_1_INDEX);
//}
float b;

void set_angle(float angle,uint8_t channel)//设置舵机角度
{
  b=2000-(angle/270*200+50);
	if (channel==0)
   DL_TimerG_setCaptureCompareValue(PWM_SERVO_INST, b, GPIO_PWM_SERVO_C0_IDX);
	else if (channel==1)
   DL_TimerG_setCaptureCompareValue(PWM_SERVO_INST, b, GPIO_PWM_SERVO_C1_IDX);
	
}





#include "motor.h"
#include <stdio.h>
#include <stdlib.h>
#include "pid.h"

//速度范围0到100
uint32_t  CompareValue;
float left_speed;
float right_speed;
float vision_left;
float vision_right;
uint8_t temp;
extern int theta_org;
PidTypeDef motor_left_pid;
PidTypeDef motor_right_pid;


void pid_motor_init(void)
{
	PID_Init(&motor_left_pid,PID_DELTA,6,1,1,70,70,70);
	PID_Init(&motor_right_pid,PID_DELTA,6,1,1,70,70,70);
}
void set_speed(float speed,uint8_t channel)
{
	CompareValue=3199*speed/100;
	if (channel==0) 
   DL_TimerG_setCaptureCompareValue(PWM_MOTOR_INST, CompareValue, GPIO_PWM_MOTOR_C0_IDX);
	else if (channel==1)
   DL_TimerG_setCaptureCompareValue(PWM_MOTOR_INST, CompareValue, GPIO_PWM_MOTOR_C1_IDX);
}
//电机编码器数据解算
uint8_t gpioA; 
uint32_t gEncoderCount1;
uint32_t gEncoderCount2;
void GROUP1_IRQHandler(void)
{
    //获取中断信号
    gpioA = DL_GPIO_getEnabledInterruptStatus(GPIOA,
    GPIO_MOTOR_PIN_1_PIN | GPIO_MOTOR_PIN_0_PIN);
 
    //如果是GPIO_EncoderA_PIN_0_PIN产生的中断
	//motor1
    if((gpioA & GPIO_MOTOR_PIN_0_PIN) == GPIO_MOTOR_PIN_0_PIN)
    {
        //Pin0上升沿，看Pin1的电平，为低电平则判断为反转，高电平判断为正转
        if(!DL_GPIO_readPins(GPIOA,GPIO_MOTOR_PIN_1_PIN))//P1为低电平
        {
            gEncoderCount1--;
        }
        else//P1为高电平
        {
            gEncoderCount1++;
        }
    }
    
		//motor2
    else if((gpioA & GPIO_MOTOR_PIN_1_PIN) == GPIO_MOTOR_PIN_1_PIN)
    {
        //Pin1上升沿
        if(!DL_GPIO_readPins(GPIOA,GPIO_MOTOR_PIN_0_PIN))//P0为低电平
        {
            gEncoderCount2++;
        }
        else//P1为高电平
        {
            gEncoderCount2--;
        }
    }
    
    //最后清除中断标志位
    DL_GPIO_clearInterruptStatus(GPIOA, GPIO_MOTOR_PIN_1_PIN|GPIO_MOTOR_PIN_0_PIN);
}


void motor_coutrol(enum	MODE mode,uint8_t motor_status)
{
 
//	switch(mode)
//	{
//		case ONLY:	
//		{//前进
//	if(motor_status==1)
//	{
//		DL_GPIO_setPins(MOTOR_STBY_PORT,MOTOR_STBY_PIN);
//		DL_GPIO_setPins(MOTOR_AIN1_PORT,MOTOR_AIN1_PIN);
//		DL_GPIO_clearPins(MOTOR_AIN2_PORT,MOTOR_AIN2_PIN);
//		DL_GPIO_setPins(MOTOR_BIN1_PORT,MOTOR_BIN1_PIN);
//		DL_GPIO_clearPins(MOTOR_BIN2_PORT,MOTOR_BIN2_PIN);
//	}
//	//后退
//	if(motor_status==2)
//	{
//		DL_GPIO_setPins(MOTOR_STBY_PORT,MOTOR_STBY_PIN);
//		DL_GPIO_clearPins(MOTOR_AIN1_PORT,MOTOR_AIN1_PIN);
//		DL_GPIO_setPins(MOTOR_AIN2_PORT,MOTOR_AIN2_PIN);
//		DL_GPIO_clearPins(MOTOR_BIN1_PORT,MOTOR_BIN1_PIN);
//		DL_GPIO_setPins(MOTOR_BIN2_PORT,MOTOR_BIN2_PIN);
//	}
//	 //向左
//	if(motor_status==3)
//	{
//		DL_GPIO_setPins(MOTOR_STBY_PORT,MOTOR_STBY_PIN);
//		DL_GPIO_clearPins(MOTOR_AIN1_PORT,MOTOR_AIN1_PIN);
//		DL_GPIO_setPins(MOTOR_AIN2_PORT,MOTOR_AIN2_PIN);
//		DL_GPIO_setPins(MOTOR_BIN1_PORT,MOTOR_BIN1_PIN);
//		DL_GPIO_clearPins(MOTOR_BIN2_PORT,MOTOR_BIN2_PIN);
//	}
//	 //向右
//	if(motor_status==4)
//	{
//		DL_GPIO_setPins(MOTOR_STBY_PORT,MOTOR_STBY_PIN);
//		DL_GPIO_setPins(MOTOR_AIN1_PORT,MOTOR_AIN1_PIN);
//		DL_GPIO_clearPins(MOTOR_AIN2_PORT,MOTOR_AIN2_PIN);
//		DL_GPIO_clearPins(MOTOR_BIN1_PORT,MOTOR_BIN1_PIN);
//		DL_GPIO_setPins(MOTOR_BIN2_PORT,MOTOR_BIN2_PIN);
//	}
//	break;
//}
//	case Grayscale_Sensor:
//	{
//		left_speed=0;
//		right_speed=0;
//		DL_GPIO_setPins(MOTOR_STBY_PORT,MOTOR_STBY_PIN);
//		DL_GPIO_clearPins(MOTOR_AIN1_PORT,MOTOR_AIN1_PIN);
//		DL_GPIO_setPins(MOTOR_AIN2_PORT,MOTOR_AIN2_PIN);
//		DL_GPIO_clearPins(MOTOR_BIN1_PORT,MOTOR_BIN1_PIN);
//		DL_GPIO_setPins(MOTOR_BIN2_PORT,MOTOR_BIN2_PIN);
//		
//		temp = DL_GPIO_readPins(Grayscale_Sensor_PORT,Grayscale_Sensor_R1_PIN); 
//		
//		 if(!DL_GPIO_readPins(Grayscale_Sensor_PORT,Grayscale_Sensor_M_PIN)&&DL_GPIO_readPins(Grayscale_Sensor_PORT,Grayscale_Sensor_L1_PIN))
//		{
//			right_speed=55;
//			left_speed=20;
//		}
//		else if(DL_GPIO_readPins(Grayscale_Sensor_PORT,Grayscale_Sensor_M_PIN)&&DL_GPIO_readPins(Grayscale_Sensor_PORT,Grayscale_Sensor_L1_PIN))
//		{
//			right_speed=55;
//			left_speed =20;	
//		}
//		else if(DL_GPIO_readPins(Grayscale_Sensor_PORT,Grayscale_Sensor_M_PIN)&&DL_GPIO_readPins(Grayscale_Sensor_PORT,Grayscale_Sensor_R1_PIN))
//		{			
//			left_speed=55; 
//			right_speed=20;
//		}
//		else if(!DL_GPIO_readPins(Grayscale_Sensor_PORT,Grayscale_Sensor_M_PIN)&&DL_GPIO_readPins(Grayscale_Sensor_PORT,Grayscale_Sensor_R1_PIN))
//		{			
//			left_speed=55; 
//			right_speed=20;
//		}
//		else if(DL_GPIO_readPins(Grayscale_Sensor_PORT,Grayscale_Sensor_M_PIN)&&!DL_GPIO_readPins(Grayscale_Sensor_PORT,Grayscale_Sensor_R1_PIN)&&!DL_GPIO_readPins(Grayscale_Sensor_PORT,Grayscale_Sensor_L1_PIN))
//		{			
//			left_speed=30; 
//			right_speed=30;
//		}
//		else
//		{
//			left_speed=20; 
//			right_speed=20 ;
//			
//		}		

//		set_speed(left_speed,0);        //PA13
//		set_speed(right_speed,1);       //PA12
//		break;
//	 
//	}		
// 	 case vision:
//	 {
		DL_GPIO_setPins(MOTOR_STBY_PORT,MOTOR_STBY_PIN);
		DL_GPIO_clearPins(MOTOR_AIN1_PORT,MOTOR_AIN1_PIN);
		DL_GPIO_setPins(MOTOR_AIN2_PORT,MOTOR_AIN2_PIN);
		DL_GPIO_clearPins(MOTOR_BIN1_PORT,MOTOR_BIN1_PIN);
		DL_GPIO_setPins(MOTOR_BIN2_PORT,MOTOR_BIN2_PIN);
	 if (theta_org>0)
	 {
		vision_left=0;
		vision_right=theta_org;
	 }
	 else if (theta_org<0)
	 {
	  vision_left=-theta_org;
		vision_right=0;
	 }
	 else if (theta_org==0)
	 {
	  vision_left=10 ;
		vision_right=10;
	 }
	 else 
	 {
		vision_left=15;
		vision_right=15;
	 }
//	 left_speed=(50);
//	 right_speed=(50);

	set_speed(vision_left,1);        //PA13
	set_speed(vision_right,0);       //PA12
//	set_speed(50,0);        //PA13
//	set_speed(50,1);       //PA12
// }

//	 break;
//	 default:
//	 break;

//	
//}
}                                 


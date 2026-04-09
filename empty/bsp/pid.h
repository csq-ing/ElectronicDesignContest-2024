#include "ti_msp_dl_config.h"
#ifndef PID_H
#define PID_H
#define FILTER_BUF_LEN		5
enum PID_MODE
{
    PID_POSITION ,
    PID_DELTA
};

typedef struct
{
    uint8_t mode;
    //PID 三参数
    float Kp;
    float Ki;
    float Kd;

    float max_out;  //最大输出
    float max_iout; //最大积分输出

    float set;
    float fdb;

    float out;
    float Pout;
    float Iout;
    float Dout;
    float Dbuf[3];  //微分项 0最新 1上一次 2上上次
    float error[3]; //误差项 0最新 1上一次 2上上次
	
	  float dead_line;

} PidTypeDef;
float PID_Calc(PidTypeDef *pid, float ref, float set);
void PID_Init(PidTypeDef *pid, uint8_t mode,float Kp,float Ki,float Kd, float max_out, float max_iout, float deadline);


#endif



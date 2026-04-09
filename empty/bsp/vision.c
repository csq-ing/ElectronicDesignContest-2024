#include "vision.h"
//int8_t R2;
//int8_t R1;
//int8_t L1;
//int8_t L2;


// union {
//    int16_t data_vision;
//    uint8_t data[2];
//  } kb;
 
unsigned char OpenMV_Buf;
int theta_org,rho_org;

void Data_processing_for_car_tracking(uint8_t data)
{
    /* 局部静态变量：接收缓存 */
    static uint8_t RxBuffer[10];
    /* 数据长度 *//* 数据数组下标 */
    static uint8_t  data_cnt = 0;
    /* 接收状态 */
    static uint8_t state = 0;
    /* 帧头1 */
    if(state==0&&data==0xAA)
    {
        state=1;
    }
    /* 帧头2 */
    else if(state==1&&data==0xBB)
    {
        state=2;
        data_cnt = 0;
    }
    /* 接收数据租 */
    else if(state==2)
    {
        RxBuffer[data_cnt++]=data;
        if(data_cnt>=8)
        {
            state = 0; 
            rho_org   = (int)((RxBuffer[0]<<24) | (RxBuffer[1]<<16) | (RxBuffer[2]<<8) | (RxBuffer[3]));  
            theta_org = (int)((RxBuffer[4]<<24) | (RxBuffer[5]<<16) | (RxBuffer[6]<<8) | (RxBuffer[7]));            
//            for(int i=0;i<8;i++) printf("%d",RxBuffer[i]);
//            printf("\n\n\n\n");
        }
    }
    /* 若有错误重新等待接收帧头 */
    else
        state = 0;
}

 
void Data_processing_for_gimble_tracking(uint8_t data)
{
	
	
	
}

	
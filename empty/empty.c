/*
 * Copyright (c) 2021, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "ti_msp_dl_config.h"
#include "oled.h"
#include "timer.h"
#include "vision.h"
extern uint32_t gEncoderCount1;
extern uint32_t gEncoderCount2;
int speed1;
int speed2;

int main(void)
 {

    SYSCFG_DL_init();
		NVIC_ClearPendingIRQ(UART_BLUETOOTH_INST_INT_IRQN);

		NVIC_EnableIRQ(TIMER_0_INST_INT_IRQN);
		NVIC_EnableIRQ(UART_BLUETOOTH_INST_INT_IRQN);
  	NVIC_EnableIRQ(UART_VISION_INST_INT_IRQN);
	  NVIC_EnableIRQ(GPIO_MOTOR_INT_IRQN);


	  DL_TimerG_startCounter(PWM_SERVO_INST);
	  DL_TimerG_startCounter(PWM_MOTOR_INST);
	  DL_TimerG_startCounter(TIMER_0_INST);
//	 	DL_TimerA_startCounter(CAPTURE_MOTORA_INST);
//	  DL_TimerA_startCounter(CAPTURE_MOTORB_INST);


//    
//    OLED_Init();
//    OLED_CLS();
//    OLED_ShowStr(10,0,(unsigned char*) "HELLO WORLD",2);
//    OLED_ShowStr(4,2,(unsigned char*) "theta_org",2);
//    OLED_ShowStr(0,4,(unsigned char*) "DATE 2024-4-14",2);
    while (1)
     {
			 	 DL_GPIO_clearPins(GPIO_GRP_0_PORT,GPIO_GRP_0_PIN_2_PIN);

			 
//        /* 每次获取完计数值后清零，则可获得以执行周期为单位的速度值 */
//        speed1 = gEncoderCount1;
//        gEncoderCount1 = 0;
//        delay_cycles(320000);
//			 
//				speed2 = gEncoderCount2;
//				gEncoderCount2 = 0;
//				delay_cycles(320000);
			 
     }
}




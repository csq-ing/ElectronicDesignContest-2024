#include "timer.h"
#include "motor.h"

 int a=0;
void  TIMER_0_INST_IRQHandler(void)
{  
//	  DL_GPIO_togglePins(LED_PORT,LED_PIN_16_PIN);
//    a++;
//	set_angle(50,0);
//	set_angle(50,1);
  motor_coutrol(1,vision);
	
}



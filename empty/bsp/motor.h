#ifndef _MOTOR_H
#define _MOTOR_H

#include "ti_msp_dl_config.h"
#include "vision.h"
enum
MODE{
	ONLY=1,
	Bluetooth,
	vision,
 Grayscale_Sensor
};
void motor_coutrol(enum	MODE mode,uint8_t motor_status);	

#endif

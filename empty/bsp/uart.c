#include "uart.h"
#include "vision.h"

uint8_t data_bluetooth;
uint8_t data_vision;
void UART_BLUETOOTH_INST_IRQHandler(void)
{
	data_bluetooth=DL_UART_Main_receiveData (UART_BLUETOOTH_INST);

		DL_UART_Main_transmitData(UART_BLUETOOTH_INST,data_bluetooth);
		DL_UART_Main_transmitData(UART_BLUETOOTH_INST,1);

}	


void UART_VISION_INST_IRQHandler(void)
{
	
	data_vision=DL_UART_Main_receiveData (UART_VISION_INST);
	Data_processing_for_car_tracking(data_vision);

}	




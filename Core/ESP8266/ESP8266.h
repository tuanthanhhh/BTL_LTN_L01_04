
#ifndef ESP8266_H_
#define ESP8266_H_

#include "stm32f1xx_hal.h"
#include <stdio.h>
#include <string.h>

extern UART_HandleTypeDef huart1;

void UART_SendData(int temperature, int humidity);

#endif /* ESP8266_H_ */

/*
 * SENSOR.h
 *
 *  Created on: Apr 29, 2024
 *      Author: LE TUAN THANH
 */

#ifndef SENSOR_SENSOR_H_
#define SENSOR_SENSOR_H_
#include "stm32f1xx_hal.h"

void adc_Init(ADC_HandleTypeDef *hadc);
void read_sensor(void);
float get_Temperature();
float get_Humidity();


#endif /* SENSOR_SENSOR_H_ */

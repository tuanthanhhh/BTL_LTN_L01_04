#include "SENSOR.h"

float value[2];
int value_adc[2];

static ADC_HandleTypeDef *hadc_ptr;

void adc_Init(ADC_HandleTypeDef *hadc) {
    hadc_ptr = hadc;
}

float* read_sensor(void)
{
	HAL_ADC_Start_DMA(hadc_ptr, value_adc, 2);
	value[0] = get_Temperature(value_adc[0]);
	value[1] = get_Humidity(value_adc[1]);
	return value;
}

float get_Temperature(int adc_value)
{
	float temperature;
	temperature = (((float)adc_value/4095)*3.3f)*100;
	return temperature;
}

float get_Humidity(int adc_value)
{
	float Vout,humidity;
	Vout = ((float)adc_value / 4095.0f) * 3.3f;
	humidity = (3.0f-Vout)/0.02f;
	return humidity;
}



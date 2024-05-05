#include "SENSOR.h"

float value[2];
int value_adc[2];

static ADC_HandleTypeDef *hadc_ptr;

void adc_Init(ADC_HandleTypeDef *hadc) {
    hadc_ptr = hadc;
}

void read_sensor(void)
{
	HAL_ADC_Start_DMA(hadc_ptr, value_adc, 2);
}

float get_Temperature()
{
	float temperature;
	int adc_value = value_adc[0];
	temperature = (((float)adc_value/4095)*3.3f)*100;
	return temperature;
}

float get_Humidity()
{
	float Vout,humidity;
	int adc_value = value_adc[1];
	Vout = ((float)adc_value / 4095.0f) * 3.3f;
	humidity = (3.0f-Vout)/0.02f;
	return humidity;
}



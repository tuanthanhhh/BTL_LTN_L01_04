#include "LM393.h"

static ADC_HandleTypeDef *hadc_ptr;

void LM393_Init(ADC_HandleTypeDef *hadc) {
    hadc_ptr = hadc;
}

float LM393_ReadHumidity(void) {
    uint16_t adc_value = 0;
    float humidity = 0.0;
    float voltage = 0.0;
    // Start ADC conversion
    HAL_ADC_Start(hadc_ptr);

    // Wait for conversion to finish
    HAL_ADC_PollForConversion(hadc_ptr, 1000);

    // Read ADC value
    adc_value = HAL_ADC_GetValue(hadc_ptr);

    // Stop ADC conversion
    HAL_ADC_Stop(hadc_ptr);

    // Convert ADC value to soil humidity (calibration dependent)
    voltage = ((float)adc_value * 5 / 4095.0f) * 100.0f;
    humidity = (1 - ((voltage - 1.9f) / (5 - 1.9f)) ) * 100.0f;

    return humidity;
}

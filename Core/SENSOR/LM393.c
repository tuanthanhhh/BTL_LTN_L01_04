#include "LM393.h"

static ADC_HandleTypeDef *hadc_ptr;

void LM393_Init(ADC_HandleTypeDef *hadc) {
    hadc_ptr = hadc;
}

float LM393_ReadHumidity(void) {
    uint16_t adc_value = 0;
    float humidity = 0.0;
    float Vout = 0;

    // Start ADC conversion
    HAL_ADC_Start(hadc_ptr);

    // Wait for conversion to finish
    HAL_ADC_PollForConversion(hadc_ptr, 1000);

    // Read ADC value
    adc_value = HAL_ADC_GetValue(hadc_ptr);

    // Stop ADC conversion
    HAL_ADC_Stop(hadc_ptr);

    // Convert ADC value to soil humidity (calibration dependent)
    Vout = ((float)adc_value / 4095.0f) * 3.3f;
    humidity = (3.0f-Vout)/0.02f;


    return humidity;
}

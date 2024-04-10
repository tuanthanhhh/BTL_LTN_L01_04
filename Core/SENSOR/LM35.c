#include "LM35.h"

static ADC_HandleTypeDef *hadc_ptr;

void LM35_Init(ADC_HandleTypeDef *hadc) {
    hadc_ptr = hadc;
}

float LM35_ReadTemperature(void) {
    uint16_t adc_value = 0;
    float temperature = 0.0f;

    // Start ADC conversion
    HAL_ADC_Start(hadc_ptr);

    // Wait for conversion to finish
    if (HAL_ADC_PollForConversion(hadc_ptr, HAL_MAX_DELAY) == HAL_OK) {
        // Read ADC value
        adc_value = HAL_ADC_GetValue(hadc_ptr);

        // Stop ADC conversion
        HAL_ADC_Stop(hadc_ptr);

        // Convert ADC value to temperature (in Celsius)
        temperature = (float)adc_value * 3.3f / 4095.0f * 100.0f;
    }

    return temperature;
}

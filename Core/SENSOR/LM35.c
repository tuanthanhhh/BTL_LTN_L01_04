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
    HAL_ADC_PollForConversion(hadc_ptr, 1000);

    adc_value = HAL_ADC_GetValue(hadc_ptr);

    HAL_ADC_Stop(hadc_ptr);
    temperature = (((float)adc_value/4095)*3.3f)*100;

    return temperature;
}

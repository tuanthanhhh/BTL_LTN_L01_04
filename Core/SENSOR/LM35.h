#ifndef LM35_H
#define LM35_H

#include "stm32f1xx_hal.h"

// Function prototypes
void LM35_Init(ADC_HandleTypeDef *hadc);
float LM35_ReadTemperature(void);

#endif /* LM35_H */

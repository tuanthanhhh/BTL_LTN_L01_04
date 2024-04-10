#ifndef LM393_H
#define LM393_H

#include "stm32f1xx_hal.h"

// Function prototypes
void LM393_Init(ADC_HandleTypeDef *hadc);
float LM393_ReadHumidity(void);

#endif /* LM393_H */

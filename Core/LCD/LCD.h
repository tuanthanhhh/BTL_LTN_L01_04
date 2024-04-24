#ifndef INC_LCD_H_
#define INC_LCD_H_

#include "stm32f1xx_hal.h"

void LCD_INIT(void);
void LCD_SEND_CMD(char cmd);
void LCD_SEND_DATA(char data);
void LCD_SEND_STRING(char *str);
void LCD_PUT_CURSOR(int row, int column);
void LCD_CLEAR(void);
void LCD_TEMP(void);
void LCD_HUMI(void);
#endif /* INC_LCD_H_ */

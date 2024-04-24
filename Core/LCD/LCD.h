/*
 * LCD.h
 *
 *  Created on: Apr 24, 2024
 *      Author: Admin
 */

#ifndef INC_LCD_H_
#define INC_LCD_H_

void lcd_cmd (char cmd);
void lcd_data (char data);
void lcd_clear  (void);
void lcd_cursor (int row, int col);
void lcd_init (void);
void lcd_string (char *str);

#endif /* INC_LCD_H_ */

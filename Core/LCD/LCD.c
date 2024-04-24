#include "LCD.h"

#include "stm32f1xx.h"

#define LCD_RS_PIN 		GPIO_PIN_9
#define LCD_RS_PORT 	GPIOB
#define LCD_RW_PIN 		GPIO_PIN_10
#define LCD_RW_PORT 	GPIOB
#define LCD_EN_PIN 		GPIO_PIN_11
#define LCD_EN_PORT 	GPIOB
#define D4_PIN 			GPIO_PIN_12
#define D4_PORT			GPIOB
#define D5_PIN 			GPIO_PIN_13
#define D5_PORT 		GPIOB
#define D6_PIN 			GPIO_PIN_14
#define D6_PORT 		GPIOB
#define D7_PIN 			GPIO_PIN_15
#define D7_PORT 		GPIOB

#define LCD_CLEAR_DISPLAY 0x01
#define LCD_FUNCTION_SET  0x20

void send_to_lcd (char data, int rs)
{
	HAL_GPIO_WritePin(LCD_RS_PORT, LCD_RS_PIN, rs);

	HAL_GPIO_WritePin(D4_PORT, D4_PIN, (data>>0)&0x01);
	HAL_GPIO_WritePin(D5_PORT, D5_PIN, (data>>1)&0x01);
	HAL_GPIO_WritePin(D6_PORT, D6_PIN, (data>>2)&0x01);
	HAL_GPIO_WritePin(D7_PORT, D7_PIN, (data>>3)&0x01);

	HAL_GPIO_WritePin(LCD_EN_PORT, LCD_EN_PIN, 1);
	HAL_GPIO_WritePin(LCD_EN_PORT, LCD_EN_PIN, 0);
}

void lcd_cmd(char cmd)
{
	char datagui;
	datagui = ((cmd>>4)&0x0f);
	send_to_lcd(datagui, 0);

	HAL_Delay(5);
	datagui = ((cmd)&0x0f);
	send_to_lcd(datagui, 0);
}

void lcd_data(char data)
{
	char datagui;
	datagui = ((data>>4)&0x0f);
	send_to_lcd(datagui, 1);
	datagui = ((data)&0x0f);
	send_to_lcd(datagui, 1);
}

void lcd_clear(void)
{
	lcd_cmd(LCD_CLEAR_DISPLAY);
	HAL_Delay(2);
}

void lcd_cursor(int row, int col)
{
	switch (row)
	{
	case 0:
		col |= 0x80;
		break;
	case 1:
		col |= 0xC0;
		break;
	}
	lcd_cmd(col);
}

void lcd_init(void)
{
	HAL_Delay(50);
	lcd_cmd(0x33);

	//HAL_Delay(5);
	//lcd_cmd(0x30);

	HAL_Delay(5);
	lcd_cmd(0x32);


	//HAL_Delay(10);
//	lcd_cmd(LCD_FUNCTION_SET);

	HAL_Delay(10);
	lcd_cmd(0x28);

//	HAL_Delay(5);
//	lcd_cmd(0x08);

	HAL_Delay(5);
	lcd_cmd(LCD_CLEAR_DISPLAY);


	HAL_Delay(5);
	lcd_cmd(0x0C);
	HAL_Delay(5);
	lcd_cmd(0x06);

}

void lcd_string(char *str)
{
	while (*str) lcd_data(*str++);
}

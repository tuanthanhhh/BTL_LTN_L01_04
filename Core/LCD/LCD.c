/*
 * lcd.c
 *
 *  Created on: Apr 13, 2024
 *      Author: Admin
 */

#include "LCD.h"

extern I2C_HandleTypeDef hi2c2;

#define SLAVE_ADDRESS_LCD 0x4E

void LCD_SEND_CMD(char cmd)
{
	char data_u, data_l;
	uint8_t data_t[4];
	data_u = cmd & 0xF0;
	data_l = ((cmd<<4) & 0xF0);
	data_t[0] = data_u|0x0C;
	data_t[1] = data_u|0x08;
	data_t[2] = data_u|0x0C;
	data_t[3] = data_u|0x08;
	HAL_I2C_Master_Transmit (&hi2c2, SLAVE_ADDRESS_LCD,(uint8_t *) data_t, 4, 100);
}

void LCD_SEND_DATA (char data)
{
	char data_u, data_l;
	uint8_t data_t[4];
	data_u = data & 0xF0;
	data_l = ((data<<4) & 0xF0);
	data_t[0] = data_u|0x0D;
	data_t[1] = data_u|0x09;
	data_t[2] = data_u|0x0D;
	data_t[3] = data_u|0x09;
	HAL_I2C_Master_Transmit (&hi2c2, SLAVE_ADDRESS_LCD,(uint8_t *) data_t, 4, 100);
}

void LCD_INIT (void)
{
	LCD_SEND_CMD (0x33);
	LCD_SEND_CMD (0x32);
	HAL_Delay(50);
	LCD_SEND_CMD (0x28);
	HAL_Delay(50);
	LCD_SEND_CMD (0x01);
	HAL_Delay(50);
	LCD_SEND_CMD (0x06);
	HAL_Delay(50);
	LCD_SEND_CMD (0x0c);
	HAL_Delay(50);
	LCD_SEND_CMD (0x02);
	HAL_Delay(50);
	LCD_SEND_CMD (0x80);
}

void LCD_SEND_STRING(char *str)
{
	while (*str) LCD_SEND_DATA (*str++);
}

void LCD_CLEAR (void)
{
	LCD_SEND_CMD (0x01);
}

void LCD_PUT_CURSOR (int row, int col)
{
	uint8_t pos_Addr;
	if(row ==1)
	{
		pos_Addr = 0x80 + row - 1 + col;
	}
	else
	{
		pos_Addr = 0x80 | (0x40 + col);
	}
	LCD_SEND_CMD(pos_Addr);
}



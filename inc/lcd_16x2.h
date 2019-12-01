/*
 * lcd_16x2.h
 *
 *  Created on: 23 Nov 2019
 *      Author: asus
 */

#ifndef LCD_16X2_H_
#define LCD_16X2_H_

//***** Header files *****//
#include <stdbool.h>
#include "stm32f4xx_hal.h"
#include <stdlib.h>

//***** List of COMMANDS *****//
#define LCD_CLEARDISPLAY 		0x01
#define LCD_RETURNHOME 			0x02
#define LCD_ENTRYMODESET 		0x04
#define LCD_DISPLAYCONTROL 	0x08
#define LCD_CURSORSHIFT 		0x10
#define LCD_FUNCTIONSET 		0x20
#define LCD_SETCGRAMADDR 		0x40
#define LCD_SETDDRAMADDR 		0x80

//***** List of commands Bitfields *****//
//1) Entry mode Bitfields
#define LCD_ENTRY_SH		 				0x01
#define LCD_ENTRY_ID 						0x02
//2) Entry mode Bitfields
#define LCD_ENTRY_SH		 				0x01
#define LCD_ENTRY_ID 						0x02
//3) Display control
#define LCD_DISPLAY_B						0x01
#define LCD_DISPLAY_C						0x02
#define LCD_DISPLAY_D						0x04
//4) Shift control
#define LCD_SHIFT_RL						0x04
#define LCD_SHIFT_SC						0x08
//5) Function set control
#define LCD_FUNCTION_F					0x04
#define LCD_FUNCTION_N					0x08
#define LCD_FUNCTION_DL					0x10

//***** Functions prototypes *****//
//Private functions
//1) Enable EN pulse
void LCD1602_EnablePulse(void);
//2) RS control
void LCD1602_RS(bool state);
//3) Write Parallel interface
void LCD1602_write(uint8_t byte);
//4) Microsecond delay functions
void LCD1602_TIM_Config(void);
void LCD1602_TIM_MicorSecDelay(uint32_t uSecDelay);
//5) Write command
void LCD1602_writeCommand(uint8_t command);
//6) Write 8 bits data
void LCD1602_writeData(uint8_t data);
//7) Write 4 bits command, *FOR 4 BITS MODE ONLY*
void LCD1602_write4bitCommand(uint8_t nibble);

//Public functions
//1) LCD begin 8 bits function
void LCD1602_Begin8BIT(GPIO_TypeDef* PORT_RS_E, uint16_t RS, uint16_t E, GPIO_TypeDef* PORT_LSBs0to3, uint16_t D0, uint16_t D1, uint16_t D2, uint16_t D3, GPIO_TypeDef* PORT_MSBs4to7, uint16_t D4, uint16_t D5, uint16_t D6, uint16_t D7);
//2) LCD begin 4 bits function
void LCD1602_Begin4BIT(GPIO_TypeDef* PORT_RS_E, uint16_t RS, uint16_t E, GPIO_TypeDef* PORT_MSBs4to7, uint16_t D4, uint16_t D5, uint16_t D6, uint16_t D7);
//3) LCD print string
void LCD1602_print(char string[]);
//4) set cursor position
void LCD1602_setCursor(uint8_t row, uint8_t col);
void LCD1602_1stLine(void);
void LCD1602_2ndLine(void);
//5) Enable two lines
void LCD1602_TwoLines(void);
void LCD1602_OneLine(void);
//6) Cursor ON/OFF
void LCD1602_noCursor(void);
void LCD1602_cursor(void);
//7) Clear display
void LCD1602_clear(void);
//8) Blinking cursor
void LCD1602_noBlink(void);
void LCD1602_blink(void);
//9) Display ON/OFF
void LCD1602_noDisplay(void);
void LCD1602_display(void);
//10) Shift Display, right or left
void LCD1602_shiftToRight(uint8_t num);
void LCD1602_shiftToLeft(uint8_t num);

//********** Print numbers to LCD **********//
//1. Integer
void LCD1602_PrintInt(int number);
//2. Float
void LCD1602_PrintFloat(float number, int decimalPoints);




#endif /* LCD_16X2_H_ */

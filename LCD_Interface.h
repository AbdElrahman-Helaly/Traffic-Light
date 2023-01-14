/*
 * LCD_Interface.h
 *
 *  Created on: Jan 6, 2023
 *      Author: Abdelrahman Helaly
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#define lcd_Clear           0x01          /* replace all characters with ASCII 'space'                       */
#define lcd_Home            0x02          /* return cursor to first position on first line                   */
#define lcd_EntryMode       0x06          // shift cursor from left to right on read/write
#define lcd_DisplayOff      0x08          // turn display off
#define lcd_DisplayOn       0x0C          // display on, cursor off, don't blink character
#define lcd_FunctionReset   0x30          // reset the LCD
#define lcd_FunctionSet8bit 0x38          // 8-bit data, 2-line display, 5 x 7 font
#define lcd_SetCursor       0x80          // set cursor position

void CLCD_VoidInti(void);
void CLCD_vidSendCommand(u8 u8CmdCpy);
void CLCD_VoidWriteCharctr(u8 copy_VoidData);
void CLCD_SendString(const char* copy_pcstring);
void CLCD_SpecialCharacter(u8* Copy_u8Pattern,u8 Copy_u8PatternNum,u8 X_Pos, u8 Y_Pos);

void LCD_vidGotoxy(u8 X_Pos , u8 Y_pos);



#endif /* LCD_INTERFACE_H_ */

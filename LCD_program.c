/*
 * LCD_program.c
 *
 *  Created on: Jan 6, 2023
 *      Author: Abdelrahman Helaly
 */


#include "STD.h"
#include "bit.h"

#include "DIO_interface.h"
#include "LCD_Interface.h"
#include "LCD_Config.h"
#include <util/delay.h>







void CLCD_VoidInti(void)
{
	DIO_voidsetportDirection(CLCD_DATA_PORT,DIO_u8PORT_OUTPUT);
	DIO_voidsetPinDirection(CLCD_CTRL_PORT, CLCD_RS_PIN,DIO_u8PIN_OUTPUT);
	DIO_voidsetPinDirection(CLCD_CTRL_PORT, CLCD_RW_PIN,DIO_u8PIN_OUTPUT);
	DIO_voidsetPinDirection(CLCD_CTRL_PORT, CLCD_EN_PIN,DIO_u8PIN_OUTPUT);

	/* Delay 30ms to ensure the initialization of the LCD driver */
	_delay_ms(30);

	/* Return Home  */
	CLCD_vidSendCommand(lcd_Home);
	_delay_ms(15);

	/* Function Set  */
	CLCD_vidSendCommand(lcd_FunctionSet8bit);
	_delay_ms(1);

	/* Display ON OFF Control */
	CLCD_vidSendCommand(lcd_DisplayOn);
	_delay_ms(1);

	/* Clear Display */
	CLCD_vidSendCommand(lcd_Clear);
	_delay_ms(15);

	/* Entry Mode Set  */
	CLCD_vidSendCommand(lcd_EntryMode);
	_delay_ms(2);

}
void CLCD_vidSendCommand(u8 u8CmdCpy)
{
	/****SET RS TO LOW ***/
	DIO_voidSetPinvalue(CLCD_CTRL_PORT , CLCD_RS_PIN ,DIO_u8PIN_Low);
	/****SET RW TO LOW ***/
	DIO_voidSetPinvalue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_Low) ;
	/*****ENABLE*****/
	DIO_voidSetPinvalue(CLCD_CTRL_PORT,CLCD_EN_PIN,DIO_u8PIN_High);

	/*****SET DATA*****/
	DIO_voidsetportvalue(CLCD_DATA_PORT,u8CmdCpy);

	/*****ENABLE*****/
	DIO_voidSetPinvalue(CLCD_CTRL_PORT,CLCD_EN_PIN,DIO_u8PIN_Low);

	_delay_ms(1) ;

	DIO_voidSetPinvalue(CLCD_CTRL_PORT,CLCD_EN_PIN,DIO_u8PIN_High);
	_delay_ms(1) ;

}
void CLCD_VoidWriteCharctr(u8 copy_VoidData)
{

	/****SET RS AS HIGH***/
	DIO_voidSetPinvalue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_High);

	/****SET RS AS LOW***/
	DIO_voidSetPinvalue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_Low);

	DIO_voidSetPinvalue(CLCD_CTRL_PORT,CLCD_EN_PIN,DIO_u8PIN_High);

	/*****SET DATA*****/
	DIO_voidsetportvalue(CLCD_DATA_PORT,copy_VoidData);

	/*****ENABLE*****/
	DIO_voidSetPinvalue(CLCD_CTRL_PORT,CLCD_EN_PIN,DIO_u8PIN_Low);
	_delay_ms(1);

	//DIO_voidSetPinvalue(CLCD_CTRL_PORT,CLCD_EN_PIN,DIO_u8PIN_High);
	_delay_ms(1);

}

void CLCD_SendString(const char* copy_pcstring)
{
	u8 Local_u8 =0 ;

	while(copy_pcstring[Local_u8] != '\0')
	{
		CLCD_VoidWriteCharctr(copy_pcstring[Local_u8]);
		Local_u8 ++ ;
	}

	_delay_ms(2);
}

void CLCD_SpecialCharacter(u8* Copy_u8Pattern,u8 Copy_u8PatternNum,u8 X_Pos, u8 Y_Pos)
{
	u8 Local_u8CGRAMAddrrs =0;
	u8 Local_u8Iterator ;

	/* Calculate CGRAM Address  */
	Local_u8CGRAMAddrrs = Copy_u8PatternNum *8 ;

	/* Send CGRAM address to LCD */
	CLCD_vidSendCommand(Local_u8CGRAMAddrrs+64);

   /* Write Pattern into CGRAM */
	for(Local_u8Iterator=0;Local_u8Iterator<8;Local_u8Iterator++)
	{
		CLCD_VoidWriteCharctr(Copy_u8Pattern[Local_u8Iterator]);
	}

	LCD_vidGotoxy(X_Pos,Y_Pos);
	CLCD_VoidWriteCharctr(Copy_u8PatternNum);

}


void LCD_vidGotoxy(u8 X_Pos ,u8 Y_pos)
{
	if(X_Pos>0 && X_Pos<=16)
	{	switch(Y_pos)
	{

	case 0 : CLCD_vidSendCommand(0x80+X_Pos-1);          break;
	case 1 : CLCD_vidSendCommand(0xC0+X_Pos-1);         break;
	default:          break;
	}
	}
}


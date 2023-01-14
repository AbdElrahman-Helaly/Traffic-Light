
/*
 * main.c
 *
 *  Created on: Jan 6, 2023
 *      Author: Abdelrahman Helaly
 */
#include "bit.h"
#include "STD.h"
#include "DIO_interface.h"
#include "LCD_Interface.h"
#include <util/delay.h>

u8 SevenSegment( u8 Led_Num );

int main(void)
{
// Initial PORT
	DIO_voidsetPinDirection(DIO_u8PORTD,DIO_u8PIN0,DIO_u8PIN_OUTPUT);
	DIO_voidsetPinDirection(DIO_u8PORTD,DIO_u8PIN1,DIO_u8PIN_OUTPUT);
	DIO_voidsetPinDirection(DIO_u8PORTD,DIO_u8PIN2,DIO_u8PIN_OUTPUT);

	DIO_voidsetportDirection(DIO_u8PORTC,DIO_u8PORT_OUTPUT);
	//CLCD Initial
	CLCD_VoidInti();
	CLCD_vidSendCommand(lcd_Clear);

while(1)
{
	// RED LED ON
	CLCD_SendString("Waiting  10 sec");
	_delay_ms(100);


	for(u8 i=9;i>0;i--)
	{
		if(i>5){
			//RED LED IS ON
			DIO_voidSetPinvalue(DIO_u8PORTD,DIO_u8PIN0,DIO_u8PIN_High);

			CLCD_vidSendCommand(lcd_SetCursor+10);
			CLCD_VoidWriteCharctr((i%10)+48);

			CLCD_vidSendCommand(lcd_SetCursor+9);
			CLCD_VoidWriteCharctr(' ');
DIO_voidsetportvalue(DIO_u8PORTC,SevenSegment(i));
			_delay_ms(200);
		}


		else if((i<=5)&&(i>=2))
		{
			//RED OFF ORANGE ON
			DIO_voidSetPinvalue(DIO_u8PORTD,DIO_u8PIN0,DIO_u8PIN_Low);
			DIO_voidSetPinvalue(DIO_u8PORTD,DIO_u8PIN1,DIO_u8PIN_High);

			CLCD_vidSendCommand(lcd_SetCursor+10);
			CLCD_VoidWriteCharctr((i%10)+48);

			CLCD_vidSendCommand(lcd_SetCursor+9);
			CLCD_VoidWriteCharctr(' ');
			DIO_voidsetportvalue(DIO_u8PORTC,SevenSegment(i));

			_delay_ms(200);

		}

		else if((i>=1)&&(i<2))
		{

			// ORANGE OFF GREEN ON
			DIO_voidSetPinvalue(DIO_u8PORTD,DIO_u8PIN1,DIO_u8PIN_Low);
			DIO_voidSetPinvalue(DIO_u8PORTD,DIO_u8PIN2,DIO_u8PIN_High);

			CLCD_vidSendCommand(lcd_SetCursor+10);
			CLCD_VoidWriteCharctr((i%10)+48);

			CLCD_vidSendCommand(lcd_SetCursor+9);

			CLCD_VoidWriteCharctr(' ');
			DIO_voidsetportvalue(DIO_u8PORTC,SevenSegment(i));

			_delay_ms(200);
		}
	}

	CLCD_vidSendCommand(lcd_Clear);
	CLCD_SendString("     GO NOW   ");

	DIO_voidsetportvalue(DIO_u8PORTC,SevenSegment(0));
	DIO_voidSetPinvalue(DIO_u8PORTD,DIO_u8PIN2,DIO_u8PIN_Low);
	_delay_ms(200);
	CLCD_vidSendCommand(lcd_Clear);



}




	return 0;
}


u8 SevenSegment( u8 Led_Num )
{

	const u8 arr[10]={

			0b0111111,
			0b0000110,
			0b1011011,
			0b1001111,
			0b1100110,
			0b1101101,
			0b1111101,
			0b0000111,
			0b1111111,
			0b1101111
	};

	return arr[ Led_Num ];
}

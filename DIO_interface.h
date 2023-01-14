/******************************************************************/
/******************************************************************/
/*******************    Eng/abdelrahman helaly  *******************/
/*******************    Layer:MCAL              *******************/
/*******************    SEC: DIO                *******************/
/*******************    version:1.00            *******************/
/******************************************************************/
/******************************************************************/

#ifndef DIO_interface_H_
#define DIO_interface_H_

#define DIO_u8PIN_High              1
#define DIO_u8PIN_Low               0


#define DIO_u8PORT_High             0xff
#define DIO_u8PORT_Low              0x00


#define DIO_u8PIN_OUTPUT            1
#define DIO_u8PIN_INPUT             0

#define DIO_u8PORT_OUTPUT           0xff
#define DIO_u8PORT_INPUT            0x00



#define DIO_u8PORTA                 0
#define DIO_u8PORTB                 1
#define DIO_u8PORTC                 2
#define DIO_u8PORTD                 3
									
#define DIO_u8PIN0                  0
#define DIO_u8PIN1                  1
#define DIO_u8PIN2                  2
#define DIO_u8PIN3                  3
#define DIO_u8PIN4                  4
#define DIO_u8PIN5                  5
#define DIO_u8PIN6                  6
#define DIO_u8PIN7                  7


//DIRECTION
void DIO_voidsetPinDirection(u8 Copy_u8port,u8 Copy_u8pin,u8 Copy_u8Direction);
void DIO_voidsetportDirection(u8 Copy_u8port,u8 Copy_u8Direction);

//VALUE
void DIO_voidSetPinvalue(u8 Copy_u8port,u8 Copy_u8pin,u8 Copy_u8value);
void DIO_voidsetportvalue(u8 Copy_u8port,u8 Copy_u8value);

//GET VALUE
void DIO_u8GetpinValue(u8 Copy_u8port,u8 Copy_u8pin,u8* Copy_pu8value);



#define Anode  1
#define Cathod  0
#endif 







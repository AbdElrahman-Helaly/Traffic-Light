
#ifndef STD_H_
#define STD_H_
 



typedef unsigned char u8;
typedef signed char s8;

typedef unsigned short int u16;
typedef signed short int s16;

typedef unsigned long int u32;
typedef signed long int s32;

typedef   float f32;

typedef   double d32;
typedef struct{
	u8 Com_type;
	u8 Port;
	u8 EnablePort;
	u8 EnablePin;

}SSD_t;
 
#define NULL 0
#endif

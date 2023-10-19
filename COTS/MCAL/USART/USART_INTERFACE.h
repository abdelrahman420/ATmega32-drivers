#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H

#include "../../LIB/STD.h"

/*Defining Modes Synchronous Or Asynchronous*/
#define SC  0
#define ASC 1

/*Defining Parity Check Options*/
#define DP 0
#define EP 1
#define OP 2

/*Defining Stop Bit Options*/
#define SB1  1 
#define SB2  2

/*Defining Character Size Options*/
#define Five_Bits  5
#define Six_Bits   6
#define Seven_Bits 7
#define Eight_Bits 8
#define Nine_Bits  9
/* Defining Asynchronous Mode Options */
#define Fast_ASC   0
#define Normal_ASC 1

/*Defining Modes of handling Data*/
#define U_POLLING
#define U_INTERRUP

void USART_voidInit(u32 copy_u32BaudRate);
void USART_voidSendData(u16 copy_u16Data);
u16 USART_u16ReceiveData(void);
void USART_voidSendDataAsync(u16 copy_u16Data);
u16 USART_u16ReceiveDataAsync(void);
void USART_voidSendString(u8 *copy_u16String);
void USART_voidRecieveString(u8 *copy_u16String);
#endif

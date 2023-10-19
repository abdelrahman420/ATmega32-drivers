/*
Author:Abdelrahman Mostafa
Date :3/8/2023
SWC  : DIO
Version : 1.0
*/
#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

#include "../../LIB/STD.h"

#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3


#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2 
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5 
#define DIO_PIN6 6
#define DIO_PIN7 7

#define DIO_INPUT  0
#define DIO_OUTPUT 1


#define DIO_LOW  0
#define DIO_HIGH 1

/*SET PIN DIRECTION*/
void DIO_voidSetPinDirection(u8 copy_u8PortID,u8 copy_u8PinID,u8 copy_u8Dir);
/*SET PIN VALUE*/
void DIO_voidSetPinValue(u8 copy_u8PortID,u8 copy_u8PinID,u8 copy_u8Value);
/*GET PIN DIRECTION*/
u8 DIO_u8GetPinValue(u8 copy_u8PortID,u8 copy_u8PinID);

/*SET PORT DIRECTION*/
void DIO_voidSetPortDirection(u8 Copy_u8PortId , u8 Copy_u8Dir);
/*SET PORT VALUE*/
void DIO_voidSetPortValue(u8 Copy_u8PortId , u8 Copy_u8Value);
/*GET PORT DIRECTION*/
u8 DIO_u8GetPortValue(u8 Copy_u8PortId);
#endif

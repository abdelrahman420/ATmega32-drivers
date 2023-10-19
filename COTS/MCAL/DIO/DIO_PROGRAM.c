/*
Author:Abdelrahman Mostafa
Date :3/8/2023
SWC  : DIO
Version : 1.0
*/


#include "../../LIB/STD.h"
#include "../../LIB/BitMath.h"
#include "DIO_INTERFACE.h"
#include "DIO_PRIVATE.h"
#include "DIO_CONFIG.h"


void DIO_voidSetPinDirection(u8 copy_u8PortID,u8 copy_u8PinID,u8 copy_u8Dir)
{
    switch(copy_u8Dir)
    {
        case DIO_INPUT:
        {
            switch(copy_u8PortID)
            {
                case DIO_PORTA: CLR_BIT(DDRA_REG,copy_u8PinID);
                break;
                case DIO_PORTB: CLR_BIT(DDRB_REG,copy_u8PinID);
                break;
                case DIO_PORTC: CLR_BIT(DDRC_REG,copy_u8PinID);
                break;
                case DIO_PORTD: CLR_BIT(DDRD_REG,copy_u8PinID);
                break;
            }
        }
        break;
        case DIO_OUTPUT:
        {
            switch(copy_u8PortID)
            {
                case DIO_PORTA: SET_BIT(DDRA_REG,copy_u8PinID);
                break;
                case DIO_PORTB: SET_BIT(DDRB_REG,copy_u8PinID);
                break;
                case DIO_PORTC: SET_BIT(DDRC_REG,copy_u8PinID);
                break;
                case DIO_PORTD: SET_BIT(DDRD_REG,copy_u8PinID);
                break;
            }
        }
        break;
    }
}
void DIO_voidSetPinValue(u8 copy_u8PortID,u8 copy_u8PinID,u8 copy_u8Value)
{
    switch(copy_u8Value)
    {
        case DIO_LOW:
        {
            switch(copy_u8PortID)
            {
                case DIO_PORTA : CLR_BIT(PORTA_REG,copy_u8PinID);
                break;
                case DIO_PORTB: CLR_BIT(PORTB_REG,copy_u8PinID);
                break;
                case DIO_PORTC: CLR_BIT(PORTC_REG,copy_u8PinID);
                break;
                case DIO_PORTD: CLR_BIT(PORTD_REG,copy_u8PinID);
                break;
            }
        }
        break;
        case DIO_HIGH:
        {
            switch(copy_u8PortID)
            {
                case DIO_PORTA: SET_BIT(PORTA_REG,copy_u8PinID);
                break;
                case DIO_PORTB: SET_BIT(PORTB_REG,copy_u8PinID);
                break;
                case DIO_PORTC: SET_BIT(PORTC_REG,copy_u8PinID);
                break;
                case DIO_PORTD: SET_BIT(PORTD_REG,copy_u8PinID);
                break;
            }
        }
        break;
    }
}
u8 DIO_u8GetPinValue(u8 copy_u8PortID,u8 copy_u8PinID)
{
    u8 Local_u8ReturnedValue = 255;
    switch(copy_u8PortID)
    {
        case DIO_PORTA: Local_u8ReturnedValue = GET_BIT(PINA_REG,copy_u8PinID);
        break;
        case DIO_PORTB: Local_u8ReturnedValue = GET_BIT(PINB_REG,copy_u8PinID);
        break;
        case DIO_PORTC: Local_u8ReturnedValue = GET_BIT(PINC_REG,copy_u8PinID);
        break;
        case DIO_PORTD: Local_u8ReturnedValue = GET_BIT(PIND_REG,copy_u8PinID);
        break;
    }
    return Local_u8ReturnedValue;
}

void DIO_voidSetPortDirection(u8 Copy_u8PortId , u8 Copy_u8Dir)
{
	switch(Copy_u8Dir)
	{
		case DIO_INPUT :
	    {
			switch(Copy_u8PortId)
			{
				case DIO_PORTA :DDRA_REG = 0x00; // 255 0b11111111
				break;
				case DIO_PORTB :DDRB_REG = 0x00;
				break;
				case DIO_PORTC :DDRC_REG = 0x00;
				break;
				case DIO_PORTD :DDRD_REG = 0x00;
				break;
				default:
				break;
			}
		}
	    break;
        case DIO_OUTPUT :
        {
            switch(Copy_u8PortId)
            {
                case DIO_PORTA :DDRA_REG = 0xff; // 255 0b11111111
                break;
                case DIO_PORTB :DDRB_REG = 0xff;
                break;
                case DIO_PORTC :DDRC_REG = 0xff;
                break;
                case DIO_PORTD :DDRD_REG = 0xff;
                break;
                default:
                break;
            }
        }
        break ;
    }
}

void DIO_voidSetPortValue(u8 Copy_u8PortId , u8 Copy_u8Value)
{
	switch(Copy_u8PortId)
	{
        case DIO_PORTA :PORTA_REG = Copy_u8Value;
        break;
        case DIO_PORTB :PORTB_REG = Copy_u8Value;
        break;
        case DIO_PORTC :PORTC_REG = Copy_u8Value;
        break;
        case DIO_PORTD :PORTD_REG = Copy_u8Value;
        break;
        default:
        break;
	}
}

u8 DIO_u8GetPortValue(u8 Copy_u8PortId)
{
	u8 Local_u8ReturnedValue = 255 ;
    switch(Copy_u8PortId)
    {
        case DIO_PORTA :Local_u8ReturnedValue = PINA_REG ;
        break;
        case DIO_PORTB :Local_u8ReturnedValue =	PINB_REG;
        break;
        case DIO_PORTC :Local_u8ReturnedValue = PINC_REG ;
        break;
        case DIO_PORTD :Local_u8ReturnedValue = PIND_REG ;
        break;
        default:
        break;
    }
	return Local_u8ReturnedValue ;
}

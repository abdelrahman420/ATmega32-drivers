

#include "../../LIB/STD.h"
#include "../../LIB/BitMath.h"
#include "../../MCAL/DIO/DIO_INTERFACE.h"
#include "LCD_INTERFACE.h"
#include "LCD_PRIVATE.h"
#include "LCD_CONFIG.h"

#define F_CPU 8000000UL
#include <util/delay.h>

void LCD_voidInit(void)
{
	DIO_voidSetPortDirection(LCD_DATA_PORT,DIO_OUTPUT);
	DIO_voidSetPinDirection(LCD_CTRL_PORT,LCD_RS,DIO_OUTPUT);
	DIO_voidSetPinDirection(LCD_CTRL_PORT,LCD_RW,DIO_OUTPUT);
	DIO_voidSetPinDirection(LCD_CTRL_PORT,LCD_EN,DIO_OUTPUT);

	_delay_ms(50);
	//Function Set
	LCD_voidsendCommand(0b00111000);


	_delay_us(50);
	/*Display on off*/
	LCD_voidsendCommand(0b00001110);


	_delay_us(50);
	/*Display clear*/
	LCD_voidsendCommand(0x01);

	_delay_ms(2);
	//Entry Mode Set
	LCD_voidsendCommand(0b00000110);

}
void LCD_voidsendCommand(u8 copy_u8Cmd)
{
	/*set Rs ->>>Low   to send command*/


		DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_RS,DIO_LOW);

	/* RW ->>>>low    to write*/

	    DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_RW,DIO_LOW);
	/*Sending command*/
	    DIO_voidSetPortValue(LCD_DATA_PORT,copy_u8Cmd);
	/*Enable PIN*/
	    DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_EN,DIO_HIGH);
	    _delay_us(1);
	    DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_EN,DIO_LOW);
	    _delay_ms(10);

}
void LCD_voidsendData(u8 copy_u8Data)
{

	    /*set Rs ->>>Low   to send command*/
			DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_RS,DIO_HIGH);

		/* RW ->>>>low    to write*/

		    DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_RW,DIO_LOW);
		/*Sending command*/

		    DIO_voidSetPortValue(LCD_DATA_PORT,copy_u8Data);
		/*Enable PIN*/
		    DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_EN,DIO_HIGH);
		    _delay_us(1);
		    DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_EN,DIO_LOW);
		    _delay_ms(10);
}
void LCD_voidSetPosition(u8 copy_u8Row,u8 copy_u8Col)
{
	switch(copy_u8Row)
	{
		case LCD_ROW_1 : LCD_voidsendCommand(0x80 + copy_u8Col - 1);
		break;
		case LCD_ROW_2 : LCD_voidsendCommand(0x80 + 64 + copy_u8Col - 1);
		break;
		default:
		break;
	}
}
void LCD_voidSendExtraChar(u8 copy_u8PatternLocation,u8 *copy_Ptru8ExtraChar,u8 copy_u8Row,u8 copy_u8Col)
{
	u8 Local_u8Address = 0;
	Local_u8Address = copy_u8PatternLocation * 8;
	//goto CGRAM
	LCD_voidsendCommand(64 + Local_u8Address);
	//generate char in CGRAM
	for(u8 i = 0;i<8;i++)
	{
		LCD_voidsendData(copy_Ptru8ExtraChar[i]);
	}
	//back to DDRAM
	LCD_voidSetPosition(copy_u8Row,copy_u8Col);
	//draw Char
	LCD_voidsendData(copy_u8PatternLocation);
}
void LCD_voidSendString(u8 *copy_u8String)
{
	int i = 0;
	while(copy_u8String[i] != '\0')
	{
		LCD_voidsendData(copy_u8String[i++]);
	}
}
void LCD_voidSendNum(u64 copy_u64Num)
{
	u64 Local_u64Reversed = 1;
	if(copy_u64Num == 0)
	{
		LCD_voidsendData('0');
	}
	else
	{
		while(copy_u64Num != 0)
		{
			Local_u64Reversed = (Local_u64Reversed *10)+(copy_u64Num % 10);
			copy_u64Num /= 10;
		}
		while(Local_u64Reversed != 1)
		{
			LCD_voidsendData((Local_u64Reversed % 10) +'0');
			Local_u64Reversed /= 10;
		}
	}
}

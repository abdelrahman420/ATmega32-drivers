

#define F_CPU 8000000UL
#include <util/delay.h>

#include "../../MCAL/DIO/DIO_INTERFACE.h"
#include "KEYPAD_INTERFACE.h"
#include "KEYPAD_PRIVATE.h"
#include "KEYPAD_CONFIG.h"

void KeyPad_voidInit()
{
    DIO_voidSetPinDirection(KEYPAD_PORT,KEYPAD_COL1_PIN,DIO_OUTPUT);
    DIO_voidSetPinDirection(KEYPAD_PORT,KEYPAD_COL2_PIN,DIO_OUTPUT);
    DIO_voidSetPinDirection(KEYPAD_PORT,KEYPAD_COL3_PIN,DIO_OUTPUT);
    DIO_voidSetPinDirection(KEYPAD_PORT,KEYPAD_COL4_PIN,DIO_OUTPUT);

    DIO_voidSetPinDirection(KEYPAD_PORT,KEYPAD_ROW1_PIN,DIO_INPUT);
    DIO_voidSetPinDirection(KEYPAD_PORT,KEYPAD_ROW2_PIN,DIO_INPUT);
    DIO_voidSetPinDirection(KEYPAD_PORT,KEYPAD_ROW3_PIN,DIO_INPUT);
    DIO_voidSetPinDirection(KEYPAD_PORT,KEYPAD_ROW4_PIN,DIO_INPUT);

    DIO_voidSetPortDirection(KEYPAD_PORT,0x0f);

    DIO_voidSetPortValue(KEYPAD_PORT,0xff);
}

u8 KeyPad_u8GetKeyPressed(void)
{

	_delay_ms(50);
    u8 Local_u8KeyPressed = NOT_PRESSED;
    for(u8 col_index= 0 ;col_index <NUM_OF_COLS;col_index ++)
    {
        DIO_voidSetPinValue(KEYPAD_PORT,cols_pins[col_index],DIO_LOW);
        for(u8 row_index = 0;row_index < NUM_OF_ROWS;row_index ++)
        {
            if(DIO_u8GetPinValue(KEYPAD_PORT,rows_pins[row_index]) == 0)
            {
                Local_u8KeyPressed = KeyPad_Keys[row_index][col_index];
                while(DIO_u8GetPinValue(KEYPAD_PORT,rows_pins[row_index]) == 0);
                _delay_ms(50);
            }
            else
            {};
        }
        DIO_voidSetPinValue(KEYPAD_PORT,cols_pins[col_index],DIO_HIGH);
    }
    return Local_u8KeyPressed;
}

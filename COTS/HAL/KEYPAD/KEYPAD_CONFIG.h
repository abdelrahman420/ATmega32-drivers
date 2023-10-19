#ifndef KEYPAD_CONFIG_H
#define KEYPAD_CONFIG_H

#define NUM_OF_ROWS  4
#define NUM_OF_COLS  4



#define KEYPAD_PORT DIO_PORTD

#define KEYPAD_ROW1_PIN  DIO_PIN4
#define KEYPAD_ROW2_PIN  DIO_PIN5
#define KEYPAD_ROW3_PIN  DIO_PIN6
#define KEYPAD_ROW4_PIN  DIO_PIN7


#define KEYPAD_COL1_PIN  DIO_PIN3
#define KEYPAD_COL2_PIN  DIO_PIN2
#define KEYPAD_COL3_PIN  DIO_PIN1
#define KEYPAD_COL4_PIN  DIO_PIN0

u8 rows_pins[NUM_OF_ROWS] =
{
	KEYPAD_ROW1_PIN,
	KEYPAD_ROW2_PIN,
	KEYPAD_ROW3_PIN,
	KEYPAD_ROW4_PIN
};

u8 cols_pins[NUM_OF_COLS] =
{
	KEYPAD_COL1_PIN,
	KEYPAD_COL2_PIN,
	KEYPAD_COL3_PIN,
	KEYPAD_COL4_PIN
};

u8 KeyPad_Keys[NUM_OF_ROWS][NUM_OF_COLS] =
{
    {'7','8','9','/'},
    {'4','5','6','*'},
    {'1','2','3','-'},
    {'C','0','=','+'}
};

#endif

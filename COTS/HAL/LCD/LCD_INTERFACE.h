#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H
#include "../../LIB/STD.h"




#define LCD_ROW_1 1
#define LCD_ROW_2 2


#define LCD_COL_1 1
#define LCD_COL_2 2
#define LCD_COL_3 3
#define LCD_COL_4 4
#define LCD_COL_5 5
#define LCD_COL_6 6
#define LCD_COL_7 7
#define LCD_COL_8 8
#define LCD_COL_9 9
#define LCD_COL_10 10
#define LCD_COL_11 11
#define LCD_COL_12 12
#define LCD_COL_13 13
#define LCD_COL_14 14
#define LCD_COL_15 15
#define LCD_COL_16 16

#define LCD_CLR_DISPLAY  0x01

#define SHIFT_LEFT   0b00011000
#define SHIFT_RIGHT  0b00011100


void LCD_voidInit(void);
void LCD_voidsendCommand(u8 copy_u8Cmd);
void LCD_voidsendData(u8 copy_u8Data);
void LCD_voidSetPosition(u8 copy_u8Row,u8 copy_u8Col);
void LCD_voidSendExtraChar(u8 copy_u8PatternLocation,u8 *copy_Ptru8ExtraChar,u8 copy_u8Row,u8 copy_u8Col);
void LCD_voidSendString(u8 *copy_u8String);
void LCD_voidSendNum(u64 copy_u64Num);



#endif

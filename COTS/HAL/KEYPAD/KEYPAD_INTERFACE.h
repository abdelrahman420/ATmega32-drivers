#ifndef KEYPAD_INTERFACE_H
#define KEYPAD_INTERFACE_H

#include "../../LIB/STD.h"



#define NOT_PRESSED   0xff
    
void KeyPad_voidInit();
u8 KeyPad_u8GetKeyPressed(void);


#endif

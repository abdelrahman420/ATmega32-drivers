#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

#include "../../LIB/STD.h"

#define Active_Low   0
#define Active_High  1
  
typedef struct 
{
    u8 Port;
    u8 Pin;
    u8 ActiveState;
    
}LED_t;

void LED_voidInit		(LED_t * Copy_PtrLed );
void LED_voidOn			(LED_t * Copy_PtrLed );
void LED_voidOff		(LED_t * Copy_PtrLed );

#endif
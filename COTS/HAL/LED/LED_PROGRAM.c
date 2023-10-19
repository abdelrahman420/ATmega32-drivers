

#include "../../MCAL/DIO/DIO_INTERFACE.h"
#include "LED_INTERFACE.h"
#include "LED_PRIVATE.h"
#include "LED_CONFIG.h"

void LED_voidInit(LED_t * Copy_PtrLed )
{
    DIO_voidSetPinDirection(Copy_PtrLed->Port,Copy_PtrLed->Pin,DIO_OUTPUT);
    switch(Copy_PtrLed->ActiveState)
    {
        case Active_Low:DIO_voidSetPinValue(Copy_PtrLed->Port,Copy_PtrLed->Pin,DIO_HIGH);
        break;
        case Active_High:DIO_voidSetPinValue(Copy_PtrLed->Port,Copy_PtrLed->Pin,DIO_LOW);
        break;
        default:
        break;
    }
}
void LED_voidOn(LED_t * Copy_PtrLed )
{
    switch(Copy_PtrLed->ActiveState)
    {
        case Active_Low:DIO_voidSetPinValue(Copy_PtrLed->Port,Copy_PtrLed->Pin,DIO_LOW);
        break;
        case Active_High:DIO_voidSetPinValue(Copy_PtrLed->Port,Copy_PtrLed->Pin,DIO_HIGH);
        break;
        default:
        break;
    }
}

void LED_voidOff(LED_t * Copy_PtrLed )
{
    switch(Copy_PtrLed->ActiveState)
    {
        case Active_Low:DIO_voidSetPinValue(Copy_PtrLed->Port,Copy_PtrLed->Pin,DIO_HIGH);
        break;
        case Active_High:DIO_voidSetPinValue(Copy_PtrLed->Port,Copy_PtrLed->Pin,DIO_LOW);
        break;
        default:
        break;
    }
}




#include "../../MCAL/DIO/DIO_INTERFACE.h"
#include "SSD_INTERFACE.h"
#include "SSD_PRIVATE.h"
#include "SSD_CONFIG.h"


void SSD_voidInit(SSD_t * Copy_Ptr_SSD)
{
    DIO_voidSetPortDirection(Copy_Ptr_SSD->Port,DIO_OUTPUT);
    switch(Copy_Ptr_SSD->CommonState)
    {
        case SSD_COMMON_CATHODE:DIO_voidSetPortValue(Copy_Ptr_SSD->Port,0x00);
        break;
        case SSD_COMMON_ANODE:DIO_voidSetPortValue(Copy_Ptr_SSD->Port,0xff);
        break;
        default:
        break;
    }

}
void SSD_voidEnable(SSD_t * Copy_Ptr_SSD ,u8 Copy_u8Number )
{
    switch(Copy_Ptr_SSD->CommonState)
    {
        case SSD_COMMON_CATHODE:DIO_voidSetPortValue(Copy_Ptr_SSD->Port,ArrayNumbers[Copy_u8Number]);
        break;
        case SSD_COMMON_ANODE:DIO_voidSetPortValue(Copy_Ptr_SSD->Port,~ArrayNumbers[Copy_u8Number]);
        break;
        default:
		break;
    }
}
void SSD_voidDisable(SSD_t * Copy_Ptr_SSD)
{
    DIO_voidSetPortDirection(Copy_Ptr_SSD->Port,DIO_OUTPUT);
    switch(Copy_Ptr_SSD->CommonState)
    {
        case SSD_COMMON_CATHODE:DIO_voidSetPortValue(Copy_Ptr_SSD->Port,0x00);
        break;
        case SSD_COMMON_ANODE:DIO_voidSetPortValue(Copy_Ptr_SSD->Port,0xff);
        break;
        default:
		break;
    }
}

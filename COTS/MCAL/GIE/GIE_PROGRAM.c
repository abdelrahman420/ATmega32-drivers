#include "../../LIB/STD.h"
#include "../../LIB/BitMath.h"
#include "GIE_INTERFACE.h"



void GIE_voidEnable(void)
{
    SET_BIT(SREG_REG,7);
}
void GIE_voidDisable(void)
{
    SET_BIT(SREG_REG,7);
}

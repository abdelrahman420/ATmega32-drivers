/*
 * WDG_PROGRAM.c
 *
 *  Created on: 19Aug.,2023
 *      Author: abdel
 */

#include "../../LIB/STD.h"
#include "../../LIB/BitMath.h"
#include "WDG_INTERFACE.h"
#include "WDG_PRIVATE.h"

void WDG_voidEnable(void)
{
	SET_BIT(WDTCR_REG,3);
	WDTCR_REG &= 0xF8;
	WDTCR_REG |= cyc128;
}
void WDG_voidDisable(void)
{
	CLR_BIT(WDTCR_REG,3);
	SET_BIT(WDTCR_REG,4);
}

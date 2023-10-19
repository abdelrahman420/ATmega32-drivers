/*
 * WDG_INTERFACE.c
 *
 *  Created on: 19Aug.,2023
 *      Author: abdel
 */

#ifndef COTS_MCAL_WDG_WDG_INTERFACE_C_
#define COTS_MCAL_WDG_WDG_INTERFACE_C_


typedef enum {
	cyc16k, cyc32k, cyc64k, cyc128, cyc256k, cyc512k, cyc1024k, cyc2048k
}WDT_prescaler;
void WDG_voidEnable(void);
void WDG_voidDisable(void);

#endif /* COTS_MCAL_WDG_WDG_INTERFACE_C_ */

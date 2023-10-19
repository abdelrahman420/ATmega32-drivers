#ifndef INTERRUPT_INTERFACE_H
#define INTERRUPT_INTERFACE_H

#include "../../LIB/STD.h"

#define EXTI_RisingEdge    0
#define EXTI_FallingEdge   1
#define EXTI_OnChange      2
#define EXTI_LowLevel      3


#define EXIT_INT0 0
#define EXIT_INT1 1
#define EXIT_INT2 2


void Interrupt_voidInit(void);
void Interrupt_voidChangeSenseControl(u8 copy_u8IntID,u8 copy_u8SenseControl);
void EXTI_voidEnable(u8 copy_u8IntID);
void EXTI_voidDisable(u8 copy_u8IntID);
void Interrupt_voiSetCallBack(u8 copy_u8IntID,void (*PF) (void));




#endif

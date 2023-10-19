#ifndef GIE_INTERFACE_H
#define GIE_INTERFACE_H


#define SREG_REG        *((volatile u8 *)0x5F)

void GIE_voidEnable(void);
void GIE_voidDisable(void);
#endif

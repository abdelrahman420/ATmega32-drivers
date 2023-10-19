#ifndef BitMath_H
#define BitMath_H


#define SET_BIT(REG,BITNO) (REG |=  (1<<BITNO))
#define CLR_BIT(REG,BITNO) (REG &= ~(1<<BITNO))
#define TOG_BIT(REG,BITNO) REG = REG ^(1<<BITNO)
#define GET_BIT(REG,BITNO) ((REG >> (BITNO))&1)



#endif

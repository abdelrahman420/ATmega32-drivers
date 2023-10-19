#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H


#define ADMUX_REG   *((volatile u8 *)0x27)
#define ADCSRA_REG  *((volatile u8 *)0x26)
#define ADCH_REG    *((volatile u8 *)0x25)
#define ADCL_REG    *((volatile u8 *)0x24)

#define SFIOR_REG   *((volatile u8 *)0x50)

#define ADEN_bit 7
#define ADIE_bit 3

#define ADCSC_bit 6
#define ADCIF_bit 4




#endif

/*
 * TIMER_PRIVATE.h
 *
 *  Created on: 15Aug.,2023
 *      Author: abdel
 */

#ifndef TIMER_PRIVATE_H
#define TIMER_PRIVATE_H



/*	General Registers For Timers */
#define TIMSK_REG  *((volatile u8*)0x59)

#define TOIE0_BIT   0
#define OCIE0_BIT   1
#define TOIE1_BIT   2
#define OCIE1B_BIT  3
#define OCIE1A_BIT  4
#define TICIE1_BIT  5




#define TIFR_REG   *((volatile u8*)0x58)

#define TOV0_BIT    0
#define OCF0_BIT    1
#define TOV1_BIT    2
#define OCF1B_BIT   3
#define OCF1A_BIT   4
#define ICF1_BIT    5


/*	Timer 0 Registers*/
#define TCCR0_REG  *((volatile u8*)0x53)

#define WGM01_BIT    3
#define WGM00_BIT    6
#define FOC0_BIT     7

#define TCNT0_REG  *((volatile u8*)0x52)
#define OCR0_REG   *((volatile u8*)0x5C)


/*	Timer 1	Registers */
#define TCCR1A_REG	*((volatile u8*)0x4F)

#define WGM10_BIT    0
#define WGM11_BIT    1
#define FOC1B_BIT	 2
#define	FOC1A_BIT	 3
#define COM1B0_BIT   4
#define COM1B1_BIT   5
#define COM1A0_BIT   6
#define COM1A1_BIT   7


#define TCCR1B_REG	*((volatile u8*)0x4E)

#define WGM12_BIT    3
#define WGM13_BIT    4

#define TCNT1_REG   *((volatile u16*)0x4C)
#define OCR1A_REG	*((volatile u16*)0x4A)
#define OCR1B_REG	*((volatile u16*)0x48)
#define ICR1_REG 	*((volatile u16*)0x46)



#endif /* COTS_MCAL_TIMERS_TIMER_PRIVATE_H_ */

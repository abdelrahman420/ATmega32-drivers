/*
 * TIMER_INTERFACE.h
 *
 *  Created on: 15Aug.,2023
 *      Author: abdel
 */

#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H

#include "../../LIB/STD.h"

/* Timer 0 Configurations */

typedef enum
{
	TMR0_Normal_mode,
	TMR0_PWM_Phase_correct,
	TMR0_Compare_Mood,
	TMR0_Fast_PWM
}TMR0_Mode_t;

typedef enum
{
	Disconnect_OC0,
	Toggle,
	Clear_OC0,
	Set_OC0
}TMR0_OC0_NonPWM_t;
typedef enum
{
	FastNon_inverting = 2,
	FastInverting
}TMR0_OC0_FastPWM_t;

typedef enum
{
	PhaseNon_inverting = 2,
	PhaseInverting
}TMR0_OC0_PhaseCorrectPWM_t;
typedef enum
{
	No_CLK,
	CLK_FCPU,
	CLK_FCPU_8,
	CLK_FCPU_64,
	CLK_FCPU_256,
	CLK_FCPU_1024,
	External_Falling,
	External_Rising
}TMR_CLKSEL_t;
typedef enum
{
	TMR_POLLING,
	TMR_INTERRUPT
}TMR_Technique_t;
typedef struct
{
	TMR0_Mode_t        			Mode;
	TMR0_OC0_NonPWM_t  			OC0_Options;
	TMR0_OC0_FastPWM_t          OC0_FastPWM;
	TMR0_OC0_PhaseCorrectPWM_t  OC0_PhaseCorrectPWM;
	TMR_CLKSEL_t        		CLOCK;
	u8                 			TMR0_Preload_Value;
	u8						    TMR0_Compare_Value;
	TMR_Technique_t    			Technique;

}TMR0_Conf_t;

/* Timer 1 Configurations */
typedef enum
{
	TMR1_Normal_Mode,
	TMR1_PWM_PhaseCorrect_8bit,
	TMR1_PWM_PhaseCorrect_9bit,
	TMR1_PWM_PhaseCorrect_10bit,
	TMR1_CTC1_Mode,
	TMR1_Fast_PWM_8bit,
	TMR1_Fast_PWM_9bit,
	TMR1_Fast_PWM_10bit,
	TMR1_PHASE_FREQ_Correct1_MODE,
	TMR1_PHASE_FREQ_Correct2_MODE,
	TMR1_PHASE_Correct1_MODE,
	TMR1_PHASE_Correct2_MODE,
	TMR1_CTC2_Mode,
	TMR1_Fast_PWM1_Mode = 14,
	TMR1_Fast_PWM2_Mode,
}TMR1_Mode_t;

typedef enum
{
	TMR1_ChannelA,TMR1_ChannelB
}TMR1_Channel_t;


typedef enum{
	Normal_disconnectedOC1, Toggle_OC1, Clear_OC1, Set_OC1
}TMR1_CTC_NonPWM_t;

typedef enum
{
	TMR1_FastNon_inverting = 2,
	TMR1_FastInverting
}TMR1_FastPWM_t;

typedef enum{
	phCorrPWM_Normal_disconnected, phCorrPWM_Toggle, phCorrPWM_nonInvertOC1, phCorrPWM_InvertedOC1
}TMR1_phCorrPWM_t;


typedef struct
{
	TMR1_Mode_t  		TMR1_Mode;
	TMR1_Channel_t 		TMR1_Channel;
	TMR1_CTC_NonPWM_t	TMR1_CTC_NonPWM;
	TMR1_FastPWM_t		TMR1_FastPWM;
	TMR1_phCorrPWM_t	TMR1_phCorrPWM;
	TMR_Technique_t  	TMR_Technique;
	TMR_CLKSEL_t		TMR_CLKSEL;
    u16                 TMR1_Preload_Value;
	u16					TMR1_Compare_Value;

}TMR1_Conf_t;



/* Timer 0 API's*/
void TMR0_voidInit(TMR0_Conf_t *TMR0_Ptr_Conf);
void TMR0_voidStart(TMR0_Conf_t *TMR0_Ptr_Conf);
void TMR0_voidDeInit(void);
void TMR0_voidSetCallBack(void (*TMR0Ptr2Func) (void));
u8 TMR0_u8GetCounter(void);

/* Timer 1 API's*/
void TMR1_voidInit(TMR1_Conf_t *TMR1_Ptr_Conf);
void TMR1_voidStart(TMR1_Conf_t *TMR1_Ptr_Conf );
void TMR1_voidSetCompareVal(u16 copy_u16CompareValue);
void TMR1_voidSetICRValue(u16 copy_u16ICRValue);
u16 TMR1_u16ReadTCNT1(void);
void TMR1_voidWriteTCNT1(u16 copy_u16TCNT1Value);
void TMR1_voidSetCallBack(void (*TMR1Ptr2Func) (void));



#endif /* COTS_MCAL_TIMERS_TIMER_INTERFACE_H_ */

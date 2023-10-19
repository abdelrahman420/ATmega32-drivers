/*
 * TIMER_PROGRAM.c
 *
 *  Created on: 15Aug.,2023
 *      Author: abdel
 */


#include "../../LIB/STD.h"
#include "../../LIB/BitMath.h"
#include "TIMER_INTERFACE.h"
#include "TIMER_PRIVATE.h"
#include "TIMER_CONFIG.h"

volatile static void (*TMR0Glopal_Ptr2Func)(void) = NULL;
volatile static void (*TMR1Glopal_Ptr2Func)(void) = NULL;

/****************************************************************************************************/
/**************************************** TIMER 0 ***************************************************/
/****************************************************************************************************/
void TMR0_voidInit(TMR0_Conf_t *TMR0_Ptr_Conf)
{
	if(TMR0_Ptr_Conf->Mode == TMR0_Normal_mode || TMR0_Ptr_Conf->Mode == TMR0_Compare_Mood )
	{
		//NON PWM MODE SET FOC0 in TCCR0
		SET_BIT(TCCR0_REG,FOC0_BIT);
	}
	else
	{
		//PWM MODE CLR FOC0 in TCCR0
		CLR_BIT(TCCR0_REG,FOC0_BIT);
	}
	switch(TMR0_Ptr_Conf->Mode)
	{
	case TMR0_Normal_mode:
	{
		CLR_BIT(TCCR0_REG,WGM01_BIT);
		CLR_BIT(TCCR0_REG,WGM00_BIT);
	}
	break;
	case TMR0_PWM_Phase_correct:
	{
		CLR_BIT(TCCR0_REG,WGM01_BIT);
		SET_BIT(TCCR0_REG,WGM00_BIT);
		TCCR0_REG &= 0xcf;
		TCCR0_REG |= ((TMR0_Ptr_Conf->OC0_PhaseCorrectPWM) << 4);
	}
	break;
	case TMR0_Compare_Mood:
	{
		SET_BIT(TCCR0_REG,WGM01_BIT);
		CLR_BIT(TCCR0_REG,WGM00_BIT);
	}
	break;
	case TMR0_Fast_PWM:
	{
		SET_BIT(TCCR0_REG,WGM01_BIT);
		SET_BIT(TCCR0_REG,WGM00_BIT);
		TCCR0_REG &= 0xcf;
		TCCR0_REG |= ((TMR0_Ptr_Conf->OC0_FastPWM) << 4);
	}
	break;
	default:
		break;
	}
	// Clearing Least significant three bits in TCCR0
	TCCR0_REG &= 0xF8;
	//Inserting required clock select
	TCCR0_REG |= TMR0_Ptr_Conf->CLOCK;
	switch(TMR0_Ptr_Conf->Technique)
	{
	case TMR_POLLING:
		break;
	case TMR_INTERRUPT:
	{
		switch(TMR0_Ptr_Conf->Mode)
		{
		case TMR0_Normal_mode: SET_BIT(TIMSK_REG,TOIE0_BIT);
		break;
		case TMR0_Compare_Mood: SET_BIT(TIMSK_REG,OCIE0_BIT);
		break;
		}
	}
	break;
	}
	TCNT0_REG = 0;
}
void TMR0_voidStart(TMR0_Conf_t *TMR0_Ptr_Conf)
{
	switch(TMR0_Ptr_Conf->Mode)
	{
	case TMR0_Normal_mode:
	{
		TCNT0_REG = TMR0_Ptr_Conf->TMR0_Preload_Value;
		switch(TMR0_Ptr_Conf->Technique)
		{
		case TMR_POLLING:
		{
			//WAIT UNTIL TIMER FINISHES COUNTING
			while(GET_BIT(TIFR_REG,TOV0_BIT) == 0);
			//CLEARING FLAG
			SET_BIT(TIFR_REG,TOV0_BIT);
		}
		break;
		case TMR_INTERRUPT:
			break;
		}
	}
	break;
	case TMR0_PWM_Phase_correct:
	{
		TCNT0_REG = TMR0_Ptr_Conf->TMR0_Preload_Value;
		OCR0_REG  = TMR0_Ptr_Conf->TMR0_Compare_Value;
	}
	break;
	case TMR0_Compare_Mood:
	{
		TCNT0_REG = TMR0_Ptr_Conf->TMR0_Preload_Value;
		OCR0_REG  = TMR0_Ptr_Conf->TMR0_Compare_Value;
		switch(TMR0_Ptr_Conf->Technique)
		{
		case TMR_POLLING:
		{
			//WAIT UNTIL TIMER FINISHES COUNTING
			while(GET_BIT(TIFR_REG,OCF0_BIT) == 0);
			//CLEARING FLAG
			SET_BIT(TIFR_REG,OCF0_BIT);
		}
		break;
		case TMR_INTERRUPT:
			break;
		}
	}
	break;
	case TMR0_Fast_PWM:
	{
		TCNT0_REG = TMR0_Ptr_Conf->TMR0_Preload_Value;
		OCR0_REG  = TMR0_Ptr_Conf->TMR0_Compare_Value;
	}
	break;
	default:
		break;
	}
}
void TMR0_voidDeInit(void)
{
	TCCR0_REG  = 0;
	TCNT0_REG  = 0;
	TIMSK_REG &= 0xFC;
	OCR0_REG   = 0;
}
u8 TMR0_u8GetCounter(void)
{
	return TCNT0_REG;
}
void TMR0_SetCallBack(void (*Ptr2Func) (void))
{

	TMR0Glopal_Ptr2Func = Ptr2Func;
}


void __vector_10_(void) __attribute__((signal));
void __vector_10_(void)
{
	if(TMR0Glopal_Ptr2Func != NULL)
	{
		TMR0Glopal_Ptr2Func();
	}
}

/****************************************************************************************************/
/**************************************** TIMER 1 ***************************************************/
/****************************************************************************************************/

void TMR1_voidInit(TMR1_Conf_t *TMR1_Ptr_Conf)
{

	if(TMR1_Ptr_Conf->TMR1_Mode == TMR1_Normal_Mode || TMR1_Ptr_Conf->TMR1_Mode == TMR1_CTC1_Mode)
	{
		SET_BIT(TCCR1A_REG,FOC1A_BIT);
		SET_BIT(TCCR1A_REG,FOC1B_BIT);
	}
	else
	{
		CLR_BIT(TCCR1A_REG,FOC1A_BIT);
		CLR_BIT(TCCR1A_REG,FOC1B_BIT);
	}
	/*Choosing mode */
	TCCR1A_REG &= 0xFC;
	TCCR1A_REG |= (TMR1_Ptr_Conf->TMR1_Mode & 0x15);
	TCCR1B_REG &= 0xE7;
	TCCR1B_REG |=  (3 << ((TMR1_Ptr_Conf->TMR1_Mode >> 2) & 0x15));

	switch(TMR1_Ptr_Conf->TMR1_Channel){
	case TMR1_ChannelA:
		if(TMR1_Ptr_Conf->TMR1_Mode == TMR1_Normal_Mode || TMR1_Ptr_Conf->TMR1_Mode == TMR1_CTC1_Mode ){
			TCCR1A_REG &= 0x3f;
			TCCR1A_REG |= TMR1_Ptr_Conf->TMR1_CTC_NonPWM << 6;
		}
		else if(TMR1_Ptr_Conf->TMR1_Mode == TMR1_Fast_PWM_8bit || TMR1_Ptr_Conf->TMR1_Mode ==TMR1_Fast_PWM_9bit || TMR1_Ptr_Conf->TMR1_Mode == TMR1_Fast_PWM_10bit || TMR1_Ptr_Conf->TMR1_Mode == TMR1_Fast_PWM2_Mode )
		{
			TCCR1A_REG &= 0x3f;
			TCCR1A_REG |= TMR1_Ptr_Conf->TMR1_FastPWM << 6;
		}

		else if(TMR1_Ptr_Conf->TMR1_Mode == TMR1_PWM_PhaseCorrect_8bit || TMR1_Ptr_Conf->TMR1_Mode == TMR1_PWM_PhaseCorrect_9bit || TMR1_Ptr_Conf->TMR1_Mode == TMR1_PWM_PhaseCorrect_10bit
				|| TMR1_Ptr_Conf->TMR1_Mode == TMR1_PHASE_Correct2_MODE || TMR1_Ptr_Conf->TMR1_Mode == TMR1_PHASE_FREQ_Correct2_MODE){
			TCCR1A_REG &= 0x3f;
			TCCR1A_REG |= TMR1_Ptr_Conf->TMR1_phCorrPWM << 6;
		}
		break;
	case TMR1_ChannelB:
		if(TMR1_Ptr_Conf->TMR1_Mode == TMR1_Normal_Mode || TMR1_Ptr_Conf->TMR1_Mode == TMR1_CTC1_Mode){
			TCCR1A_REG &= 0xCf;
			TCCR1A_REG |= TMR1_Ptr_Conf->TMR1_CTC_NonPWM << 4;
		}
		else if(TMR1_Ptr_Conf->TMR1_Mode == TMR1_Fast_PWM_8bit || TMR1_Ptr_Conf->TMR1_Mode ==TMR1_Fast_PWM_9bit || TMR1_Ptr_Conf->TMR1_Mode == TMR1_Fast_PWM_10bit || TMR1_Ptr_Conf->TMR1_Mode == TMR1_Fast_PWM2_Mode )
		{
			TCCR1A_REG &= 0xCf;
			TCCR1A_REG |= TMR1_Ptr_Conf->TMR1_CTC_NonPWM << 4;
		}

		else if(TMR1_Ptr_Conf->TMR1_Mode == TMR1_PWM_PhaseCorrect_8bit || TMR1_Ptr_Conf->TMR1_Mode == TMR1_PWM_PhaseCorrect_9bit || TMR1_Ptr_Conf->TMR1_Mode == TMR1_PWM_PhaseCorrect_10bit
				|| TMR1_Ptr_Conf->TMR1_Mode == TMR1_PHASE_Correct2_MODE || TMR1_Ptr_Conf->TMR1_Mode == TMR1_PHASE_FREQ_Correct2_MODE){
			TCCR1A_REG &= 0xCf;
			TCCR1A_REG |= TMR1_Ptr_Conf->TMR1_CTC_NonPWM << 4;
		}
		break;
	}

	TCCR1B_REG &=0xf8;
	TCCR1B_REG |= TMR1_Ptr_Conf->TMR_CLKSEL;

	switch(TMR1_Ptr_Conf->TMR_Technique){
	case TMR_POLLING:
		break;
	case TMR_INTERRUPT:
		if(TMR1_Ptr_Conf->TMR1_CTC_NonPWM == TMR1_Normal_Mode)
		{
			SET_BIT(TIMSK_REG,TOIE1_BIT);
		}
		else if (TMR1_Ptr_Conf->TMR1_CTC_NonPWM == TMR1_CTC1_Mode ){
			switch(TMR1_Ptr_Conf->TMR1_Channel){
			case TMR1_ChannelA:
				SET_BIT(TIMSK_REG,OCIE1A_BIT);
				break;
			case TMR1_ChannelB:
				SET_BIT(TIMSK_REG,OCIE1B_BIT);
				break;
			}
		}
	}

	TCNT1_REG = 0;
	OCR1A_REG = 0;
	OCR1B_REG = 0;
}
void TMR1_voidStart(TMR1_Conf_t *TMR1_Ptr_Conf )
{
	switch(TMR1_Ptr_Conf->TMR1_Channel)
	{
		case TMR1_ChannelA:
		{
			switch(TMR1_Ptr_Conf->TMR1_Mode)
			{
				case TMR1_Normal_Mode:
				{
					TCNT1_REG	= TMR1_Ptr_Conf->TMR1_Preload_Value;
					switch(TMR1_Ptr_Conf->TMR_Technique)
					{
						case TMR_POLLING:
						{
							//wait till flag
							while(GET_BIT(TIFR_REG,TOV1_BIT) ==0);
							//clear flag
							SET_BIT(TIFR_REG,TOV1_BIT);
						}
						break;
						case TMR_INTERRUPT:
						{
							//ISR Will Do The Work
						}
						break;
					}
				}
				break;
				case TMR1_CTC1_Mode:
				{
					OCR1A_REG	= TMR1_Ptr_Conf->TMR1_Compare_Value;
					TCCR1A_REG &=0x3F;
					TCCR1A_REG |= ((TMR1_Ptr_Conf->TMR1_CTC_NonPWM)<<6);

					switch(TMR1_Ptr_Conf->TMR_Technique)
					{
						case TMR_POLLING:
						{
							//wait till flag
							while(GET_BIT(TIFR_REG,OCF1A_BIT) ==0);
							//clear flag
							SET_BIT(TIFR_REG,OCF1A_BIT);
						}
						break;
						case TMR_INTERRUPT:
						{
						//ISR Will Do The Work
						}
					}
				}
				break;
				case TMR1_PHASE_Correct1_MODE:
				{
					OCR1A_REG	= TMR1_Ptr_Conf->TMR1_Compare_Value;
					TCCR1A_REG &=0x3F;
					TCCR1A_REG |= ((TMR1_Ptr_Conf->TMR1_phCorrPWM)<<6);
				}
				break;
				case TMR1_Fast_PWM1_Mode:
				{
					OCR1A_REG	= TMR1_Ptr_Conf->TMR1_Compare_Value;
					TCCR1A_REG &=0x3F;
					TCCR1A_REG |= ((TMR1_Ptr_Conf->TMR1_FastPWM)<<6);
				}
				break;
			}
			break;
			case TMR1_ChannelB:
			{
				switch(TMR1_Ptr_Conf->TMR1_Mode)
				{
					case TMR1_Normal_Mode:
					{
						TCNT1_REG	= TMR1_Ptr_Conf->TMR1_Preload_Value;
						switch(TMR1_Ptr_Conf->TMR_Technique)
						{
							case TMR_POLLING:
							{
								//wait till flag
								while(GET_BIT(TIFR_REG,TOV1_BIT) ==0);
								//clear flag
								SET_BIT(TIFR_REG,TOV1_BIT);
							}
							break;
							case TMR_INTERRUPT:
							{
								//ISR Will Do The Work
							}
							break;
						}
					}
					break;
					case TMR1_CTC1_Mode:
					{
						OCR1A_REG	= TMR1_Ptr_Conf->TMR1_Compare_Value;
						TCCR1A_REG &=0xCF;
						TCCR1A_REG |= ((TMR1_Ptr_Conf->TMR1_CTC_NonPWM)<<4);

						switch(TMR1_Ptr_Conf->TMR_Technique)
						{
							case TMR_POLLING:
							{
								//wait till flag
								while(GET_BIT(TIFR_REG,OCF1A_BIT) ==0);
								//clear flag
								SET_BIT(TIFR_REG,OCF1A_BIT);
							}
							break;
							case TMR_INTERRUPT:
							{
							//ISR Will Do The Work
							}
						}
					}
					break;
					case TMR1_PHASE_Correct1_MODE:
					{
						OCR1A_REG	= TMR1_Ptr_Conf->TMR1_Compare_Value;
						TCCR1A_REG &=0xCF;
						TCCR1A_REG |= ((TMR1_Ptr_Conf->TMR1_phCorrPWM)<<4);
					}
					break;
					case TMR1_Fast_PWM1_Mode:
					{
						OCR1A_REG	= TMR1_Ptr_Conf->TMR1_Compare_Value;
						TCCR1A_REG &=0xCF;
						TCCR1A_REG |= ((TMR1_Ptr_Conf->TMR1_FastPWM)<<4);
					}
					break;
				}
				break;
			}
			break;
		}
	}
}

void TMR1_voidSetCompareVal(u16 copy_u16CompareValue)
{
	OCR1A_REG = copy_u16CompareValue;
}
void TMR1_voidSetICRValue(u16 copy_u16ICRValue)
{
	ICR1_REG = copy_u16ICRValue;
}
u16 TMR1_u16ReadTCNT1(void)
{
	return TCNT1_REG;
}
void TMR1_voidWriteTCNT1(u16 copy_u16TCNT1Value)
{
	TCNT1_REG = 0;
}
void TMR1_voidSetCallBack(void (*TMR1Ptr2Func) (void))
{
	TMR1Glopal_Ptr2Func = TMR1Ptr2Func;
}
void __vector_9(void) __attribute__((signal));
void __vector_9(void)
{
	if(TMR1Glopal_Ptr2Func != NULL)
	{
		TMR1Glopal_Ptr2Func();
	}
}








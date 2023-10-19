#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

#include "../../LIB/STD.h"
typedef enum{
	ADC0,
	ADC1,
	ADC2,
	ADC3,
	ADC4,
	ADC5,
	ADC6,
	ADC7
}ADC_channel_t;
typedef enum
{
	AREF,
	AVCC,
	INT256mv = 3

}ADC_RefSel_t;
typedef enum
{
	FCPU_2 = 1,
	FCPU_4,
	FCPU_8,
	FCPU_16,
	FCPU_32,
	FCPU_64,
	FCPU_128
}ADC_Prescaler_t;

typedef struct
{
	ADC_RefSel_t Vref;
	ADC_Prescaler_t Prescaler;
}ADC_Conf_t;
void ADC_voidInit(ADC_Conf_t * Ptr_Conf);
u16 ADC_u16ConvertedValue(ADC_channel_t ChannelNo);


#endif

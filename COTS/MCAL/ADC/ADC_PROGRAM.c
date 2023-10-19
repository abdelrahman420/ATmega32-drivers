#include "../../LIB/STD.h"
#include "../../LIB/BitMath.h"
#include "ADC_INTERFACE.h"
#include "ADC_PRIVATE.h"
#include "ADC_CONFIG.h"


void ADC_voidInit(ADC_Conf_t * Ptr_Conf)
{
	
	//Clearing REFS1 & REFS0 bits
	ADMUX_REG &= 0x3F;
	//Selecting Vref
	ADMUX_REG |= ((Ptr_Conf->Vref & 0x03)<<6);
	//Clearing ADPS0 & ADPS1 & ADPS2
	ADCSRA_REG &= 0xF8;
	//Selecting Prescaler
	ADCSRA_REG |= Ptr_Conf->Prescaler;
	//Enabling ADC
	SET_BIT(ADCSRA_REG,7);
#if ADC_Tech == ADC_POLLING
	CLR_BIT(ADCSRA_REG,ADIE_bit);
#elif ADC_Tech == ADC_INTERRUPT
	SET_BIT(ADCSRA_REG,ADIE_bit);
#endif
}
u16 ADC_u16ConvertedValue(u8 copy_u8Channel)
{
	ADMUX_REG &= 0xE0;
	ADMUX_REG |= (copy_u8Channel & 0x07);

    u16 Local_u16ConvValue = 0;
    //start conversion
    SET_BIT(ADCSRA_REG,ADCSC_bit);
    //PIF = 1 conversion finishes
    while(GET_BIT(ADCSRA_REG,ADCIF_bit)==0){};
    //read data
    Local_u16ConvValue = (ADCL_REG) | (ADCH_REG<<8);
    //clear flag
    SET_BIT(ADCSRA_REG,ADCIF_bit);
    return Local_u16ConvValue;
    
}

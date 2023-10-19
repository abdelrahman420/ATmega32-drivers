#include "../../LIB/STD.h"
#include "../../LIB/BitMath.h"
#include "USART_INTERFACE.h"
#include "USART_PRIVATE.h"
#include "USART_CONFIG.h"

u16 GlopalSendData = 0;
u16 GlopalReceiveData = 0;

void __vector_13(void) __attribute__((signal));
void __vector_14(void) __attribute__((signal));

void USART_voidInit(u32 copy_u32BaudRate)
{

    u16 copy_u16UBRR;
    //Setting Mode
    #if ModeSel == SC
    SET_BIT(UCSRC_REG,UMSEL_BIT);
    #elif ModeSel == ASC
    CLR_BIT(UCSRC_REG,UMSEL_BIT);
    #endif

    //Setting Frame format
    #if Char_Size == Five_Bits       //Character size is 5 bits
    CLR_BIT(UCSRC_REG,UCSZ0_BIT);
    CLR_BIT(UCSRC_REG,UCSZ1_BIT);
    CLR_BIT(UCSRB_REG,UCSZS2_BIT);
    #elif Char_Size == Six_Bits      //Character size is 6 bits
    SET_BIT(UCSRC_REG,UCSZ0_BIT);
    CLR_BIT(UCSRC_REG,UCSZ1_BIT);
    CLR_BIT(UCSRB_REG,UCZSS2_BIT);
    #elif Char_Size == Seven_Bits    //Character size is 7 bits
    CLR_BIT(UCSRC_REG,UCSZ0_BIT);
    SET_BIT(UCSRC_REG,UCSZ1_BIT);
    CLR_BIT(UCSRB_REG,UCSZS2_BIT);
    #elif Char_Size == Eight_Bits    //Character size is 8 bits
    SET_BIT(UCSRC_REG,UCSZ0_BIT);
    SET_BIT(UCSRC_REG,UCSZ1_BIT);
    CLR_BIT(UCSRB_REG,UCSZ2_BIT);
    #elif Char_Size == Nine_Bits     //Character size is 9 bits
    SET_BIT(UCSRC_REG,UCSZ0_BIT);
    SET_BIT(UCSRC_REG,UCSZ1_BIT);
    SET_BIT(UCSRB_REG,UCSZ2_BIT);
    #endif

    //Setting Stop bit modes
    #if StopBit == SB1             //Using 1 stop bit
    CLR_BIT(UCSRC_REG,USBS_BIT);
    #elif StopBit == SB2           //Using 2 stop bits
    SET_BIT(UCSRC_REG,USBS_BIT);
    #endif

    //Setting Parity check
    #if ParitySelect == DP
    CLR_BIT(UCSRC_REG,UPM0_BIT);
    CLR_BIT(UCSRC_REG,UPM1_BIT);
    #elif ParitySelect == EP
    CLR_BIT(UCSRC_REG,UPM0_BIT);
    SET_BIT(UCSRC_REG,UPM1_BIT);
    #elif ParitySelect == OP
    SET_BIT(UCSRC_REG,UPM0_BIT);
    SET_BIT(UCSRC_REG,UPM1_BIT);
    #endif

    //Enabling transmitting and Receiving
    SET_BIT(UCSRB_REG,TXEN_BIT);   //Enable transmitting
    SET_BIT(UCSRB_REG,RXEN_BIT);   //Enable receiving

    //Selecting Baud rate
    CLR_BIT(UCSRC_REG,URSEL_BIT); //Setting the URSEL bit to 0 to make sure iam writting on UBRRH register.

    #if ASC_Mode == Normal_ASC
    CLR_BIT(UCSRA_REG,U2X_BIT);
    copy_u16UBRR = (((F_CPU / (copy_u32BaudRate * 16UL))) - 1);
    #elif ASC_Mode == Fast_ASC
    SET_BIT(UCSRA_REG,U2X_BIT);
    copy_u16UBRR = (((F_CPU / (copy_u32BaudRate * 8UL))) - 1);
    #endif

    UBRRH_REG = (u8)(copy_u16UBRR>>8);
    UBRRL_REG = (u8)copy_u16UBRR;
}
void USART_voidSendData(u16 copy_u16Data)
{
    #if Char_Size == Nine_Bits
    while(GET_BIT(UCSRA_REG,UDRE_BIT) != 1);
    TXB8_BIT = (copy_u16Data>>8);
    UDR_REG = copy_u16Data;
    #else
    while(GET_BIT(UCSRA_REG,UDRE_BIT) != 1);
    UDR_REG = copy_u16Data;

    #endif


}
u16 USART_u16ReceiveData(void)
{

    u16 copy_u16RecievedDate;
    u8 NinthBit;
    #if Char_Size == Nine_Bits
    while(GET_BIT(UCSRA_REG,RXC_BIT) != 1);
    NinthBit =GET_BIT(UCSRA_REG,RXC_BIT);
    copy_u16RecievedDate = (NinthBit<<8);
    copy_u16RecievedDate |= UDR_REG;
    #else
    while(GET_BIT(UCSRA_REG,RXC_BIT) != 1);
    copy_u16RecievedDate = UDR_REG;
    #endif
    return copy_u16RecievedDate;
}

void USART_voidSendString(u8 *copy_u8String)
{
	u8 i = 0;
	while(copy_u8String[i] != '\0')
	{
		USART_voidSendData(copy_u8String[i]);
		i++;
	}

}
void USART_voidRecieveString(u8 *copy_u8String)
{
	u8 i = -1;
	while(copy_u8String[i] != '.')
	{
		copy_u8String[++i] = USART_u16ReceiveData();
	}
	copy_u8String[i] ='\0';
}
void USART_voidSendDataAsync(u16 copy_u16Data)
{
	SET_BIT(UCSRB_REG,UDRIE_BIT);
	GlopalSendData = copy_u16Data;
}
u16 USART_u16ReceiveDataAsync(void)
{
	SET_BIT(UCSRB_REG,UDRIE_BIT);
	return UDR_REG;
}

void __vector_14(void)
{

	UDR_REG = GlopalSendData;
	CLR_BIT(UCSRB_REG,UDRIE_BIT);
}
void __vector_13(void)
{

	GlopalReceiveData = UDR_REG;
	CLR_BIT(UCSRB_REG,UDRIE_BIT);
}

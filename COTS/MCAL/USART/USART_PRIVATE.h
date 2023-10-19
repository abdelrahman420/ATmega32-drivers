#ifndef USART_PRIVATE_H
#define USART_PRIVATE_H

#define UDR_REG   *((volatile u8*)0x2C)
#define UCSRA_REG *((volatile u8*)0x2B)

#define RXC_BIT    7   //Flag is set when there is unread data in recieve buffer.
#define TXC_BIT    6   //Flag is set when the data is transmitted out from shift register and there is no new data at UDR.
#define UDRE_BIT   5   //Flag is set if UDR is ready to recieve data
#define FE_BIT     4   //This bit is set if the next character in the receive buffer had a Frame Error when received.
#define DOR_BIT    3   //This bit is set if a Data OverRun condition is detected.
#define PE_BIT     2   //This bit is set if the next character in the receive buffer had a Parity Error.
#define U2X_BIT    1   //When this bit is set it doubles the transfer rate for asynchronous communication. 
#define MPCM_BIT   0   //This bit enables the Multi-processor Communication mode. 


#define UCSRB_REG *((volatile u8*)0x2A)

#define RXCIE_BIT   7   //This bit enables interrupt on the RXC Flag.
#define TXCIE_BIT   6   //This bit enables interrupt on the TXC Flag.
#define UDRIE_BIT   5   //This bit enables interrupt on the UDRE Flag.
#define RXEN_BIT    4   //This bit Enables the USART Reciever.
#define TXEN_BIT    3   //This bit Enables the USART Trasmitter.
#define UCSZ2_BIT   2   //Setting Character size with UCSZ1 and UCSZ0.
#define RXB8_BIT    1   //RXB8 is the ninth data bit of the received character. 
#define TXB8_BIT    0   //TXB8 is the ninth data bit in the character to be transmitted. 


#define UCSRC_REG *((volatile u8*)0x40)

#define URSEL_BIT   7  //The URSEL must be one when writing the UCSRC.
#define UMSEL_BIT   6  //This bit selects between Asynchronous and Synchronous mode of operation.
#define UPM1_BIT    5  //UPM1 and UPM0 These bits enable and set type of parity generation and check.
#define UPM0_BIT    4  
#define USBS_BIT    3  //Stop bit select 1 stop bit or 2 stop bits
#define UCSZ1_BIT   2  //Setting Character size with UCSZ2 and UCSZ0 from 5 to 9 bits.
#define UCSZ0_BIT   1
#define UCPOL_BIT   0  //This bit is used for Synchronous mode only chosing clock . 

#define UBRRL_REG *((volatile u8*)0x29)
#define UBRRH_REG *((volatile u8*)0x40)

/*
The UBRRH contains the four
most significant bits, and the UBRRL contains the 8 least significant bits of the USART baud
rate. Ongoing transmissions by the transmitter and receiver will be corrupted if the baud rate is
changed. Writing UBRRL will trigger an immediate update of the baud rate prescaler.
*/
#endif

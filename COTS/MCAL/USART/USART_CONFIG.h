#ifndef USART_CONFIG_H
#define USART_CONFIG_H


/*Choosing mode Synchronous or Asynchronous
Select ASC for Asynchronous mode
Select SC for Synchronous mode
*/

#define ModeSel  ASC

/*Choossing Parity configurations
Disable Parity Check           Select DP
Enable Even Parity Check       Select EP
Enable ODD Parity Check        Select OP
*/

#define ParitySelect DP

/*Stop Bit Selection 
one bit  SB1 1
Two bits SB2 2
*/

#define StopBit SB1

/*Selecting Character Size
Options are [5 bits,6 bits,7 bits,8 bits,9 bits]
Select Five_Bits for 5 bits Character Size.
Select Six_Bits for 6 bits Character Size.
Select Seven_Bits for 7 bits Character Size.
Select Eight_Bits for 8 bits Character Size.
Select Nine_Bits for 9 bits Character Size.
*/

#define Char_Size  Eight_Bits

/*Selecting  Asynchronous communication Mode
Select Fast_ASC to double the transfer rate
Select Normal_ASC to communicate with normal transfer rate */

#define ASC_Mode  Normal_ASC

/*Selecting Mode of handling Data
  U_POLLING POLLING until flag is Set
  U_INTERRUPT enter ISR when Data is transmitted or received
*/

#define UART_TECHNIQUE UART_POLLING



#endif

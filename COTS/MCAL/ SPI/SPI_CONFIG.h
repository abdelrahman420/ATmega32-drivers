/*
 * SPI_CONFIG.h
 *
 *  Created on: 21Aug.,2023
 *      Author: abdel
 */

#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H
/*SELECTING SPI TECHNIQUE
 * SPI_INTERRUPT
 * SPI_POLLING */

#define SPI_TECHNIQUE SPI_POLLING

/*SELECTING SPI MODE
 * SPI_MASTER if the  device is the master
 * SPI_SLAVE  if the  device is the slave*/

#define SPI_MODE SPI_MASTER

/* SELECTING DATA ORDER MODE
 * LSB Least significant bit is transmitted first
 * MSB Most significant bit is transmitted first*/

#define DATA_ORDER LSB

/*SELCTING CLOCK POLARITY
 * LE_RISING for leading edge rising and trailing edge falling
 * LE_FALLING for leading edge falling and trailing edge rising*/

#define CLK_POLARITY LE_RISING

/*SELECTING CLOCK PHASE
 *LE_SAMPLE for leading edge sample and trailing edge setup
 *LE_SETUP  for leading edge setup and trailing edge sample*/

#define CLK_PHASE LE_SAMPLE

/*SELECTING DATA TRANSFER SPEED
 *NORMAL_SPEED
 *DOUBLE_SPEED */

#define TRANSFER_SPEED NORMAL_SPEED


#endif /* COTS_MCAL__SPI_SPI_CONFIG_H_ */

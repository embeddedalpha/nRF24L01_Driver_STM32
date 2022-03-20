/*
 * nRF24L01.h
 *
 *  Created on: Mar 19, 2022
 *      Author: Kunal
 */

#ifndef NRF24L01_NRF24L01_H_
#define NRF24L01_NRF24L01_H_

#include "main.h"
#include "GPIO/GPIO.h"
#include "SPI/SPI.h"
#include "Console/Console.h"
#include "nRF24L01_Reg.h"

#define nRF24_DEBUG 0

#define nRF24L01_TX_Only_Mode 0
#define nRF24L01_RX_Only_Mode 1
#define nRF24L01_ShockBurst_TX_Mode	2
#define nRF24L01_ShockBurst_RX_Mode	3



#define Enable_Power_Down 1
#define Disable_Power_Down 0
#define Standby_Mode_1 0
#define Standby_Mode_2 1

#define Data_Pipe_0 0
#define Data_Pipe_1 1
#define Data_Pipe_2 2
#define Data_Pipe_3 3
#define Data_Pipe_4 4
#define Data_Pipe_5 5





struct nRF24L01_Config
{
	int mode ;
	int channel;
	int data_rate;
	int payload_size;
	int data_pipe_number;
	int32_t own_address;
	int32_t tx_address_0;
	int32_t tx_address_1;
	int32_t tx_address_2;
	int32_t tx_address_3;
	int32_t tx_address_4;
	int32_t tx_address_5;
	int32_t rx_address_0;
	int32_t rx_address_1;
	int32_t rx_address_2;
	int32_t rx_address_3;
	int32_t rx_address_4;
	int32_t rx_address_5;
	uint8_t *packet;
}
nRF24L01_Config;



void nRF24L01_Init(SPI_TypeDef *nRF24L01);

int nRF24L01_Power_Down_Mode(uint8_t enable_disable);

void nRF24L01_Stanby_Mode(uint8_t mode);

//void nRF24L01_RX_Mode(int data_pipe_number, int address_width, int frequency_channel, int data_rate, int payload_width);
//
//void nRF24L01_TX_Mode(int32_t address, int data_pipe_number, int address_width, int frequency_channel, int data_rate, int payload_width);
//
//void nRF24L01_Transmit_Packet(uint32_t address, uint8_t data_pipe_number, uint8_t *packet, int payload_width);

#endif /* NRF24L01_NRF24L01_H_ */

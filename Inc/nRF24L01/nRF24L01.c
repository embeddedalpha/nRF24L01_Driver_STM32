/*
 * nRF24L01.c
 *
 *  Created on: Mar 19, 2022
 *      Author: Kunal
 */


#include "nRF24L01.h"

SPI_Config nRF24L01;


//static void nRF24L01_Write_Register(uint8_t reg_address, uint8_t data)
//{
//	SPI_CSS_High(nRF24L01);
//	SPI_CSS_Low(nRF24L01);
//	SPI_Send_Data(nRF24L01, (NRF24L01_CMD_W_REGISTER & reg_address));
//	SPI_Send_Data(nRF24L01, data);
//	SPI_CSS_High(nRF24L01);
//}
//
//static int nRF24L01_Read_Register(uint8_t reg_address)
//{
//	int temp;
//	SPI_CSS_High(nRF24L01);
//	SPI_CSS_Low(nRF24L01);
//	SPI_Send_Data(nRF24L01, (NRF24L01_CMD_R_REGISTER & reg_address));
//	temp = SPI_Receive_Data(nRF24L01);
//	SPI_CSS_High(nRF24L01);
//
//}
//
//static void nRF24L01_CE_High(void)
//{
//	GPIOA -> BSRR |= GPIO_BSRR_BS0;
//}
//
//static void nRF24L01_CE_Low(void)
//{
//	GPIOA -> BSRR |= GPIO_BSRR_BR0;
//}

static void nRF24L01_Flush_TX_FIFO(void)
{
	SPI_CSS_High(nRF24L01);
	SPI_CSS_Low(nRF24L01);
	SPI_Send_Data(nRF24L01, NRF24L01_CMD_FLUSH_TX);
	SPI_CSS_High(nRF24L01);
}

static void nRF24L01_Flush_RX_FIFO(void)
{
	SPI_CSS_High(nRF24L01);
	SPI_CSS_Low(nRF24L01);
	SPI_Send_Data(nRF24L01, NRF24L01_CMD_FLUSH_RX);
	SPI_CSS_High(nRF24L01);
}

void nRF24L01_Init(SPI_TypeDef *nRF24L01)
{
	int temp;
	nRF24L01_Power_Down_Mode(Disable_Power_Down);

}


int nRF24L01_Power_Down_Mode(uint8_t enable_disable)
{
	int temp, return_value;
	switch (enable_disable)
	{
		case Enable_Power_Down:
		{
			nRF24L01_Write_Register(NRF24L01_CONFIG, 0x00);
			Delay_ms(2);
			temp = nRF24L01_Read_Register(NRF24L01_CONFIG);
			if((temp & (1 << 1)) == (1 << 1))
			{
				return_value = -1;
			}
			else
			{
				return_value = 1;
			}
		}
			break;

		case Disable_Power_Down:
		{
			nRF24L01_Write_Register(NRF24L01_CONFIG, (1 << 1));
			Delay_ms(2);
			temp = nRF24L01_Read_Register(NRF24L01_CONFIG);
			if((temp & (1 << 1)) != (1 << 1))
			{
				return_value = -1;
			}
			else
			{
				return_value = 1;
			}
		}
			break;

	}
}


void nRF24L01_Stanby_Mode(uint8_t mode)
{
	switch (mode)
	{
		case Standby_Mode_1:
		{

		}
			break;

		case Standby_Mode_2:
		{

		}
			break;

	}
}

void nRF24L01_RX_Mode(int data_pipe_number, int address_width, int frequency_channel, int data_rate, int payload_width)
{
	nRF24L01_CE_Low();
	//CONFIGURE CRC
	//SET PWR_UP AND PRIM_RX BIT TO 1
	nRF24L01_Write_Register(NRF24L01_CONFIG, 0x03);
	//Disable auto ack on data pipe
	nRF24L01_Write_Register(NRF24L01_EN_AA, 0 << data_pipe_number);
	//Same address width as transmitter device
	nRF24L01_Write_Register(NRF24L01_SETUP_AW, address_width);
	//Same frequency channel as transmitter device
	nRF24L01_Write_Register(NRF24L01_RF_CH, frequency_channel);
	//Same data rate as transmitter
	nRF24L01_Write_Register(NRF24L01_SETUP_AW, data_rate);

	switch (data_pipe_number) {
		case Data_Pipe_0:
		{
			nRF24L01_Write_Register(NRF24L01_RX_PW_P0, payload_width);
		}
			break;
		case Data_Pipe_1:
		{
			nRF24L01_Write_Register(NRF24L01_RX_PW_P1, payload_width);
		}
			break;
		case Data_Pipe_2:
		{
			nRF24L01_Write_Register(NRF24L01_RX_PW_P2, payload_width);
		}
			break;
		case Data_Pipe_3:
		{
			nRF24L01_Write_Register(NRF24L01_RX_PW_P3, payload_width);
		}
			break;
		case Data_Pipe_4:
		{
			nRF24L01_Write_Register(NRF24L01_RX_PW_P4, payload_width);
		}
			break;
		case Data_Pipe_5:
		{
			nRF24L01_Write_Register(NRF24L01_RX_PW_P5, payload_width);
		}
			break;
		default:
		{
			nRF24L01_Write_Register(NRF24L01_RX_PW_P0, payload_width);
		}
			break;
	}

	nRF24L01_CE_High();


}

void nRF24L01_TX_Mode(int32_t address, int data_pipe_number, int address_width, int frequency_channel, int data_rate, int payload_width)
{
	nRF24L01_CE_Low();
	nRF24L01_Write_Register(NRF24L01_CONFIG, 0x00);
	nRF24L01_Write_Register(NRF24L01_SETUP_RETR, 0x00);
	nRF24L01_Write_Register(NRF24L01_EN_AA, 0 << data_pipe_number);
	//Same address width as transmitter device
	nRF24L01_Write_Register(NRF24L01_SETUP_AW, address_width);
	//Same frequency channel as transmitter device
	nRF24L01_Write_Register(NRF24L01_RF_CH, frequency_channel);
	//Same data rate as transmitter
	nRF24L01_Write_Register(NRF24L01_SETUP_AW, data_rate);
	nRF24L01_Power_Down_Mode(Disable_Power_Down);

}

void nRF24L01_Transmit_Packet(uint32_t address, uint8_t data_pipe_number, uint8_t *packet, int payload_width)
{
//	nRF24L01_CE_High();
	//Flush TX FIFO
	nRF24L01_Flush_TX_FIFO();


}


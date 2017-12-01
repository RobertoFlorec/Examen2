/*
 * UART.h
 *
 * 		I.	T.	E.	S.	O.
 * Sistemas con Microcontroladores y DSP's
 *
 *Author: Daniel flores, Alejandrino Ponce, Adrian Ramos
 *
 */


#ifndef SOURCES_UART_H_
#define SOURCES_UART_H_


#include "DataTypeDefinitions.h"
#include "MK64F12.h"

#define SystemClock 21000000
#define MAKE_DECIMAL 0x30

typedef struct{
	uint8 flag;
	uint8 mailBox;
}UART_MailBoxType;

/** Typedef to define UART channel**/
typedef enum {UART_0,UART_1,UART_2,UART_3,UART_4,UART_5}UART_ChannelType;

/** Typedef to define the baud rate**/
typedef enum {BD_4800=4800,BD_9600=9600,BD_5600=5600, BD_115200=115200}UART_BaudRateType;

/** It configures the UART to be used. systemClk is given in Hertz*/
void UART_init(UART_ChannelType uartChannel, uint32 systemClk, UART_BaudRateType baudRate);

/**It enables the UART ISR*/
void UART_interruptEnable(UART_ChannelType uartChannel);

/** It send one character through the serial port*/
void UART_putChar (UART_ChannelType uartChannel, uint8 character);

/*** It a string character through the serial port**/
void UART_putString(UART_ChannelType uartChannel, sint8* string);
/***It checks the*/
uint8 UART_CheckMailBox(UART_ChannelType Channel );
/** PCR and select the settings */
void UART_SetPCR(UART_ChannelType UARTChannel);

uint8 stateCheck(void);
BooleanType checkMailBoxFlag(void);


#endif /* UART_H_ */


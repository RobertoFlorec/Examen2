/*
 * CONVERSION.c
 *
 *  Created on: 30/11/2017
 *      Author: Roberto
 */
#include "DataTypeDefinitions.h"
#include "PIT.h"
#include "GPIO.h"
#include "NVIC.h"
#include "CONVERSION.h"
#include "UART.h"

void init(void){
	GPIO_init(GPIO_B, GPIO_OUTPUT, BIT23);
	UART_SetPCR(UART_0);
	PIT_clockGating();
	NVIC_enableInterruptAndPriotity(PIT_CH0_IRQ, PRIORITY_10);
	EnableInterrupts;

}

void convertToMorse(uint8 text){


convert(text);

}

void GPIO_init(GPIO_portNameType portName,GPIO_PIN_CONFIG gpio,BitsType bit){
	GPIO_pinControlRegisterType pinControlResgisterPORTB = GPIO_MUX1;
	GPIO_clockGating(portName);
	GPIO_pinControlRegister(portName, bit, &pinControlResgisterPORTB);
	GPIO_dataDirectionPIN(portName, gpio, bit);
	GPIO_setPIN(portName, bit);

}


/*
 * CONVERSION.h
 *
 *  Created on: 30/11/2017
 *      Author: Roberto
 */

#ifndef CONVERSION_H_
#define CONVERSION_H_

#define a 0x61
#define b 0x62
#define c 0x63
#define d 0x64
#define e 0x65
#define f 0x66
#define g 0x67
#define h 0x68
#define i 0x69
#define j 0x6A
#define k 0x6B
#define l 0x6C
#define m 0x6D
#define n 0x6E
#define o 0x6F
#define p 0x70
#define q 0x71
#define r 0x72
#define s 0x73
#define t 0x74
#define u 0x75
#define v 0x76
#define w 0x77
#define x 0x78
#define y 0x79
#define z 0x7A
#define ENTER 0X0D

void convertToMorse(uint8 text);
void GPIO_init(GPIO_portNameType portName,GPIO_PIN_CONFIG gpio,BitsType bit);

#endif /* CONVERSION_H_ */

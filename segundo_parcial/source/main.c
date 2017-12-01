/*
 * Copyright (c) 2016, NXP Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of NXP Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
 
/**
 * @file    segundo_parcial.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "UART.h"
#include "MK64F12.h"
#include "GlobalFunctions.h"
#include "CONVERSION.h"
int main(void) {
	init();





	/***********************************************************/
			static uint8 text[100]; /*! Arreglo para guardar lo que se escriba*/
			static uint8 textCounter = 0;
			static uint8 counter;
			uint8 Data;
			while(1){
			UART_putString(UART_0,"\033[2;10H");/** Comando para posicionar el cursor en la posici�n x e y */
			UART_putString(UART_0, "Escribir Texto");/** Imprime secuencia */
			UART_putString(UART_0,"\033[3;10H");


					while(1){/*! se queda esperando datos hasta que se presiona ENTER o ESC*/
						Data = UART_CheckMailBox(UART_0);

						if((Data >= a) && (Data <= z)){/*! si el dato es un letra minuscula, se guarada como parte de la direccion*/
							text[textCounter] = Data;
							textCounter++;
						}
						if(ENTER == Data){/*!cuando se presiona ENTER se guardan los valores y se rompe el loop*/

							for(counter = 0; counter < textCounter; counter++){
								convertToMorse(text[i]);
								delay(65000);
							}
								textCounter = 0;
							break;
						}
						delay(65000);
					}
	/***********************************************************/

    }

    return 0 ;
}

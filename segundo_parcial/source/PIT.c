/*
 * PIT.c
 *
 *  Created on: 19/09/2017
 *      Author: Roberto
 */
#include "PIT.h"

#define PIT_CLOCK_GATING 0x00800000
#define PIT_ON ~(0x3)
#define PIT_OFF 0x2
static uint8 Pit_Interrupt_Flag;


void PIT_delay(PIT_Timer_t pitTimer,float systemClock ,float period){

	float clockPeriod = (1/(systemClock/2));
	float triggerLDVAL = ((period / clockPeriod));
	PIT->MCR &= PIT_ON;
	PIT->CHANNEL[0].LDVAL = (uint32)(triggerLDVAL - 1);
	PIT->CHANNEL[0].TCTRL |= PIT_TCTRL_TIE_MASK | PIT_TCTRL_TEN_MASK;


}

void PIT_clockGating(void){
	SIM->SCGC6 |= PIT_CLOCK_GATING;
}

uint8 PIT_getIntrStatus(void){

	return Pit_Interrupt_Flag;
}

void PIT_clear(void){
	Pit_Interrupt_Flag = FALSE;

}

void PIT0_IRQHandler(void){

	PIT->CHANNEL[0].TFLG |= PIT_TFLG_TIF_MASK;
	PIT->CHANNEL[0].TFLG; //read control register for clear PIT flag, this is silicon bug
	PIT->CHANNEL[0].TCTRL &= ~(PIT_TCTRL_TIE_MASK);//enables PIT timer interrupt
	PIT->CHANNEL[0].TCTRL &= ~(PIT_TCTRL_TEN_MASK);//enables timer0
	PIT->MCR = PIT_OFF;
	Pit_Interrupt_Flag = TRUE;
}


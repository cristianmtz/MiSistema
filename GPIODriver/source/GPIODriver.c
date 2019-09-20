/*
 * Copyright 2016-2018 NXP Semiconductor, Inc.
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
 * @file    GPIODriver.c
 * @brief   Application entry point.
 */

/********************************************************
*	Author:			B.Chavoya, C.Martinez				*
*	File Name:		GPIODriver.c      					*
*   Description:										*
*   This file initializes all the KL27 pins     		*
*   that are necessary to activate buttons, displays	*
*	and the KL27 LED.									*
********************************************************/

/****** Include Section *******/
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL27Z644.h"
#include "fsl_debug_console.h"

#include "GPIODriver.h"

/****** Global Variables *******/


/****** Local Variables *******/





/****** Local Functions *******/

void Port_Init_Configuration_LED (void)
  {
    SIM->SCGC5 |= (1 << 10); //SYSTEM CLOCK GATE 5
	GPIOB->PDDR = (1<<18); //PTB18
	PORTB->PCR[18] = PORT_PCR_MUX(1);	//PTB18
	GPIOB->PDOR = (1<<18); //PTB18
  }




  /** @brief
   *
   *  This function sets all the Port Data Input Registers, Port Output Registers, Port Data Direction Registers,
   *  System Clock Gate and the Port Control registers of all GPIOS
   *
   *  @return void
   */
  void Port_Init_Configuration (void)
  {
	    ///////////////////////////////////////////
	    ///////////PDOR///////////////////////////
	    ///////////////////////////////////////////
	    /*DISPLAYS SEGMENTS PDOR*/
	    GPIOB->PDOR = (1<<3); //PTB2
	    GPIOD->PDOR = (1<<0); //PTD0
	    GPIOD->PDOR = (1<<1); //PTD1
	    GPIOD->PDOR = (1<<2); //PTD2
	    GPIOD->PDOR = (1<<3); //PTD3
	    GPIOD->PDOR = (1<<4); //PTD4
	    GPIOD->PDOR = (1<<5); //PTD5

	    /*DISPLAY PDOR*/
	    GPIOC->PDOR = (1<<10); //PTC10
	    GPIOC->PDOR = (1<<11); //PTC11
	    GPIOE->PDOR = (1<<0); //PTE0
	    GPIOE->PDOR = (1<<1); //PTE1



	    ///////////////////////////////////////////
	    ///////////PDDR///////////////////////////
	    ///////////////////////////////////////////
	    /*BUTTON PDDR*/
	    GPIOC->PDDR = (1<<3); //PTC3
	    GPIOB->PDDR = (1<<3); //PTB3
	    GPIOB->PDDR = (1<<16); //PTB16
	    GPIOC->PDDR = (1<<17); //PTB17
	    GPIOC->PDDR = (1<<1); //PTC1
	    GPIOC->PDDR = (1<<2); //PTC2


	    /*DISPLAYS SEGMENTS PDDR*/
	    GPIOB->PDDR = (1<<3); //PTB2
	    GPIOD->PDDR = (1<<0); //PTD0
	    GPIOD->PDDR = (1<<1); //PTD1
	    GPIOD->PDDR = (1<<2); //PTD2
	    GPIOD->PDDR = (1<<3); //PTD3
	    GPIOD->PDDR = (1<<4); //PTD4
	    GPIOD->PDDR = (1<<5); //PTD5



	    /*DISPLAY PDDR*/
	    GPIOC->PDDR = (1<<10); //PTC10
	    GPIOC->PDDR = (1<<11); //PTC11
	    GPIOE->PDDR = (1<<0); //PTE0
	    GPIOE->PDDR = (1<<1); //PTE1



	    ///////////////////////////////////////////
	    ///////////PCR///////////////////////////
	    ///////////////////////////////////////////
	    /*BUTTON PCR*/
	    PORTC->PCR[3] = PORT_PCR_MUX(1);	//PTC3
	    PORTB->PCR[3] = PORT_PCR_MUX(1);	//PTB3
	    PORTB->PCR[16] = PORT_PCR_MUX(1);	//PTB16
	    PORTB->PCR[17] = PORT_PCR_MUX(1);	//PTB17
	    PORTC->PCR[1] = PORT_PCR_MUX(1);	//PTC1
	    PORTC->PCR[2] = PORT_PCR_MUX(1);	//PTC2



	    /*DISPLAYS SEGMENTS PCR*/
	     PORTB->PCR[2] = PORT_PCR_MUX(1);		//PTB2
	     PORTD->PCR[0] = PORT_PCR_MUX(1);		//PTD0
	     PORTD->PCR[1] = PORT_PCR_MUX(1);		//PTD1
	     PORTD->PCR[2] = PORT_PCR_MUX(1);		//PTD2
	     PORTD->PCR[3] = PORT_PCR_MUX(1);		//PTD3
	     PORTD->PCR[4] = PORT_PCR_MUX(1);		//PTD4
	     PORTD->PCR[5] = PORT_PCR_MUX(1);		//PTD4

	     /*DISPLAY PCR*/
	     PORTC->PCR[10] = PORT_PCR_MUX(1);		//PTC10
	     PORTC->PCR[11] = PORT_PCR_MUX(1);	    //PTC11
	     PORTE->PCR[0] = PORT_PCR_MUX(1);		//PTE0
	     PORTE->PCR[1] = PORT_PCR_MUX(1);		//PTE1

  }

/* PARTE PAUL*/
  typedef enum
  {
	  enPORTBPIN2 = 0,
	  enPORTBPIN3,
	  enPORTBPIN16,
	  enPORTBPIN17,
	  enPORTCPIN1,
	  enPORTCPIN2,
	  enPORTCPIN3,
	  enPORTCPIN10,
	  enPORTCPIN11,
	  enPORTDPIN0,
	  enPORTDPIN1,
	  enPORTDPIN2,
	  enPORTDPIN3,
	  enPORTDPIN4,
	  enPORTDPIN5,
	  enPORTEPIN0,
	  enPORTEPIN1,
	  enTotalPins
  }tenMyPins;


 typedef struct
 {
	 tenMyPins enMyPin;
	 uint32_t  *pu32Address;
	 uint8_t   u8InputOrOutput;
 }tstMyPins;


//tstMyPins stMyPinsConfig[enTotalPins] = INIT_STRUCT;


  void Output ( uint8_t u8Output, tenMyPins enCurrentPin )
  {
	  if( u8Output == 1 		&& 		stMyPinsConfig[enCurrentPin].u8InputOrOutput == 1)
	  {
		  *stMyPinsConfig[enCurrentPin].pu32Address |= (1 << stMyPinsConfig[enCurrentPin].enMyPin);
		  //GPIOA->PDOR//
	  }
	  else
	  {
		  //u8Port &= ~(1 << u8Pin);
	  }
  }

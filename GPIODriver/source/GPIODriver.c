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

/****** Global Variables *******/


/****** Local Variables *******/





/****** Local Functions *******/

/** @brief This function is to configure System Clock Gate 5
  *  @return void
  */
  static void SCGC5_Configuration (void)
  {
	  /*volatile uint32_t *pdwSCGC5 = (volatile uint32_t*)SCGC5;
	  *pdwSCGC5 |= (1<<10);*/
	  SIM->SCGC5 |= (1 << 10); //Equivalencia
  }


  /** @brief This function sets all the Port Data Input Registers
   *  @return void
   *  */
  void Port_Data_Input_Registers (void)
  {
	  /*BUTTON PDIR*/
	  volatile uint32_t *pdwGPIO_PDIR_BUTTON_1 = (volatile uint32_t*); //PTC3
	  *pdwGPIO_PDIR_BUTTON_1 |=(1<<3);
	  volatile uint32_t *pdwGPIO_PDIR_BUTTON_2 = (volatile uint32_t*); //PTB3
	  *pdwGPIO_PDIR_BUTTON_2 |=(1<<3);
	  volatile uint32_t *pdwGPIO_PDIR_BUTTON_3 = (volatile uint32_t*); //PTB16
	  *pdwGPIO_PDIR_BUTTON_3 |=(1<<16);
	  volatile uint32_t *pdwGPIO_PDIR_BUTTON_4 = (volatile uint32_t*); //PTB17
	  *pdwGPIO_PDIR_BUTTON_4 |=(1<<17);
	  volatile uint32_t *pdwGPIO_PDIR_BUTTON_5 = (volatile uint32_t*); //PTC1
	  *pdwGPIO_PDIR_BUTTON_5 |=(1<<1);
	  volatile uint32_t *pdwGPIO_PDIR_BUTTON_6 = (volatile uint32_t*); //PTC2
	  *pdwGPIO_PDIR_BUTTON_6 |=(1<<2);

	  /*BUTTON PDIR*/



  }

 /** @brief This function sets all the Port Output Registers (not including the LED PDOR)
  *  @return void
  */

  void Port_Data_Output_Registers (void)
  {
	  /*display segments PDOR*/
	  	  volatile uint32_t *pdwGPIO_PDOR_DISPLAY_SEGMENT_1 = (volatile uint32_t*); //PTB2
	      *pdwGPIO_PDDR_DISPLAY_SEGMENT_1 |=(1<<2);
	      volatile uint32_t *pdwGPIO_PDOR_DISPLAY_SEGMENT_2 = (volatile uint32_t*); //PTD0
	      *pdwGPIO_PDDR_DISPLAY_SEGMENT_2 |=(1<<0);
	      volatile uint32_t *pdwGPIO_PDOR_DISPLAY_SEGMENT_3 = (volatile uint32_t*); //PTD1
	      *pdwGPIO_PDDR_DISPLAY_SEGMENT_3 |=(1<<1);
	      volatile uint32_t *pdwGPIO_PDOR_DISPLAY_SEGMENT_4 = (volatile uint32_t*); //PTD2
	      *pdwGPIO_PDDR_DISPLAY_SEGMENT_4 |=(1<<2);
	      volatile uint32_t *pdwGPIO_PDOR_DISPLAY_SEGMENT_5 = (volatile uint32_t*); //PTD3
	      *pdwGPIO_PDDR_DISPLAY_SEGMENT_5 |=(1<<3);
	      volatile uint32_t *pdwGPIO_PDOR_DISPLAY_SEGMENT_6 = (volatile uint32_t*); //PTD4
	      *pdwGPIO_PDDR_DISPLAY_SEGMENT_6 |=(1<<4);
	      volatile uint32_t *pdwGPIO_PDOR_DISPLAY_SEGMENT_7 = (volatile uint32_t*); //PTD5
	      *pdwGPIO_PDDR_DISPLAY_SEGMENT_7 |=(1<<5);

	      /*DISPLAYs PDOR*/
	          volatile uint32_t *pdwGPIO_PDOR_DISPLAY_1 = (volatile uint32_t*); //PTC10
	          *pdwGPIO_PDDR_DISPLAY_1 |= (1<<10);
	          volatile uint32_t *pdwGPIO_PDOR_DISPLAY_2 = (volatile uint32_t*); //PTC11
	          *pdwGPIO_PDDR_DISPLAY_2 |= (1<<11);
	          volatile uint32_t *pdwGPIO_PDOR_DISPLAY_3 = (volatile uint32_t*); //PTE0
	          *pdwGPIO_PDDR_DISPLAY_3 |= (1<<0);
	          volatile uint32_t *pdwGPIO_PDOR_DISPLAY_4 = (volatile uint32_t*); //PTE1
	          *pdwGPIO_PDDR_DISPLAY_4 |= (1<<1);


  }




 /** @brief his function is to configure the pins (PCR, PDDR)
  *  @return void
  */
  static void Pin_Configurations (void)
  {
	/*LED CONFIG*/
  	volatile uint32_t *pdwGPIO_PDDR_RED_LED = (volatile uint32_t*);
    volatile uint32_t *pdwMUX_RED_LED = (volatile uint32_t*);
    *pdwMUX_RED_LED |= (1<<8);
    *pdwGPIO_PDDR_RED_LED |= (1<<18);


    /*BUTTON PDDR*/
    volatile uint32_t *pdwGPIO_PDDR_BUTTON_1 = (volatile uint32_t*); //PTC3
    *pdwGPIO_PDDR_BUTTON_1 |=(1<<3);
    volatile uint32_t *pdwGPIO_PDDR_BUTTON_2 = (volatile uint32_t*); //PTB3
    *pdwGPIO_PDDR_BUTTON_2 |=(1<<3);
    volatile uint32_t *pdwGPIO_PDDR_BUTTON_3 = (volatile uint32_t*); //PTB16
    *pdwGPIO_PDDR_BUTTON_3 |=(1<<16);
    volatile uint32_t *pdwGPIO_PDDR_BUTTON_4 = (volatile uint32_t*); //PTB17
    *pdwGPIO_PDDR_BUTTON_4 |=(1<<17);
    volatile uint32_t *pdwGPIO_PDDR_BUTTON_5 = (volatile uint32_t*); //PTC1
    *pdwGPIO_PDDR_BUTTON_5 |=(1<<1);
    volatile uint32_t *pdwGPIO_PDDR_BUTTON_6 = (volatile uint32_t*); //PTC2
    *pdwGPIO_PDDR_BUTTON_6 |=(1<<2);

    /*DISPLAYS SEGMENTS PDDR*/
       volatile uint32_t *pdwGPIO_PDDR_DISPLAY_SEGMENT_1 = (volatile uint32_t*); //PTB2
       *pdwGPIO_PDDR_DISPLAY_SEGMENT_1 |=(1<<2);
       volatile uint32_t *pdwGPIO_PDDR_DISPLAY_SEGMENT_2 = (volatile uint32_t*); //PTD0
       *pdwGPIO_PDDR_DISPLAY_SEGMENT_2 |=(1<<0);
       volatile uint32_t *pdwGPIO_PDDR_DISPLAY_SEGMENT_3 = (volatile uint32_t*); //PTD1
       *pdwGPIO_PDDR_DISPLAY_SEGMENT_3 |=(1<<1);
       volatile uint32_t *pdwGPIO_PDDR_DISPLAY_SEGMENT_4 = (volatile uint32_t*); //PTD2
       *pdwGPIO_PDDR_DISPLAY_SEGMENT_4 |=(1<<2);
       volatile uint32_t *pdwGPIO_PDDR_DISPLAY_SEGMENT_5 = (volatile uint32_t*); //PTD3
       *pdwGPIO_PDDR_DISPLAY_SEGMENT_5 |=(1<<3);
       volatile uint32_t *pdwGPIO_PDDR_DISPLAY_SEGMENT_6 = (volatile uint32_t*); //PTD4
       *pdwGPIO_PDDR_DISPLAY_SEGMENT_6 |=(1<<4);
       volatile uint32_t *pdwGPIO_PDDR_DISPLAY_SEGMENT_7 = (volatile uint32_t*); //PTD5
       *pdwGPIO_PDDR_DISPLAY_SEGMENT_7 |=(1<<5);


       /*DISPLAY PDDR*/
       volatile uint32_t *pdwGPIO_PDDR_DISPLAY_1 = (volatile uint32_t*); //PTC10
       *pdwGPIO_PDDR_DISPLAY_1 |= (1<<10);
       volatile uint32_t *pdwGPIO_PDDR_DISPLAY_2 = (volatile uint32_t*); //PTC11
       *pdwGPIO_PDDR_DISPLAY_2 |= (1<<11);
       volatile uint32_t *pdwGPIO_PDDR_DISPLAY_3 = (volatile uint32_t*); //PTE0
       *pdwGPIO_PDDR_DISPLAY_3 |= (1<<0);
       volatile uint32_t *pdwGPIO_PDDR_DISPLAY_4 = (volatile uint32_t*); //PTE1
       *pdwGPIO_PDDR_DISPLAY_4 |= (1<<1);

    /***************/
    /***************/
    /*BUTTON PCR*/
    volatile uint32_t *pdwMUX_BUTTON_1 = (volatile uint32_t*); //PTC3
    *pdwMUX_BUTTON_1 |=(1<<8);
    volatile uint32_t *pdwMUX_BUTTON_2 = (volatile uint32_t*); //PTB3
    *pdwMUX_BUTTON_2 |=(1<<8);
    volatile uint32_t *pdwMUX_BUTTON_3 = (volatile uint32_t*); //PTB16
    *pdwMUX_BUTTON_3 |=(1<<8);
    volatile uint32_t *pdwMUX_BUTTON_4 = (volatile uint32_t*); //PTB17
    *pdwMUX_BUTTON_4 |=(1<<8);
    volatile uint32_t *pdwMUX_BUTTON_5 = (volatile uint32_t*); //PTC1
    *pdwMUX_BUTTON_5 |=(1<<8);
    volatile uint32_t *pdwMUX_BUTTON_6 = (volatile uint32_t*); //PTC2
    *pdwMUX_BUTTON_6 |=(1<<8);


    ////////////////////////////////////
    PORTC->PCR[3] = PORT_PCR_MUX(1);	//PTC3
    PORTB->PCR[3] = PORT_PCR_MUX(1);	//PTB3
    PORTB->PCR[16] = PORT_PCR_MUX(1);	//PTB16
    PORTB->PCR[17] = PORT_PCR_MUX(1);	//PTB17
    PORTC->PCR[1] = PORT_PCR_MUX(1);	//PTC1
    PORTC->PCR[2] = PORT_PCR_MUX(1);	//PTC2



    /*DISPLAYS SEGMENTS PCR*/
    	   volatile uint32_t *pdwMUX_DISPLAY_SEGMENT_1 = (volatile uint32_t*); //PTB2
    	   *pdwMUX_DISPLAY_SEGMENT_1 |=(1<<8);
           volatile uint32_t *pdwMUX_DISPLAY_SEGMENT_2 = (volatile uint32_t*); //PTD0
           *pdwMUX_DISPLAY_SEGMENT_2 |=(1<<8);
           volatile uint32_t *pdwMUX_DISPLAY_SEGMENT_3 = (volatile uint32_t*); //PTD1
           *pdwMUX_DISPLAY_SEGMENT_3 |=(1<<8);
           volatile uint32_t *pdwMUX_DISPLAY_SEGMENT_4 = (volatile uint32_t*); //PTD2
           *pdwMUX_DISPLAY_SEGMENT_4 |=(1<<8);
           volatile uint32_t *pdwMUX_DISPLAY_SEGMENT_5 = (volatile uint32_t*); //PTD3
           *pdwMUX_DISPLAY_SEGMENT_5 |=(1<<8);
           volatile uint32_t *pdwMUX_DISPLAY_SEGMENT_6 = (volatile uint32_t*); //PTD4
           *pdwMUX_DISPLAY_SEGMENT_6 |=(1<<8);
           volatile uint32_t *pdwMUX_DISPLAY_SEGMENT_7 = (volatile uint32_t*); //PTD5
           *pdwMUX_DISPLAY_SEGMENT_7 |=(1<<8);

           ////////////////////////////////
           ////////////////////////////////////
           PORTB->PCR[2] = PORT_PCR_MUX(1);		//PTB2
           PORTD->PCR[0] = PORT_PCR_MUX(1);		//PTD0
           PORTD->PCR[1] = PORT_PCR_MUX(1);		//PTD1
           PORTD->PCR[2] = PORT_PCR_MUX(1);		//PTD2
           PORTD->PCR[3] = PORT_PCR_MUX(1);		//PTD3
           PORTD->PCR[4] = PORT_PCR_MUX(1);		//PTD4
           PORTD->PCR[5] = PORT_PCR_MUX(1);		//PTD4



    /*DISPLAY PCR*/
           volatile uint32_t *pdwMUX_DISPLAY_1 = (volatile uint32_t*); //PTC10
           *pdwMUX_DISPLAY_1 |= (1<<8);
           volatile uint32_t *pdwMUX_DISPLAY_2 = (volatile uint32_t*); //PTC11
           *pdwMUX_DISPLAY_2 |= (1<<8);
           volatile uint32_t *pdwMUX_DISPLAY_3 = (volatile uint32_t*); //PTE0
           *pdwMUX_DISPLAY_3 |= (1<<8);
           volatile uint32_t *pdwMUX_DISPLAY_4 = (volatile uint32_t*); //PTE1
           *pdwMUX_DISPLAY_4 |= (1<<8);

           ///////////////////////////
           ///////////////////////////

           ////////////////////////////////
           ////////////////////////////////////
           PORTC->PCR[10] = PORT_PCR_MUX(1);		//PTC10
           PORTC->PCR[11] = PORT_PCR_MUX(1);	    //PTC11
           PORTE->PCR[0] = PORT_PCR_MUX(1);		    //PTE0
           PORTE->PCR[1] = PORT_PCR_MUX(1);		    //PTE1

  }


/****** Global Functions *******/

/** @brief
 *  @param
 *  @param
 *  @return
 */

/** @brief main function
 *  @param none
 *  @return void
 */
int main(void)
{
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
    BOARD_InitDebugConsole();
    volatile uint32_t* pdwPDOR_RED_LED = (volatile uint32_t*);
    uint32_t dwdelay = 0;

      SCGC5_Configuration();
      Pin_Configurations();
      //Port_Output_Registers();

        while(1)
        {
        	dwdelay = 0x000F4240;

        	while(dwdelay--)
        	{

        	}
        	*pdwPDOR_RED_LED ^= (1<<18);

        }
        return 0 ;
}

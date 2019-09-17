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
*	and the KL27 LED.									*										*
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
	  volatile uint32_t *pdwSCGC5 = (volatile uint32_t*)0x40048038;
	  *pdwSCGC5 |= (1<<10);
  }


  /** @brief This function sets all the Port Data Input Registers
   *  @return void
   *  */
  void Port_Data_Input_Registers (void)
  {
	  /*BUTTON PDIR*/
	  volatile uint32_t *pdwGPIO_PDIR_BUTTON_1 = (volatile uint32_t*)0x400FF090; //PTC3
	  *pdwGPIO_PDIR_BUTTON_1 |=(1<<3);
	  volatile uint32_t *pdwGPIO_PDIR_BUTTON_2 = (volatile uint32_t*)0x400FF050; //PTB3
	  *pdwGPIO_PDIR_BUTTON_2 |=(1<<3);
	  volatile uint32_t *pdwGPIO_PDIR_BUTTON_3 = (volatile uint32_t*)0x400FF050; //PTB16
	  *pdwGPIO_PDIR_BUTTON_3 |=(1<<16);
	  volatile uint32_t *pdwGPIO_PDIR_BUTTON_4 = (volatile uint32_t*)0x400FF050; //PTB17
	  *pdwGPIO_PDIR_BUTTON_4 |=(1<<17);
	  volatile uint32_t *pdwGPIO_PDIR_BUTTON_5 = (volatile uint32_t*)0x400FF090; //PTC1
	  *pdwGPIO_PDIR_BUTTON_5 |=(1<<1);
	  volatile uint32_t *pdwGPIO_PDIR_BUTTON_6 = (volatile uint32_t*)0x400FF090; //PTC2
	  *pdwGPIO_PDIR_BUTTON_6 |=(1<<2);
  }

 /** @brief This function sets all the Port Output Registers (not including the LED PDOR)
  *  @return void
  */

  void Port_Output_Registers (void)
  {

  }




 /** @brief his function is to configure the pins (PCR, PDDR)
  *  @return void
  */
  static void Pin_Configurations (void)
  {
	/*LED CONFIG*/
  	volatile uint32_t *pdwGPIO_PDDR_RED_LED = (volatile uint32_t*)0x400FF054;
    volatile uint32_t *pdwMUX_RED_LED = (volatile uint32_t*)0x4004A048;
    *pdwMUX_RED_LED |= (1<<8);
    *pdwGPIO_PDDR_RED_LED |= (1<<18);


    /*BUTTON PDDR*/
    volatile uint32_t *pdwGPIO_PDDR_BUTTON_1 = (volatile uint32_t*)0x400FF094; //PTC3
    *pdwGPIO_PDDR_BUTTON_1 |=(1<<3);
    volatile uint32_t *pdwGPIO_PDDR_BUTTON_2 = (volatile uint32_t*)0x400FF054; //PTB3
    *pdwGPIO_PDDR_BUTTON_2 |=(1<<3);
    volatile uint32_t *pdwGPIO_PDDR_BUTTON_3 = (volatile uint32_t*)0x400FF054; //PTB16
    *pdwGPIO_PDDR_BUTTON_3 |=(1<<16);
    volatile uint32_t *pdwGPIO_PDDR_BUTTON_4 = (volatile uint32_t*)0x400FF054; //PTB17
    *pdwGPIO_PDDR_BUTTON_4 |=(1<<17);
    volatile uint32_t *pdwGPIO_PDDR_BUTTON_5 = (volatile uint32_t*)0x400FF094; //PTC1
    *pdwGPIO_PDDR_BUTTON_5 |=(1<<1);
    volatile uint32_t *pdwGPIO_PDDR_BUTTON_6 = (volatile uint32_t*)0x400FF094; //PTC2
    *pdwGPIO_PDDR_BUTTON_6 |=(1<<2);

    /*BUTTON PCR
    volatile uint32_t *pdwPE_BUTTON_1 = (volatile uint32_t*)0x4004B00C; //PTC3
    *pdwPE_BUTTON_1 |=(1<<1);
    volatile uint32_t *pdwPE_BUTTON_2 = (volatile uint32_t*)0x4004A00C; //PTB3
    *pdwPE_BUTTON_2 |=(1<<1);
    volatile uint32_t *pdwPE_BUTTON_3 = (volatile uint32_t*)0x4004A040; //PTB16
    *pdwPE_BUTTON_3 |=(1<<1);
    volatile uint32_t *pdwPE_BUTTON_4 = (volatile uint32_t*)0x4004A044; //PTB17
    *pdwPE_BUTTON_4 |=(1<<1);
    volatile uint32_t *pdwPE_BUTTON_5 = (volatile uint32_t*)0x4004B004; //PTC1
    *pdwPE_BUTTON_5 |=(1<<1);
    volatile uint32_t *pdwPE_BUTTON_6 = (volatile uint32_t*)0x4004B008; //PTC2
    *pdwPE_BUTTON_6 |=(1<<1);
    */

    /*DISPLAYS SEGMENTS PDDR*/
    volatile uint32_t *pdwGPIO_PDDR_DISPLAY_SEGMENT_1 = (volatile uint32_t*)0x400FF054; //PTB2
    *pdwGPIO_PDDR_DISPLAY_SEGMENT_1 |=(1<<2);
    volatile uint32_t *pdwGPIO_PDDR_DISPLAY_SEGMENT_2 = (volatile uint32_t*)0x400FF0D4; //PTD0
    *pdwGPIO_PDDR_DISPLAY_SEGMENT_2 |=(1<<0);
    volatile uint32_t *pdwGPIO_PDDR_DISPLAY_SEGMENT_3 = (volatile uint32_t*)0x400FF0D4; //PTD1
    *pdwGPIO_PDDR_DISPLAY_SEGMENT_3 |=(1<<1);
    volatile uint32_t *pdwGPIO_PDDR_DISPLAY_SEGMENT_4 = (volatile uint32_t*)0x400FF0D4; //PTD2
    *pdwGPIO_PDDR_DISPLAY_SEGMENT_4 |=(1<<2);
    volatile uint32_t *pdwGPIO_PDDR_DISPLAY_SEGMENT_5 = (volatile uint32_t*)0x400FF0D4; //PTD3
    *pdwGPIO_PDDR_DISPLAY_SEGMENT_5 |=(1<<3);
    volatile uint32_t *pdwGPIO_PDDR_DISPLAY_SEGMENT_6 = (volatile uint32_t*)0x400FF0D4; //PTD4
    *pdwGPIO_PDDR_DISPLAY_SEGMENT_6 |=(1<<4);
    volatile uint32_t *pdwGPIO_PDDR_DISPLAY_SEGMENT_7 = (volatile uint32_t*)0x400FF0D4; //PTD5
    *pdwGPIO_PDDR_DISPLAY_SEGMENT_7 |=(1<<5);

    /*DISPLAYS SEGMENTS PCR*/

    /*DISPLAY PDDR*/
    volatile uint32_t *pdwGPIO_PDDR_DISPLAY_1 = (volatile uint32_t*)0x400FF094; //PTC10
    *pdwGPIO_PDDR_DISPLAY_1 |= (1<<10);
    volatile uint32_t *pdwGPIO_PDDR_DISPLAY_2 = (volatile uint32_t*)0x400FF094; //PTC11
    *pdwGPIO_PDDR_DISPLAY_2 |= (1<<11);
    volatile uint32_t *pdwGPIO_PDDR_DISPLAY_3 = (volatile uint32_t*)0x400FF114; //PTE0
    *pdwGPIO_PDDR_DISPLAY_3 |= (1<<0);
    volatile uint32_t *pdwGPIO_PDDR_DISPLAY_4 = (volatile uint32_t*)0x400FF114; //PTE1
    *pdwGPIO_PDDR_DISPLAY_4 |= (1<<1);

    /*DISPLAY PCR*/
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
    volatile uint32_t* pdwPDOR_RED_LED = (volatile uint32_t*)0x400FF040;
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

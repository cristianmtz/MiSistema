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
*	Author:			B.Chavoya							*
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

/** @brief
 *  @param
 *  @param
 *  @return
 */

/*
 * static void System_Clock_Gating (void)
 * {
 * 		volatile uint32_t* pdwSCGC5 = (volatile uint32_t*)0x40048038;
 * 		*pdwSCGC5 |= (1<<10);
 *
 * }
 */

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
  	/* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
  	/* Init FSL debug console. */
    BOARD_InitDebugConsole();

    volatile uint32_t* pdwSCGC5 = (volatile uint32_t*)0x40048038; //función System Clock Gate
    volatile uint32_t* pdwGPIO_PDDR = (volatile uint32_t*)0x400FF054;
    volatile uint32_t *pdwMUX = (volatile uint32_t*)0x4004A048;
    volatile uint32_t* pdwPDOR = (volatile uint32_t*)0x400FF040;
    uint32_t dwdelay = 0;


      *pdwSCGC5 |= (1<<10);
      *pdwMUX |= (1<<8);
      *pdwGPIO_PDDR |= (1<<18);

        while(1)
        {
        	dwdelay = 0x000F4240;

        	while(dwdelay--)
        	{

        	}

        	*pdwPDOR ^= (1<<18);

        }
        return 0 ;
}

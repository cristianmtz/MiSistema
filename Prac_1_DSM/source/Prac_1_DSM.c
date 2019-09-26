/*
 * Copyright 2016-2019 NXP
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
 * @file    Prac_1_DSM.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL27Z644.h"
#include "fsl_debug_console.h"
#include "GpioDriver.h"
#include "DisplayDriver.h"
#include "DebouncerDriver.h"




int main(void) {

	Port_Init_Configuration();


	while(1){
		uint32_t Delay = 20000;
			uint8_t value = 0;
			uint8_t decrease = 0;
			uint8_t displayRight = 1;
			uint8_t displayLeft = 1;
			uint8_t currentDisplay = 1;
			//bandera para saber si esta activa la configuracion
			uint8_t activeConfig = 0;
			uint8_t configValue = 0;
			static uint8_t Counter[4];
			uint8_t runValue = 0;
			uint8_t isRunning = 0;

			while(1){
				Delay = 20000;
				while(Delay--);

				configValue = bfnDebouncer(GPIOA,12);
				if(configValue == 1){
					activeConfig = 1;
				}

				if(activeConfig == 1){
					//Debounce 1
					value = bfnDebouncer(GPIOD,1);
					if(value == 1){
						Bcd2SevenSegments(Counter[currentDisplay - 1]);
						clearsegments();
						if(Counter[currentDisplay - 1] >= 9){
							Counter[currentDisplay - 1] = 0;
						}else{
							++Counter[currentDisplay - 1];
						}
					}else{
						Bcd2SevenSegments(Counter[currentDisplay - 1]);
						clearsegments();
					}

					// Drecrementar contador*/
					decrease = bfnDebouncer(GPIOD,2);
					if(decrease == 1){
						if(Counter[currentDisplay - 1] > 0){
							Counter[currentDisplay - 1]--;
						}
						Bcd2SevenSegments(Counter[currentDisplay - 1]);
						clearsegments();
					}else{
						Bcd2SevenSegments(Counter[currentDisplay - 1]);
						clearsegments();
					}

					// Mover a la izquierda
					displayRight = bfnDebouncer(GPIOD,4);
					if(displayRight == 1){
						if(currentDisplay >= 1 && currentDisplay < 5){
							currentDisplay++;
						}

					}

					// Mover a la derechA
					displayLeft = bfnDebouncer(GPIOD,5);
					if(displayLeft == 1){
						if(currentDisplay > 1){
							currentDisplay--;
						}

					}
					//Run
					runValue = bfnDebouncer(GPIOE,25);
					if(runValue == 1){
						while(Counter[0] > 0 && Counter[1] > 0 && Counter[2] > 0 && Counter[3] > 0){
							//Enceder todos los displays

						}
						isRunning = true;
					}
				}
				if(activeConfig == 0){
					Bcd2SevenSegments(0);
					clearsegments();
					OneHot(1);
				}else{
					if(isRunning == 0){
						OneHot(currentDisplay);
					}
				}
			}

	}

    return 0 ;
}

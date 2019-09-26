/********************************************************
*	Author: 		Cristian Mtz     					*
*	File Name:      GpioDriver.c						*
*   Description:    									*
*   													*
*	This file is for my dear students, here is 			*
*	described how should they desing their modules.		*
********************************************************/

/****** Inlcude Section *******/
#include <GpioDriver.h>
#include "stdio.h"
#include "MKL27Z644.h"

/****** Global Variables *******/

/****** Local Variables *******/

/****** Local Functions *******/

/** @brief This function is for add two parameters with pointers
 *  @param u8FirstParam First number to add
 *  @param u8SecondParam Second number to add
 *  @param u16Result Where the result will be stored
 *  @return void
 */

/****** Global Functions *******/

/** @brief This function is for add two parameters
 *  @param u8FirstParam First data to add
 *  @param u8SecondParam Second data to add
 *  @return uin16
 */

/** @brief main function
 *  @param none
 *  @return void
 */


 void Port_Init_Configuration (void)
  {



	 					SIM->SCGC5 |=SIM_SCGC5_PORTB_MASK;
	 		 	 	 	SIM->SCGC5 |=SIM_SCGC5_PORTC_MASK;
	 		 	 	 	SIM->SCGC5 |=SIM_SCGC5_PORTE_MASK;
	 		 	 	 	SIM->SCGC5 |=SIM_SCGC5_PORTD_MASK;
	 					SIM->SCGC5 |=SIM_SCGC5_PORTA_MASK;



	 					////////////////Inicializacion de Segmentos////////////////////

	 					PORTB->PCR[17] = PORT_PCR_MUX(1);
	 					GPIOB->PDDR |=   GPIO_PDDR_PDD(1<<17);

	 					PORTE->PCR[20] = PORT_PCR_MUX(1);
	 					GPIOE->PDDR |=   GPIO_PDDR_PDD(1<<20);

	 					PORTE->PCR[21] = PORT_PCR_MUX(1);
	 					GPIOE->PDDR |=   GPIO_PDDR_PDD(1<<21);


	 					PORTC->PCR[7] = PORT_PCR_MUX(1);
						GPIOC->PDDR |=   GPIO_PDDR_PDD(1<<7);

						PORTC->PCR[8] = PORT_PCR_MUX(1);
						GPIOC->PDDR |=   GPIO_PDDR_PDD(1<<8);

						PORTC->PCR[9] = PORT_PCR_MUX(1);
						GPIOC->PDDR |=   GPIO_PDDR_PDD(1<<9);

						PORTC->PCR[10] = PORT_PCR_MUX(1);
						GPIOC->PDDR |=   GPIO_PDDR_PDD(1<<10);


	 			////////////////////Inicializacion de Displays////////////////////////////////////////////////

						PORTB->PCR[1] = PORT_PCR_MUX(1);
						GPIOB->PDDR |=   GPIO_PDDR_PDD(1<<1);

						PORTB->PCR[2] = PORT_PCR_MUX(1);
						GPIOB->PDDR |=   GPIO_PDDR_PDD(1<<2);

						PORTB->PCR[3] = PORT_PCR_MUX(1);
						GPIOB->PDDR |=   GPIO_PDDR_PDD(1<<3);

						PORTB->PCR[16] = PORT_PCR_MUX(1);
						GPIOB->PDDR |=   GPIO_PDDR_PDD(1<<16);


	//////////////////////Inicializacion de Botones/////////////////////////////////////////////////////////////


						PORTD->PCR[1] = PORT_PCR_MUX(1);
						GPIOD->PDDR |=   GPIO_PDDR_PDD(0<<1);


						PORTD->PCR[2] = PORT_PCR_MUX(1);
						GPIOD->PDDR |=   GPIO_PDDR_PDD(0<<2);

						PORTD->PCR[4] = PORT_PCR_MUX(1);
						GPIOD->PDDR |=   GPIO_PDDR_PDD(0<<4);

						PORTD->PCR[5] = PORT_PCR_MUX(1);
						GPIOD->PDDR |=   GPIO_PDDR_PDD(0<<5);

						PORTA->PCR[12] = PORT_PCR_MUX(1);
						GPIOA->PDDR |=   GPIO_PDDR_PDD(0<<12);

						PORTE->PCR[25] |= PORT_PCR_MUX(1);
						GPIOE->PDDR |=   GPIO_PDDR_PDD(0<<25);




		///////////////////////////////////////////////////////////////////////////////















	///////////////////////////////////////////////////////////////////////////////////////////////////
					/*
							PORTD->PCR[7] = PORT_PCR_MUX(1);
	 		 	 	 		GPIOD->PDDR |=   GPIO_PDDR_PDD(0<<7);


	 		 	 	 		PORTD->PCR[6] = PORT_PCR_MUX(1);
	 		 	 	 		GPIOD->PDDR |=   GPIO_PDDR_PDD(0<<6);

	 		 	 	 		PORTD->PCR[1] = PORT_PCR_MUX(1);
	 		 	 	 		GPIOD->PDDR |=   GPIO_PDDR_PDD(0<<1);

	 		 	 	 		PORTD->PCR[2] = PORT_PCR_MUX(1);
	 		 	 	 		GPIOD->PDDR |=   GPIO_PDDR_PDD(0<<2);

	 		 	 	 		PORTD->PCR[3] = PORT_PCR_MUX(1);
	 		 	 	 		GPIOD->PDDR |=   GPIO_PDDR_PDD(0<<3);



	 		 	 	 		/*port
	 					PORTA->PCR[1] |= PORT_PCR_MUX(1);
	 					GPIOA->PDDR |=   GPIO_PDDR_PDD(0<<1);

	 					PORTA->PCR[4] |= PORT_PCR_MUX(1);
	 					GPIOA->PDDR |=   GPIO_PDDR_PDD(0<<4);

	 					PORTA->PCR[5] |= PORT_PCR_MUX(1);
	 					GPIOA->PDDR |=   GPIO_PDDR_PDD(0<<5);

	 					PORTA->PCR[2] |= PORT_PCR_MUX(1);
	 					GPIOA->PDDR |= GPIO_PDDR_PDD(0<<2);


	 		 	 	 	/*port B

	 					PORTB->PCR[19] = PORT_PCR_MUX(1);
	 				    GPIOB->PDDR |=   GPIO_PDDR_PDD(1<<19);

	 				    PORTC->PCR[11] = PORT_PCR_MUX(1);
	 				    GPIOC->PDDR |=   GPIO_PDDR_PDD(0<<11);


	 				    */


	 }






 void Port_Init_led(void){

	 SIM->SCGC5 |=SIM_SCGC5_PORTB_MASK;
	 PORTB->PCR[18] = PORT_PCR_MUX(1);
	GPIOB->PDDR = GPIO_PDDR_PDD(1<<18);

 }

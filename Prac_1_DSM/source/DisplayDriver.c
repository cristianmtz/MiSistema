/********************************************************
*	Author: Cristian Mtz								*
*	File Name:  DisplayDriver.c   						*
*   Description:    									*
*   													*
*											 			*
*														*
********************************************************/

/****** Inlcude Section *******/
#include "stdio.h"
#include "MKL27Z644.h"
#include <DisplayDriver.h>

/****** Global Variables *******/


/****** Local Variables *******/


/****** Local Functions *******/

/** @brief 
 *  @param 
 *  @param 
 *  @return 
 */


/****** Global Functions *******/

/** @brief 
 *  @param 
 *  @param 
 *  @return 
 */

void Bcd2SevenSegments(uint8 NumToTransform)
	 {
	 	switch(NumToTransform)
	 	{
 		case (cero):
 		{
 			 /*gbA_segment = 0;
 			 gbB_segment = 1;
 			 gbC_segment = 1;
 			 gbD_segment = 0;
 			 gbE_segment = 0;
 			 gbF_segment = 0;
 			 gbG_segment = 0;*/

 			/*B Y C*/
 			GPIOB->PDOR |= GPIO_PDOR_PDO(1<<17);
 			GPIOE->PDOR |= GPIO_PDOR_PDO(1<<20);
 			GPIOE->PDOR |= GPIO_PDOR_PDO(1<<21);
 			GPIOC->PDOR |= GPIO_PDOR_PDO(1<<7);
 			GPIOC->PDOR |= GPIO_PDOR_PDO(1<<8);
 			GPIOC->PDOR |= GPIO_PDOR_PDO(1<<9);

 		}break;
	 		case (one):
	 		{
	 			 /*gbA_segment = 0;
	 			 gbB_segment = 1;
	 			 gbC_segment = 1;
	 			 gbD_segment = 0;
	 			 gbE_segment = 0;
	 			 gbF_segment = 0;
	 			 gbG_segment = 0;*/

	 			/*B Y C*/
	 			GPIOE->PDOR  |= GPIO_PDOR_PDO(1<<20);
	 			GPIOE->PDOR |= GPIO_PDOR_PDO(1<<21);

	 		}break;
	 		case  (two):
	 		{
	 			 /*gbA_segment = 1;
	 			 gbB_segment = 1;
	 			 gbC_segment = 0;
	 			 gbD_segment = 1;
	 			 gbE_segment = 1;
	 			 gbF_segment = 0;
	 			 gbG_segment = 1;*/
	 			/*PRIMERO APAGAMOS LOS QUE ESTEN PRENDIDOS*/

	 			/*ACTIVAMOS PARA ESTOS */
	 			GPIOB->PDOR |= GPIO_PDOR_PDO(1<<17);
	 			GPIOE->PDOR |= GPIO_PDOR_PDO(1<<20);
	 			GPIOC->PDOR |= GPIO_PDOR_PDO(1<<7);
	 			GPIOC->PDOR |= GPIO_PDOR_PDO(1<<8);
	 			GPIOC->PDOR |= GPIO_PDOR_PDO(1<<10);

	 		}break;
	 		case (three):
	 	{
	 			/* gbA_segment = 1;
	 			 gbB_segment = 1;
	 			 gbC_segment = 1;
	 			 gbD_segment = 1;
	 			 gbE_segment = 0;
	 			 gbF_segment = 0;
	 			 gbG_segment = 1;*/
	 			/*APAGAR LOS ANTERIORES*/

	 			/*SET LOS DE ESTE ESTADO*/
	 			GPIOB->PDOR |= GPIO_PDOR_PDO(1<<17);
	 			GPIOE->PDOR |= GPIO_PDOR_PDO(1<<20);
	 			GPIOE->PDOR |= GPIO_PDOR_PDO(1<<21);
	 			GPIOC->PDOR |= GPIO_PDOR_PDO(1<<7);
	 			GPIOC->PDOR |= GPIO_PDOR_PDO(1<<10);

	 	}break;
	 		case (four):
	 	{
	 			/* gbA_segment = 0;
	 			 gbB_segment = 1;
	 			 gbC_segment = 1;
	 			 gbD_segment = 0;
	 			 gbE_segment = 0;
	 			 gbF_segment = 1;
	 			 gbG_segment = 1;*/
	 			/*APAGAR LOS ANTERIORES*/

	 			/*SET LOS DE ESTE ESTADO*/
	 			GPIOE->PDOR |= GPIO_PDOR_PDO(1<<20);
	 			GPIOE->PDOR |= GPIO_PDOR_PDO(1<<21);
	 			GPIOC->PDOR |= GPIO_PDOR_PDO(1<<9);
	 			GPIOC->PDOR |= GPIO_PDOR_PDO(1<<10);
	 	}break;
	 		case (five):
	 	{
	 		/*	 gbA_segment = 1;
	 			 gbB_segment = 0;
	 			 gbC_segment = 1;
	 			 gbD_segment = 1;
	 			 gbE_segment = 0;
	 			 gbF_segment = 1;
	 			 gbG_segment = 1;*/

	 			/*SET LOS DE ESTE ESTADO*/
	 			GPIOB->PDOR |= GPIO_PDOR_PDO(1<<17);
	 			GPIOE->PDOR |= GPIO_PDOR_PDO(1<<21);
	 			GPIOC->PDOR |= GPIO_PDOR_PDO(1<<7);
	 			GPIOC->PDOR |= GPIO_PDOR_PDO(1<<9);
	 			GPIOC->PDOR |= GPIO_PDOR_PDO(1<<10);

	 	}break;
	 		case (six):
	 	{
	 		/*	 gbA_segment = 1;
	 			 gbB_segment = 0;
	 			 gbC_segment = 1;
	 			 gbD_segment = 1;
	 			 gbE_segment = 1;
	 			 gbF_segment = 1;
	 			 gbG_segment = 1;*/
	 			/*APAGAR LOS ANTERIORES*/

	 			/*SET LOS DE ESTE ESTADO*/
	 			GPIOB->PDOR |= GPIO_PDOR_PDO(1<<17);
	 			GPIOE->PDOR |= GPIO_PDOR_PDO(1<<21);
	 			GPIOC->PDOR |= GPIO_PDOR_PDO(1<<7);
	 			GPIOC->PDOR |= GPIO_PDOR_PDO(1<<8);
	 			GPIOC->PDOR |= GPIO_PDOR_PDO(1<<9);
	 			GPIOC->PDOR |= GPIO_PDOR_PDO(1<<10);
	 	}break;
	 		case (seven):
	 	{
	 		/*	 gbA_segment = 1;
	 			 gbB_segment = 1;
	 			 gbC_segment = 1;
	 			 gbD_segment = 0;
	 			 gbE_segment = 0;
	 			 gbF_segment = 0;
	 			 gbG_segment = 0;*/
	 			/*APAGAR LOS ANTERIORES*/

	 			/*SET LOS DE ESTE ESTADO*/
	 			GPIOB->PDOR |= GPIO_PDOR_PDO(1<<17);
	 			GPIOE->PDOR |= GPIO_PDOR_PDO(1<<20);
	 			GPIOE->PDOR |= GPIO_PDOR_PDO(1<<21);

	 	}break;
	 		case (eight):
	 	{
	 	/*		 gbA_segment = 1;
	 			 gbB_segment = 1;
	 			 gbC_segment = 1;
	 			 gbD_segment = 1;
	 			 gbE_segment = 1;
	 			 gbF_segment = 1;
	 			 gbG_segment = 1;*/

	 			/*SET LOS DE ESTE ESTADO*/
	 			GPIOB->PDOR |= GPIO_PDOR_PDO(1<<17);
	 			GPIOE->PDOR |= GPIO_PDOR_PDO(1<<20);
	 			GPIOE->PDOR |= GPIO_PDOR_PDO(1<<21);
	 			GPIOC->PDOR |= GPIO_PDOR_PDO(1<<7);
	 			GPIOC->PDOR |= GPIO_PDOR_PDO(1<<8);
	 			GPIOC->PDOR |= GPIO_PDOR_PDO(1<<9);
	 			GPIOC->PDOR |= GPIO_PDOR_PDO(1<<10);


	 	}break;
	 		case  (nine):
	 	{
	 	/*		 gbA_segment = 1;
	 			 gbB_segment = 1;
	 			 gbC_segment = 1;
	 			 gbD_segment = 0;
	 			 gbE_segment = 0;
	 			 gbF_segment = 1;
	 			 gbG_segment = 1;*/

	 			/*SET LOS DE ESTE ESTADO*/
	 			GPIOB->PDOR |= GPIO_PDOR_PDO(1<<17);
	 			GPIOE->PDOR |= GPIO_PDOR_PDO(1<<20);
	 			GPIOE->PDOR |= GPIO_PDOR_PDO(1<<21);
	 			GPIOC->PDOR |= GPIO_PDOR_PDO(1<<9);
	 			GPIOC->PDOR |= GPIO_PDOR_PDO(1<<10);




	 	}break;

	 }
}


void OneHot (uint32 u32DisplayControl){

				if(u32DisplayControl == 1)
				{
					cleardisplay();
				clearsegments();
				GPIOB->PDOR &= ~(GPIO_PDOR_PDO(1<<1));

				}else if(u32DisplayControl ==2)
				{
					cleardisplay();
				clearsegments();
				GPIOB->PDOR &= ~(GPIO_PDOR_PDO(1<<2));

				}else if(u32DisplayControl ==3)
				{
					cleardisplay();
				clearsegments();
				GPIOB->PDOR &= ~(GPIO_PDOR_PDO(1<<3));

				}else if(u32DisplayControl ==4)
				{
					cleardisplay();
				clearsegments();
				GPIOB->PDOR &= ~(GPIO_PDOR_PDO(1<<16));
				}
}

void cleardisplay(void){
			GPIOB->PDOR |= GPIO_PDOR_PDO(1<<1);
			GPIOB->PDOR |= GPIO_PDOR_PDO(1<<16);
			GPIOB->PDOR |= GPIO_PDOR_PDO(1<<2);
			GPIOB->PDOR |= GPIO_PDOR_PDO(1<<3);
}

void clearsegments(void){
		GPIOB->PDOR &= ~(GPIO_PDOR_PDO(1<<17));
		GPIOE->PDOR &= ~(GPIO_PDOR_PDO(1<<20));
		GPIOE->PDOR &= ~(GPIO_PDOR_PDO(1<<21));
		GPIOC->PDOR &= ~(GPIO_PDOR_PDO(1<<7));
		GPIOC->PDOR &= ~(GPIO_PDOR_PDO(1<<8));
		GPIOC->PDOR &= ~(GPIO_PDOR_PDO(1<<9));
		GPIOC->PDOR &= ~(GPIO_PDOR_PDO(1<<10));
}

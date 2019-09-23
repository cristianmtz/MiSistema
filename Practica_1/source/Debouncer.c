/********************************************************
*	Author: Cristian Martinez 							*
*	File Name: Debouncer     							*
*   Description:    									*
*   													*
*											 			*
*														*
********************************************************/

/****** Inlcude Section *******/

#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL27Z644.h"
#include "fsl_debug_console.h"
#include "fsl_gpio.h"
/****** Global Variables *******/

/****** Local Variables *******/

/****** Local Functions *******/

/****** Global Functions *******/

/*******Typedef Section ********/


enum state_of_movement{

	cero =0,
	one,
	two,
	three,
	four,
	five,
	six,
	seven,
	eight,
	nine
};

/*
enum gpio_ports{

	GPIOPORTA = 0,
	GPIOPORTB,
	GPIOPORTC,
	GPIOPORTD,
	GPIOPORTE

};
*/
void PortInit(void);
uint8_t bfnDebouncer(uint32_t pin);
void Bcd2SevenSegments(uint8_t NumToTransform);
void OneHot (uint32_t u32DisplayControl);
void cleardisplay(void);
void clearsegments(void);


int main(void){
		PortInit();

	uint32_t Delay = 20000;
	uint8_t value = 0;
	static uint8_t Counter=0;

	while(1){
		Delay = 20000;
		while(Delay--);
		//Debounce 1
		value = bfnDebouncer(1);
		if(value == 1){
			Bcd2SevenSegments(Counter);
			clearsegments();
			if(Counter >= 9){
				Counter = 0;
			}else{
				Counter++;
			}
		}else{
			Bcd2SevenSegments(Counter);
			clearsegments();
		}
		OneHot(1);
	}

	return 0;
}


uint8_t bfnDebouncer(uint32_t pin){
	uint8_t ReadValue = 0;
	static uint8_t StableValue = 0;
	static uint8_t Index = 0;
	static uint8_t Samples[3];

	ReadValue = GPIO_PinRead(GPIOA, pin);
	if(ReadValue != StableValue){
		Samples[Index] = ReadValue;
		Index++;
	}
	else{
		Index = 0;
	}

	if((Samples[1] & Samples[2]) == 1 && StableValue == 0 && Index == 2){
		StableValue = 1;
		Samples[0] = 0;
		Samples[1] = 0;
		Samples[2] = 0;
		Index = 0;
	}else{
		StableValue = 0;
	}

	return StableValue;
}

void Bcd2SevenSegments(uint8_t NumToTransform)
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

void OneHot (uint32_t u32DisplayControl){

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

void PortInit(void)
	 {



					SIM->SCGC5 |=SIM_SCGC5_PORTB_MASK;
		 	 	 	SIM->SCGC5 |=SIM_SCGC5_PORTC_MASK;
		 	 	 	SIM->SCGC5 |=SIM_SCGC5_PORTE_MASK;
		 	 	 	SIM->SCGC5 |=SIM_SCGC5_PORTD_MASK;
					SIM->SCGC5 |=SIM_SCGC5_PORTA_MASK;


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



		 	 	 		/*port A*/
					PORTA->PCR[1] |= PORT_PCR_MUX(1);
					GPIOA->PDDR |=   GPIO_PDDR_PDD(0<<1);

					PORTA->PCR[4] |= PORT_PCR_MUX(1);
					GPIOA->PDDR |=   GPIO_PDDR_PDD(0<<4);

					PORTA->PCR[5] |= PORT_PCR_MUX(1);
					GPIOA->PDDR |=   GPIO_PDDR_PDD(0<<5);

					PORTA->PCR[2] |= PORT_PCR_MUX(1);
					GPIOA->PDDR |= GPIO_PDDR_PDD(0<<2);


		 	 	 	/*port B*/
					PORTB->PCR[1] = PORT_PCR_MUX(1);
					GPIOB->PDDR |=   GPIO_PDDR_PDD(1<<1);

					PORTB->PCR[2] = PORT_PCR_MUX(1);
					GPIOB->PDDR |=   GPIO_PDDR_PDD(1<<2);

					PORTB->PCR[3] = PORT_PCR_MUX(1);
					GPIOB->PDDR |=   GPIO_PDDR_PDD(1<<3);

					PORTB->PCR[16] = PORT_PCR_MUX(1);
					GPIOB->PDDR |=   GPIO_PDDR_PDD(1<<16);

					PORTB->PCR[19] = PORT_PCR_MUX(1);
				    GPIOB->PDDR |=   GPIO_PDDR_PDD(1<<19);


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

				    PORTC->PCR[11] = PORT_PCR_MUX(1);
				    GPIOC->PDDR |=   GPIO_PDDR_PDD(0<<11);
				    }




#ifndef GPIODRIVER_H_
#define GPIODRIVER_H_



#endif /* GPIODRIVER_H_ */

/********************************************************
*	Author:			B.Chavoya, C.Martinez				*
*	File Name:		GPIODriver.h      					*
*   Description:										*
*   This file initializes all the KL27 pins     		*
*   that are necessary to activate buttons, displays	*
*	and the KL27 LED.									*
********************************************************/


/******  Include Section *******/


/******  Define Section *******/
#define LED_TOGGLE_TIME  (0x003D0900)


#define INIT_STRUCT 			\
{								\
	{enPORTBPIN2, (uint32_t*)GPIOB_BASE, 1}, 	\
	{enPORTBPIN3, GPIOB->PDOR, 1}, 	\
	{enPORTBPIN16, GPIOB->PDOR, 1}, \
	{enPORTBPIN17, GPIOB->PDOR, 1}, \
	{enPORTCPIN1, GPIOC->PDOR, 1}, 	\
	{enPORTCPIN2, GPIOC->PDOR, 1}, 	\
	{enPORTCPIN10, GPIOC->PDOR, 1},	\
	{enPORTCPIN11, GPIOC->PDOR, 1},	\
	{enPORTDPIN0, GPIOD->PDOR, 1},	\
	{enPORTDPIN1, GPIOD->PDOR, 1},	\
	{enPORTDPIN2, GPIOD->PDOR, 1},	\
	{enPORTDPIN3, GPIOD->PDOR, 1},	\
	{enPORTDPIN4, GPIOD->PDOR, 1},	\
	{enPORTDPIN5, GPIOD->PDOR, 1},	\
	{enPORTEPIN0, GPIOE->PDOR, 1},	\
	{enPORTEPIN1, GPIOE->PDOR, 1}	\
}


/******  Typedef Section *******/


/******  Prototype Section *******/


/******  Extern Section *******/

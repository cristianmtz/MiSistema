/********************************************************
*	Author: 		P. Molina							*
*	File Name:      HeaderTemplate.h					*
*   Description:    									*
*   													*
*	This file is for my dear students, here is 			*
*	described how should they desing their modules.		*
********************************************************/


/******  Inlcude Section *******/
#include "stdint.h"

/******  Define Section *******/


/******  Typedef Section *******/


/******  Prototype Section *******/
uint32_t getIndexButton(uint32_t pin);

uint32_t bfnDebouncer(GPIO_Type *bases, uint32_t pin);

uint8_t getIndex(uint32_t pin);

/******  Extern Section *******/

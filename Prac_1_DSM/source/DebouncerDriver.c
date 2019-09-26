/********************************************************
*	Author: 											*
*	File Name:      									*
*   Description:    									*
*   													*
*											 			*
*														*
********************************************************/

/****** Inlcude Section *******/
#include "stdio.h"
#include "MKL27Z644.h"
#include <DebouncerDriver.h>
#include "fsl_gpio.h"
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


uint32_t bfnDebouncer(GPIO_Type *bases, uint32_t pin){
	uint32_t ReadValue[6];
	static uint32_t StableValue[6];
	static uint32_t Index[6];
	static uint32_t Samples[6][3];
	static uint32_t  indixito = 0;

	indixito = getIndex(pin);
	ReadValue[indixito] = getIndexButton(pin);

	if(ReadValue[indixito] != StableValue[indixito]){
		Samples[indixito][Index[indixito]] = ReadValue[indixito];
		++Index[indixito];
	}
	else{
		Index[indixito] = 0;
	}

	if((Samples[indixito][1] & Samples[indixito][2]) == 1 && StableValue[indixito] == 0 && Index[indixito] == 2){
		StableValue[indixito] = 1;
		Samples[indixito][0] = 0;
		Samples[indixito][1] = 0;
		Samples[indixito][2] = 0;
		Index[indixito] = 0;
	}else{
		StableValue[indixito] = 0;
	}

	return StableValue[indixito];
}

uint32_t getIndexButton(uint32_t pin){
	uint32_t result = 0;
	switch(pin){
		case 1:
		case 2:
		case 4:
		case 5:
			result = GPIO_PinRead(GPIOD, pin);
			break;
		case 12:
			result = GPIO_PinRead(GPIOA, pin);
			break;
		case 25:
			result = GPIO_PinRead(GPIOE, pin);
			break;
	}

	return result;
}

uint8_t getIndex(uint32_t pin){
	uint8_t result = 0;
	switch(pin){
		case 1:
			result = 0;
			break;
		case 2:
			result = 1;
			break;
		case 4:
			result = 2;
			break;
		case 5:
			result = 3;
			break;
		case 12:
			result = 4;
			break;
		case 25:
			result = 5;
			break;
	}

	return result;
}

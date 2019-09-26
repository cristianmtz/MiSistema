/********************************************************
*	Author: 		Cristian Mtz						*
*	File Name:      DisplayDriver.h	     				*
*   Description:    									*
*   													*
*	This file is for my dear students, here is 			*
*	described how should they desing their modules.		*
********************************************************/


/******  Inlcude Section *******/
#include "stdint.h"


/******  Define Section *******/


/******  Typedef Section *******/
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned long uint32;

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

/******  Prototype Section *******/
void Bcd2SevenSegments(uint8 NumToTransform);
void OneHot (uint32 u32DisplayControl);
void cleardisplay(void);
void clearsegments(void);

/******  Extern Section *******/

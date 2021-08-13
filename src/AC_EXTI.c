/*
 * AC_EXTI.c
 *
 *  Created on: Aug 12, 2021
 *      Author: ahmet
 */
#include "AC_EXTI.h"
void AC_EXTIInit(void)
{
	EXTI_InitTypeDef EXTI_InitStructure;
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource5);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource6);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource7);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource8);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource9);

	EXTI_InitStructure.EXTI_Line = EXTI_Line5| EXTI_Line6 | EXTI_Line7|
									EXTI_Line8 | EXTI_Line9;
	EXTI_InitStructure.EXTI_LineCmd	= ENABLE;
	EXTI_InitStructure.EXTI_Mode	= EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger	= EXTI_Trigger_Rising;

	EXTI_Init(&EXTI_InitStructure);
}


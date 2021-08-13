/*
 * AC_NVIC.c
 *
 *  Created on: Aug 12, 2021
 *      Author: ahmet
 */
#include "AC_NVIC.h"

//instead of NVIC_PriorityGroupConfig() ,I used this
#define AIRCR_VECTKEY_MASK    ((uint32_t)0x05FA0000)

void AC_NVICInit(void)
{

	NVIC_InitTypeDef NVIC_InitStructure;
	// instead of NVIC_PriorityGroupConfig()
	SCB->AIRCR = AIRCR_VECTKEY_MASK | NVIC_PriorityGroup_1;

	NVIC_InitStructure.NVIC_IRQChannel					=EXTI9_5_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd 				= ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority= 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority		=0;
	NVIC_Init(&NVIC_InitStructure);
}

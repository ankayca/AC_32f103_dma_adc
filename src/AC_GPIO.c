/*
 * AC_GPIO.c
 *
 *  Created on: Aug 12, 2021
 *      Author: ahmet
 */
#include "AC_GPIO.h"
void AC_GPIOInit(void)
{
	GPIO_InitTypeDef gpio_initStructure;

	// LED and 2 transistor
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	gpio_initStructure.GPIO_Mode = GPIO_Mode_Out_OD;
	gpio_initStructure.GPIO_Pin = GPIO_Pin_13 | GPIO_Pin_14|GPIO_Pin_15;
	gpio_initStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOC,&gpio_initStructure);

	// BUTTONS
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	gpio_initStructure.GPIO_Mode 	= GPIO_Mode_IPU;
	gpio_initStructure.GPIO_Pin 	= GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 |
										GPIO_Pin_8 | GPIO_Pin_9;
	gpio_initStructure.GPIO_Speed	= GPIO_Speed_2MHz;
	GPIO_Init(GPIOB,&gpio_initStructure);

	// ADC
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1,ENABLE);
	gpio_initStructure.GPIO_Mode = GPIO_Mode_AIN;
	gpio_initStructure.GPIO_Pin	= GPIO_Pin_3;
	GPIO_Init(GPIOA,&gpio_initStructure);
}


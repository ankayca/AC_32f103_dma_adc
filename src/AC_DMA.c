/*
 * AC_DMA.c
 *
 *  Created on: Aug 12, 2021
 *      Author: Ankayca
 */

#ifndef AC_DMA_C_
#define AC_DMA_C_
#include "AC_DMA.h"
void AC_DMAInit(uint16_t adcValue[2])
{
	// DMA CONFIG

	DMA_InitTypeDef DMAInitStructure;
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1,ENABLE);

	DMA_Cmd(DMA1_Channel1,DISABLE);
	DMA_DeInit(DMA1_Channel1);
	// DMA buffer size =2
	DMAInitStructure.DMA_BufferSize=2;

	DMAInitStructure.DMA_DIR=DMA_DIR_PeripheralSRC;
	DMAInitStructure.DMA_M2M=DISABLE;
	DMAInitStructure.DMA_MemoryBaseAddr=(uint32_t)adcValue;
	DMAInitStructure.DMA_MemoryDataSize=DMA_MemoryDataSize_HalfWord;
	DMAInitStructure.DMA_MemoryInc=DMA_MemoryInc_Enable;
	DMAInitStructure.DMA_Mode=DMA_Mode_Circular;
	DMAInitStructure.DMA_PeripheralBaseAddr=(uint32_t) & ADC1->DR;
	DMAInitStructure.DMA_PeripheralDataSize=DMA_PeripheralDataSize_HalfWord;
	DMAInitStructure.DMA_PeripheralInc=DMA_PeripheralInc_Disable;
	DMAInitStructure.DMA_Priority=DMA_Priority_High;

	DMA_Init(DMA1_Channel1,&DMAInitStructure);
	DMA_Cmd(DMA1_Channel1,ENABLE);


}

#endif /* AC_DMA_C_ */

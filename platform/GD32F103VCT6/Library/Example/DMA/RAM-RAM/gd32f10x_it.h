/**
  ******************************************************************************
  * @file    DMA/RAM_RAM/gd32f10x_it.h
  * @author  MCU SD
  * @version V1.0
  * @date    26-Dec-2014
  * @brief   The header file of the ISR.
  ******************************************************************************
  */ 

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GD32F10X_IT_H
#define __GD32F10X_IT_H

/* Includes ------------------------------------------------------------------*/
#include "gd32f10x.h"

/* Exported functions ------------------------------------------------------- */
void NMI_Handler(void);
void HardFault_Handler(void);
void MemManage_Handler(void);
void BusFault_Handler(void);
void UsageFault_Handler(void);
void SVC_Handler(void);
void DebugMon_Handler(void);
void PendSV_Handler(void);
void SysTick_Handler(void);
void DMA1_Channel1_IRQHandler(void);
void DMA1_Channel2_IRQHandler(void);
void DMA1_Channel3_IRQHandler(void);
void DMA1_Channel4_IRQHandler(void);
void DMA1_Channel5_IRQHandler(void);
void DMA1_Channel6_IRQHandler(void);
void DMA1_Channel7_IRQHandler(void);

#endif /* __GD32F10X_IT_H */

/******************* (C) COPYRIGHT 2014 GIGADEVICE *****END OF FILE****/

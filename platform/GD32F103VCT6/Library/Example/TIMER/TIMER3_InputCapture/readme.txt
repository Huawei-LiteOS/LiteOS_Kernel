/**
  ******************************************************************************
  * @file    TIMER/TIMER3_InputCapture/readme.txt
  * @author  MCU SD 
  * @version V1.0
  * @date    26-Dec-2014 
  * @brief   Description of the TIMER demo.
  ******************************************************************************
  */

  @brief
    This demo is based on the GD32107C-EVAL board, it shows TIMER peripheral to 
  measure the frequency of an external signal.
    The TIMxCLK frequency is set to SystemCoreClock,the Prescaler is 54000 so 
  the TIMER3 counter clock is 2KHz.
    The external signal is connected to TIMER3 CH1 pin (PA6).
    The Rising edge is used as active edge.
    The TIMER3 CHCC1 is used to compute the frequency value.

  @note     
    The available frequence of the input signal is ranging from 0.03Hz to 2KHz.
  You can use USART1 to watch the frequency of the input signal.The USART1 is 
  configured as follow:
    - BaudRate    = 115200 baud  
    - Word Length = 8 Bits
    - One Stop Bit
    - No parity
    - Hardware flow control disabled (RTS and CTS signals)
    - Receive and transmit enabled

/****************** (C) COPYRIGHT 2014 GIGADEVICE *********END OF FILE*********/

/**
  ******************************************************************************
  * @file    I2C/Interrupt_MasterTransmitter&SlaveReceiver/readme.txt
  * @author  MCU SD 
  * @version V1.0
  * @date    6-Sep-2014 
  * @brief   Description of the Interrupt_MasterTransmitter&SlaveReceiver demo.
  ******************************************************************************
  */

  @brief
    This demo is based on the GD32107C-EVAL board, it shows how to use the I2C 
  interrupt programming mode in master transmitting mode or slave receiving mode.
  In this demo, I2C1 is operated as the master transmitter and I2C2 as the slave 
  receiver.Moreover,the SCL line and SDA line of I2C1 interface are controled by 
  the I/O pin PB6 and PB7 respectively. The SCL and SDA of I2C2 are controled by 
  the pin PB10 and PB11 respectively.
    This demo will send the data of I2C_Buf_Write array through I2C1 interface 
  to the I2C2,and it will store the data received by I2C2 in the I2C_Buf_Read 
  array.If this transmission can send and receive data correctly, LED2 and LED3 
  will be turned on. Otherwise, turn on all the LEDs.

  @note
    We shoud use the jumper to connect the PB6 and PB10. The PB7 and PB11 are 
  connected as well.

/****************** (C) COPYRIGHT 2014 GIGADEVICE *********END OF FILE*********/
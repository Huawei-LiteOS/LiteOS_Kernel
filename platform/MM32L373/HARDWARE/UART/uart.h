#ifndef __UART_H
#define __UART_H
#include "stdio.h"	
#include "sys.h" 
//����1��ʼ��		   
void uart_initwBaudRate(u32 bound);
//����һ���ֽ�
char uartWriteByte(char ch);
#endif



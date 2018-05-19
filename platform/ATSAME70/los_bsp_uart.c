#include "sam.h"
#include "los_bsp_uart.h"
#include "Board_LED.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "los_demo_debug.h"
#include "dbg_console.h"

void LOS_EvbUartInit(void)
{
#if 0
	uint32_t ul_sr;
	PMC->PMC_WPMR = 0x504D4300;             /* Disable write protect            */
	PMC->PMC_PCER0 = (1UL << ID_PIOA );      /* enable UART3 clock                */
	PMC->PMC_PCER1 = (1UL << (ID_UART3-32));

	  /* Configure UART0 Pins (PD30 = TX, PD28 = RX). */
  PIOA->PIO_IDR        =  (PIO_PD28A_URXD3 | PIO_PD30A_UTXD3);
	
	ul_sr = PIOA->PIO_ABCDSR[0];
	PIOA->PIO_ABCDSR[0] &= (~(PIO_PD28A_URXD3 | PIO_PD30A_UTXD3) & ul_sr);
	ul_sr = PIOA->PIO_ABCDSR[1];
	PIOA->PIO_ABCDSR[1] &= (~(PIO_PD28A_URXD3 | PIO_PD30A_UTXD3) & ul_sr);

  PIOA->PIO_PDR        =  (PIO_PD28A_URXD3 | PIO_PD30A_UTXD3);
	PIOA->PIO_PUDR       =  (PIO_PD28A_URXD3 | PIO_PD30A_UTXD3);
	
  /* Configure UART3 for 115200 baud. */
  UART3->UART_CR   = (UART_CR_RSTRX | UART_CR_RSTTX) |
                     (UART_CR_RXDIS | UART_CR_TXDIS);
	UART3->UART_BRGR = (SystemCoreClock / 115200) / 16;
  UART3->UART_MR   =  (0x4u <<  9);        /* (UART) No Parity                 */
  UART3->UART_CR   = UART_CR_RXEN | UART_CR_TXEN;
	
	PMC->PMC_WPMR = 0x504D4301;             /* Enable write protect             */
#endif	
//usart1 EDBUG
	DBG_Configure(115200,150000000);
	return ;
}


/*************************************************************************************************
 *  ���ܣ��򴮿�1����һ���ַ�                                                                    *
 *  ������(1) ��Ҫ�����͵��ַ�                                                                   *
 *  ���أ�                                                                                       *
 *  ˵����                                                                                       *
 *************************************************************************************************/
void LOS_EvbUartWriteByte(char c)
{
	DBG_PutChar((uint8_t)c);
}

/*************************************************************************************************
 *  ���ܣ��򴮿�1����һ���ַ���                                                                  *
 *  ������(1) ��Ҫ�����͵��ַ���                                                                 *
 *  ���أ�                                                                                       *
 *  ˵����                                                                                       *
 *************************************************************************************************/
void LOS_EvbUartWriteStr(const char* str)
{
    while (*str)
    {
			LOS_EvbUartWriteByte(*str++);
    }
	return ;
}


/*************************************************************************************************
 *  ���ܣ��Ӵ���1����һ���ַ�                                                                    *
 *  ������(1) �洢���յ����ַ�                                                                   *
 *  ���أ�                                                                                       *
 *  ˵����                                                                                       *
 *************************************************************************************************/
void LOS_EvbUartReadByte(char* c)
{
    *c = (char)DBG_GetChar();
}


static char _buffer[256];
void LOS_EvbUartPrintf(char* fmt, ...)
{
    int i;
    va_list ap;
    va_start(ap, fmt);
    vsprintf(_buffer, fmt, ap);
    va_end(ap);

    for (i = 0; _buffer[i] != '\0'; i++)
    {
        LOS_EvbUartWriteByte(_buffer[i]);
    }
	return ;
}

#ifndef LOS_KERNEL_TEST_KEIL_SWSIMU
///�ض���c�⺯��printf�����ڣ��ض�����ʹ��printf����
int fputc(int ch, FILE *f)
{
		/* ����һ���ֽ����ݵ�����USART */
		LOS_EvbUartWriteByte(ch);	
	
		return (ch);
}
#endif


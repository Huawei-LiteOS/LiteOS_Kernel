#include "uart.h"

/*
#ifdef __GNUC__
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif 

#ifdef USE_IAR
PUTCHAR_PROTOTYPE {
    while((UART1->CSR & ((uint16_t)0x0001)) == 0 );//ѭ������,ֱ���������   
    UART1->TDR = (ch & (uint16_t)0x00FF);      
    return ch;
}

#else
#pragma import(__use_no_semihosting)             
//��׼����Ҫ��֧�ֺ���                 
struct __FILE { 
    int handle; 
};

FILE __stdout;       
//����_sys_exit()�Ա���ʹ�ð�����ģʽ    
_sys_exit(int x) { 
    x = x; 
}

//�ض���fputc���� 
int fputc(int ch, FILE *f) {      
    while((UART1->CSR & ((uint16_t)0x0001)) == 0 );//ѭ������,ֱ���������   
    UART1->TDR = (ch & (uint16_t)0x00FF);      
    return ch;
}
#endif 
*/

void Uart1_Init(void) {
	//GPIO�˿�����	 
	RCC->AHBENR |= 1<<17;   //ʹ��PORTA��ʱ��  
	RCC->APB2ENR |= 1<<14;  //ʹ�ܴ���ʱ�� 
		
	GPIOA->AFRH &= 0xF00F;
	GPIOA->AFRH |= 0x110;
	
	//UART ��ʼ������
	UART1->BRR = (sys_clk_freq / 16) / (115200);
  UART1->FRA = (sys_clk_freq / 16) % (115200);
	UART1->CCR |= 0x30; //110000
	UART1->GCR |= 0x19;  //11001;
	UART1->GCR |= 0x0001;                    //ʹ�ܴ���1 
	
	GPIOA->CRH &= 0XFFFFF00F;//IO״̬����
	GPIOA->CRH |= 0X000008B0;//IO״̬����
}

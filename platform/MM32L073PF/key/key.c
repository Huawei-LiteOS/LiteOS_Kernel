#include "key.h"

//������ʼ������ 
//PA0 PC13 PB10 PB11���ó�����
void KEY_Init(void) {
	RCC->AHBENR |= 0xF << 17;   //RCC->APB2ENR|=1<<2;  //ʹ��PORTAʱ��	   	    
	
	GPIOA->CRL &= 0XFFFFFFF0;	//PA0���ó�����	,K2(WK_UP)
	GPIOA->CRL |= GPIO_CRL_CNF0_1;   
	
	GPIOC->CRH &= 0XFF0FFFFF;	//PC13���ó�����,K1	  
	GPIOC->CRH |= GPIO_CRH_CNF13_1;   
	GPIOC->ODR |= GPIO_ODR_ODR13;	   	//PC13���� 
	
	GPIOB->CRH &= 0XFFFF00FF;	//PB10,PB11���ó�����,K3,K4	  
	GPIOB->CRH |= GPIO_CRH_CNF10_1 | GPIO_CRH_CNF11_1;   
	GPIOB->ODR |= GPIO_ODR_ODR10 | GPIO_ODR_ODR11;	   	//PB10,PB11���� 
	
}

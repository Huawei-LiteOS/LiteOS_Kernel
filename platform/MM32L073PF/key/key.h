#ifndef __KEY_H
#define __KEY_H	 
#include "MM32L073PF.h"

//////////////////////////////////////////////////////////////////////////////////	 
//������
//������������	   
//////////////////////////////////////////////////////////////////////////////////   	 


#define KEY1    ((GPIOC->IDR & 0x2000) ? 1 : 0)  //���� //��ȡ����1  ������ֵΪ1��Ϊ1����Ϊ0
#define WK_UP   ((GPIOA->IDR & 0x1) ? 1 : 0)  //���� //��ȡ����2 
#define KEY3    ((GPIOB->IDR & 0x400) ? 1 : 0)  //���� //��ȡ����3
#define KEY4    ((GPIOB->IDR & 0x800) ? 1 : 0) //���� //��ȡ����4

#define KEY1_PRES	1		//KEY1 
#define WKUP_PRES	2		//WK_UP  
#define KEY3_PRES	3		//KEY3 
#define KEY4_PRES	4		//KEY4 

void KEY_Init(void);//IO��ʼ��

#endif /* __KEY_H */

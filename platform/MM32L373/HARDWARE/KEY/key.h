#ifndef __KEY_H
#define __KEY_H	 
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������
//������������	   
//////////////////////////////////////////////////////////////////////////////////   	 


//#define KEY0 PCin(5)   	
//#define KEY1 PAin(15)	 
//#define WK_UP  PAin(0)	 
 

#define KEY3  GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_10)//��ȡ����0
#define KEY4  GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_15)//��ȡ����1
#define WK_UP   GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)//��ȡ����2 
 

#define KEY3_PRES	1		//KEY3  
#define KEY4_PRES	2		//KEY4 
#define WKUP_PRES	3		//WK_UP  

void KEY_Init(void);//IO��ʼ��
u8 KEY_Scan(u8 mode);  	//����ɨ�躯��					    
#endif

#ifndef _LOS_BSP_LED_H
#define _LOS_BSP_LED_H

#ifdef LOS_STM32F103RB

#include "stm32f10x.h"


/* ����LED���ӵ�GPIO�˿�, �û�ֻ��Ҫ�޸�����Ĵ��뼴�ɸı���Ƶ�LED���� */
#define macLED1_GPIO_PORT    	GPIOB			              /* GPIO�˿� */
#define macLED1_GPIO_CLK 	    RCC_APB2Periph_GPIOB		/* GPIO�˿�ʱ�� */
#define macLED1_GPIO_PIN		  GPIO_Pin_0			          /* LED���ź� */

#define macLED2_GPIO_PORT    	GPIOA			              /* GPIO�˿� */
#define macLED2_GPIO_CLK 	    RCC_APB2Periph_GPIOA		/* GPIO�˿�ʱ�� */
#define macLED2_GPIO_PIN		  GPIO_Pin_5			         /* LED���ź� */

#define macLED3_GPIO_PORT    	GPIOB			              /* GPIO�˿� */
#define macLED3_GPIO_CLK 	    RCC_APB2Periph_GPIOF		/* GPIO�˿�ʱ�� */
#define macLED3_GPIO_PIN		  GPIO_Pin_5			          /* LED���ź� */


/* ���κ꣬��������������һ��ʹ�� */
#define LED1(a)	if (a)	\
					GPIO_SetBits(macLED1_GPIO_PORT,macLED1_GPIO_PIN);\
					else		\
					GPIO_ResetBits(macLED1_GPIO_PORT,macLED1_GPIO_PIN)

#define LED2(a)	if (a)	\
					GPIO_SetBits(macLED2_GPIO_PORT,macLED2_GPIO_PIN);\
					else		\
					GPIO_ResetBits(macLED2_GPIO_PORT,macLED2_GPIO_PIN)

#define LED3(a)	if (a)	\
					GPIO_SetBits(macLED2_GPIO_PORT,macLED3_GPIO_PIN);\
					else		\
					GPIO_ResetBits(macLED2_GPIO_PORT,macLED3_GPIO_PIN)


/* ֱ�Ӳ����Ĵ����ķ�������IO */
#define	digitalHi(p,i)			{p->BSRR=i;}			//����Ϊ�ߵ�ƽ		
#define digitalLo(p,i)			{p->BRR=i;}				//����͵�ƽ
#define digitalToggle(p,i)		{p->ODR ^=i;}			//�����ת״̬


/* �������IO�ĺ� */
#define LED1_TOGGLE		digitalToggle(macLED1_GPIO_PORT,macLED1_GPIO_PIN)
#define LED1_OFF		digitalHi(macLED1_GPIO_PORT,macLED1_GPIO_PIN)
#define LED1_ON			digitalLo(macLED1_GPIO_PORT,macLED1_GPIO_PIN)

#define LED2_TOGGLE		digitalToggle(macLED2_GPIO_PORT,macLED2_GPIO_PIN)
#define LED2_OFF		digitalHi(macLED2_GPIO_PORT,macLED2_GPIO_PIN)
#define LED2_ON			digitalLo(macLED2_GPIO_PORT,macLED2_GPIO_PIN)

#define LED3_TOGGLE		digitalToggle(macLED2_GPIO_PORT,macLED3_GPIO_PIN)
#define LED3_OFF		digitalHi(macLED2_GPIO_PORT,macLED3_GPIO_PIN)
#define LED3_ON			digitalLo(macLED2_GPIO_PORT,macLED3_GPIO_PIN)

void LED_GPIO_Config(void);

#endif


#define LED_ON	  (1)
#define LED_OFF	  (0)
#define LOS_LED1	(0)
#define LOS_LED2	(1)
#define LOS_LED3	(2)
#define LOS_LED4	(3)
#define LOS_LEDX	(4)


void LOS_EvbLedInit(void);
void LOS_EvbLedControl(int index, int cmd);

#endif

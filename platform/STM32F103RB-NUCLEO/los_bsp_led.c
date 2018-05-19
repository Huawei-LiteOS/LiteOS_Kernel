#include "stdint.h"
#include "los_bsp_led.h"

/******************************************************************************
	here include some special hearder file you need
******************************************************************************/



/*****************************************************************************
 Function    : LOS_EvbLedInit
 Description : Init LED device
 Input       : None
 Output      : None
 Return      : None
 *****************************************************************************/
void LOS_EvbLedInit(void)
{
#ifdef LOS_STM32F103RB
		/*����һ��GPIO_InitTypeDef���͵Ľṹ��*/
		GPIO_InitTypeDef GPIO_InitStructure;

		/*����GPIOB��GPIOF������ʱ��*/
		RCC_APB2PeriphClockCmd( macLED1_GPIO_CLK|macLED2_GPIO_CLK|macLED3_GPIO_CLK, ENABLE); 

		/*ѡ��Ҫ���Ƶ�GPIOB����*/															   
		GPIO_InitStructure.GPIO_Pin = macLED1_GPIO_PIN;	

		/*��������ģʽΪͨ���������*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   

		/*������������Ϊ50MHz */   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

		/*���ÿ⺯������ʼ��GPIOB0*/
		GPIO_Init(macLED1_GPIO_PORT, &GPIO_InitStructure);	
		
		/*ѡ��Ҫ���Ƶ�GPIOF����*/															   
		GPIO_InitStructure.GPIO_Pin = macLED2_GPIO_PIN;

		/*���ÿ⺯������ʼ��GPIOF7*/
		GPIO_Init(macLED2_GPIO_PORT, &GPIO_InitStructure);
		
		/*ѡ��Ҫ���Ƶ�GPIOF����*/															   
		GPIO_InitStructure.GPIO_Pin = macLED3_GPIO_PIN;

		/*���ÿ⺯������ʼ��GPIOF7*/
		GPIO_Init(macLED3_GPIO_PORT, &GPIO_InitStructure);			  

		/* �ر�����led��	*/
		GPIO_SetBits(macLED1_GPIO_PORT, macLED1_GPIO_PIN);
		
		/* �ر�����led��	*/
		GPIO_SetBits(macLED2_GPIO_PORT, macLED2_GPIO_PIN);	 
    
    /* �ر�����led��	*/
		GPIO_SetBits(macLED3_GPIO_PORT, macLED3_GPIO_PIN);	 
#endif

	return ;
}

/*************************************************************************************************
 *  Function    ��LOS_EvbLedControl
 *  Discription : Led control function
 *  Input       : (1) index Led's index                                                                 
 *                (2) cmd   Led on or off  
 *  Output      : None
 *  Return      : None                                                                                                                                                            
**************************************************************************************************/
void LOS_EvbLedControl(int index, int cmd)
{
#ifdef LOS_STM32F103RB
    switch (index)
    {
        case LOS_LED1:
        {
            if (cmd == LED_ON)
            {
                LED1_ON; 
            }
            else
            {
                LED1_OFF; 
            }
            break;
        }
        case LOS_LED2:
        {
            if (cmd == LED_ON)
            {
                LED2_ON;
            }
            else
            {
                LED2_OFF;
            }
            break;
        }
        case LOS_LED3:
        {
            if (cmd == LED_ON)
            {
                LED3_ON; 
            }
            else
            {
                LED3_OFF;
            }
            break;
        }
        default:
        {
            break;
        }
    }
#endif
	return ;
}


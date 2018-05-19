#ifndef _LOS_BSP_LED_H
#define _LOS_BSP_LED_H

#define LED_ON	    (1)
#define LED_OFF	    (0)
#define LOS_LED1	(0)
#define LOS_LED2	(1)



void LOS_EvbLedInit(void);
void LOS_EvbLedControl(int index, int cmd);
#endif


#ifndef _SYSTICK_H_
#define _SYSTICK_H_

#include "hw_stm32f051r8.h"
/*****************/
void Systick_init(void);
void Start_systick(void);
unsigned int Get_state_sys(void);
void delay_ms (void);
#endif
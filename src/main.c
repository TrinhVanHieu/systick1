#include "project.h"


/*************************************************************************************************/

void delay(unsigned int timeout)
{
    unsigned int t1, t2;
    for (t1 = 0; t1 < timeout; t1++)
    {
        for (t2 = 0; t2 < 0xFFF; t2++)
        {
          asm(" nop");
        }
    }
}


void main(void)
{
    system_init();
    enabled_clock();
    pin_init();
  
    interrupt_init();

	while(1)
	{
		led_on (LD3_PIN); led_on (LD4_PIN);
		delay_ms(500);
		led_off (LD3_PIN); led_off (LD4_PIN);
		delay_ms (500);
	}
}


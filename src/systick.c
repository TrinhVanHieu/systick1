#include "project.h"
/***********************************/
unsigned int count;
void Systick_init(void)
{
	unsigned int tmprep;
	/*Disable systick - disable interrupt - clear flag*/
	write_reg(SYST_CSR, 0x0u);
	
	/*source clock - processor - 1*/
	tmprep = read_reg(SYST_CSR, ~(1 << 2));
	tmprep = tmprep | (1 << 2);
	write_reg(SYST_CSR, tmprep);
	
	/*clear value of VCR*/
	write_reg(SYST_CVR, 0x0u);
}

void Start_systick(void)
{
	write_reg(SYST_RVR, value);
	
	/*8000 tick = 1ms*/
	write_reg(SYST_RVR, 0x1F3Fu); 
	
	/*start systick*/
	unsigned int tmprep;
	tmprep = read_reg(SYST_CSR, ~(1 << 0));
	tmprep = tmprep | (1 << 0);
	write_reg(SYST_CSR, tmprep);
	
}

unsigned int Get_state_sys(void)
{
	unsigned int tmprep;
	
	/*flag bit 16*/
	tmprep = read_reg(SYST_CSR, (1 << 16));
	tmprep = tmprep >> 16;
	
	return tmprep;
}

void delay_ms (unsigned int value)
{
	while (count <= value)
	{
		do
		{
			count++;
		}
		while(0 == Get_state_sys());
	}
}
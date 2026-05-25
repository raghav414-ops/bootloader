#include "stm32f446xx.h"


void fpu_enable(void)
{
	/* enable floating point uit. enable CP10 and CP11 Full access*/
	SCB->CPACR |=(1<<20);
	SCB->CPACR |=(1<<21);
	SCB->CPACR |=(1<<22);
	SCB->CPACR |=(1<<23);
}

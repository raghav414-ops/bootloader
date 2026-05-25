#include "uart.h"
#define GPIOAEN (1U<<0)

void debug_uart_init(void){
	/* enable clock access to GPIOA*/
	RCC->AHB1ENR |= GPIOAEN;
	/* set mode of PA2 to alternate function mode*/
	GPIOA->MODER &=~(1U<<4);
	GPIOA->MODER |=(1U<<5);
	/* set alternate function type too AF7(UART2_TX)*/
	GPIOA->AFR[0] |=(1U<<8);
	GPIOA->AFR[0] |=(1U<<9);
	GPIOA->AFR[0] |=(1U<<10);
	GPIOA->AFR[0] &=~(1U<<11);
	/* enable clock access to uart2*/

	/* configure uart baudrate*/
	/* configure transfer direction*/
}

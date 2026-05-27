#include "bsp.h"
#include "stm32f446xx.h"

#define GPIOAEN (1U<<0)
#define GPIOCEN (1U<<2)
#define PIN5 	(1U<<5)
#define LED_PIN PIN5
#define PIN13 	(1U<<13)
#define BTN_PIN PIN13
void led_Init(void)
{
	//enable clock access to GPIOA
	RCC->AHB1ENR |=GPIOAEN;
	GPIOA->MODER |=(1U<<10);
	GPIOA->MODER &=~(1U<<11);
	//Set PA5 mode to output mode
}

void led_on(void)
{
	//set PA5 high
	GPIOA->ODR |=LED_PIN;
}

void led_off(void)
{
	//set PA5 low
	GPIOA->ODR &= ~LED_PIN;

}

void button_Init(void)
{
	//enable clock access to clock PORTC
	RCC->AHB1ENR |=GPIOCEN;
	// SET pc13 AS an input pin
	GPIOC->MODER &=~(1U<<26);
	GPIOC->MODER &=~(1U<<27);
}

bool get_btn_state(void)
{
	//chck if button is pressed
	if(GPIOC->IDR & BTN_PIN)
	{
		return false;
	}
	else
	{
		return true;
	}
}

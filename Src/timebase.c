#include "timebase.h"
#include "stm32f446xx.h"
//#include <stdio.h>
#define CTRL_ENABLE (1U<<0)
#define CTRL_TICKINT (1U<<1)
#define CTRL_CLKSRC (1U<<2)
#define CTRL_CNTFLAG (1U<<16)

#define ONE_SEC_LOAD 16000000

#define MAX_DELAY    0xFFFFFFFF
#define TICK_FREQ 	 1
//global variable tick that holds the number of ticks that our clock has made
volatile uint32_t g_curr_tick;
volatile uint32_t g_curr_tick_p;
uint32_t get_tick(void);
//volatile uint32_t tick_freq = 1;

// delay in seconds
//void delay(uint32_t delay)
//{
//	uint32_t tickstart = get_tick();
//	uint32_t wait = delay;
//
//	if(wait < MAX_DELAY)
//	{
//		wait += (uint32_t)TICK_FREQ;
//	}
//
//	while((get_tick() - tickstart) < wait){}
//}

void delay(uint32_t delay_ticks)
{
    uint32_t tickstart = get_tick();

    // This exact subtraction handle 32-bit overflow flawlessly
    while ((get_tick() - tickstart) < delay_ticks)
    {
        // Do nothing, just wait
    }
}

uint32_t get_tick(void)
{
//	__disable_irq();
//	g_curr_tick_p = g_curr_tick;
//	__enable_irq();
	return g_curr_tick;
}

static void tick_increment(void)
{
	g_curr_tick += TICK_FREQ;
}

void timebase_init(void)
{
	//Disable global interrupts
	__disable_irq();
	//Load the timer with number of clock cycles per second
	SysTick->LOAD = (ONE_SEC_LOAD/TICK_FREQ) - 1;
	//Clear systick current value register
	SysTick->VAL = 0;
	//select internal clock source
	SysTick->CTRL = CTRL_CLKSRC;
	//enable interrupt
	SysTick->CTRL |= CTRL_TICKINT;
	//enable systick
	SysTick->CTRL |= CTRL_ENABLE;
	//enable global interrupts
	__enable_irq();
}

void SysTick_Handler(void)
{
	tick_increment();
}

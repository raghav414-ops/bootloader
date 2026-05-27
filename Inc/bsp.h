#ifndef __BSP_H__
#define __BSP_H__
#include<stdint.h>
#include<stdbool.h>

void led_Init(void);
void led_on(void);
void led_off(void);
void button_Init(void);
bool get_btn_state(void);
#endif

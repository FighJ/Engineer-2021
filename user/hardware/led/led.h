#ifndef LED_H
#define LED_H
#include "main.h"
#include "stm32f4xx.h"

#define FLOW_LED_A 0
#define FLOW_LED_B 1
#define FLOW_LED_C 2
#define FLOW_LED_D 3
#define FLOW_LED_E 4
#define FLOW_LED_F 5
#define FLOW_LED_G 6
#define FLOW_LED_H 7

void led_configuration(void);

extern void led_green_on(void);
extern void led_green_off(void);
extern void led_green_toggle(void);

extern void led_red_on(void);
extern void led_red_off(void);
extern void led_red_toggle(void);

extern void flow_led_on(uint16_t num);
extern void flow_led_off(uint16_t num);
extern void flow_led_toggle(uint16_t num);

extern void all_flow_led_on(void);
extern void all_flow_led_off(void);
extern void all_flow_led_toggle(void);

#endif

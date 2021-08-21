#ifndef _RELAY_H
#define _RELAY_H

#include "stm32f4xx.h"

#define table_up GPIO_SetBits(GPIOF, GPIO_Pin_0)
#define table_down GPIO_ResetBits(GPIOF, GPIO_Pin_0)

#define arm_catch GPIO_SetBits(GPIOF, GPIO_Pin_1)
#define arm_drop GPIO_ResetBits(GPIOF, GPIO_Pin_1)

#define help_out power_ctrl_on(0)
#define help_back power_ctrl_off(0)

#define carry_up GPIO_SetBits(GPIOE, GPIO_Pin_4)
#define carry_down GPIO_ResetBits(GPIOE, GPIO_Pin_4)


extern void gpio_up_init(void);
extern void gpio_close_init(void);
extern void gpio_forward_init(void);
extern void gpio_open_init(void);
extern void gpio_relays_init(void);



#endif

#ifndef _PWM_H
#define _PWM_H
#include "stm32f4xx.h"

#define gimbal_pitch_mid_angle 1700
#define gimbal_yaw_mid_angle 2300

#define gimbal_pitch_max_angle 2200
#define gimbal_pitch_min_angle 1000

#define gimbal_pitch_max_real_angle 45
#define gimbal_pitch_min_real_angle -45

extern void Gimbal_PWM_Init(void);
extern void PWM_TIM2_Init(u32 arr,u32 psc);
extern void PWM_TIM4_Init(u32 arr,u32 psc);
extern void PWM_TIM5_Init(u32 arr,u32 psc);

extern void Gimbal_Angle_control(int16_t angle_pitch);
	
#endif

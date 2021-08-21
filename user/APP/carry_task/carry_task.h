#ifndef CARRY_TASK_H
#define CARRY_TASK_H

#include "main.h"
#include "stm32f4xx.h"
#include "pid.h"
#include "CAN_Receive.h"

//CARRY速度环PID参数 最大输出 积分限幅
#define CARRY_SPEED_KP 2.0f
#define CARRY_SPEED_KI 0.0f
#define CARRY_SPEED_KD 0.0f
#define CARRY_SPEED_MAX_OUT 10000.0f
#define CARRY_SPEED_MAX_IOUT 1000.0f

//CARRY角度环PID参数 最大输出 积分限幅
#define CARRY_ANGLE_KP 5.0f
#define CARRY_ANGLE_KI 0.0f
#define CARRY_ANGLE_KD 0.0f
#define CARRY_ANGLE_MAX_OUT 10000.0f
#define CARRY_ANGLE_MAX_IOUT 1000.0f

//模式赋值变量
extern void carry_task(void *pvParameters);
#endif

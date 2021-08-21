#ifndef CHASSIS_BEHAVIOUR_SIMPLE_H
#define CHASSIS_BEHAVIOUR_SIMPLE_H

#include "main.h"
#include "math.h"
#include "stm32f4xx.h"
#include "chassis_task.h"
#include "FreeRTOSConfig.h"
#include "FreeRTOS.h"
#include "task.h"
#include "delay.h"
#include "pid.h"
#include "Remote_Control.h"
#include "CAN_Receive.h"
#include "user_lib.h"
#include "arm_behavior.h"

//WHEEL 速度环PID参数 最大输出 积分限幅
#define WHEEL_SPEED_KP 25.0f
#define WHEEL_SPEED_KI 0.1f
#define WHEEL_SPEED_KD 0.0f
#define WHEEL_SPEED_MAX_OUT 16000.0f
#define WHEEL_SPEED_MAX_IOUT 1000.0f

//遥控器速度解算幅度
#define RC_SPEED 3

#define CHASSIS_ACCEL_X_NUM 0.5f
#define CHASSIS_ACCEL_Y_NUM 0.5f	

#define	CHASSIS_CONTROL_TIME 0.002 //s

typedef enum
{
  CHASSIS_ZERO_FORCE = 0, //底盘无力
	CHASSIS_RC_CONTROL,
	CHASSIS_KEY_CONTROL  //PC控制
} Chassis_Mode;

extern void chassis_init(void);
extern void chassis_mode_behaviour(void);

#endif

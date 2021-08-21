#ifndef ARM_BEHAVIOUR_H
#define ARM_BEHAVIOUR_H

#include "main.h"
#include "math.h"
#include "stm32f4xx.h"
#include "arm_task.h"
#include "FreeRTOSConfig.h"
#include "FreeRTOS.h"
#include "task.h"
#include "delay.h"
#include "pid.h"
#include "Remote_Control.h"
#include "CAN_Receive.h"
#include "user_lib.h"

//ARM速度环PID参数 最大输出 积分限幅
#define ARM_SPEED_KP 2.0f
#define ARM_SPEED_KI 0.0f
#define ARM_SPEED_KD 0.0f
#define ARM_SPEED_MAX_OUT 8000.0f
#define ARM_SPEED_MAX_IOUT 1000.0f

//ARM角度环PID参数 最大输出 积分限幅
#define ARM_ANGLE_KP 10.0f
#define ARM_ANGLE_KI 0.0f
#define ARM_ANGLE_KD 0.0f
#define ARM_ANGLE_MAX_OUT 8000.0f
#define ARM_ANGLE_MAX_IOUT 1000.0f

//TABLE角度环PID参数 最大输出 积分限幅
#define TABLE_ANGLE_KP 0.0f
#define TABLE_ANGLE_KI 0.0f
#define TABLE_ANGLE_KD 0.0f
#define TABLE_ANGLE_MAX_OUT 16000.0f
#define TABLE_ANGLE_MAX_IOUT 1000.0f

//TABLE角度环PID参数 最大输出 积分限幅
#define TABLE_SPEED_KP 0.0f
#define TABLE_SPEED_KI 0.0f
#define TABLE_SPEED_KD 0.0f
#define TABLE_SPEED_MAX_OUT 16000.0f
#define TABLE_SPEED_MAX_IOUT 1000.0f

typedef enum
{
	ARM_KEY,
	ZERO_FORCE,//电机无力
	ARM_RC,
	
	ARM_FORWARD,//机械臂抬起准备抓取
	ARM_BACK,//机械臂放下
} Arm_Mode;

#endif

#ifndef GIMBAL_BEHAVIOUR_SIMPLE_H
#define GIMBAL_BEHAVIOUR_SIMPLE_H

#include "main.h"
#include "math.h"
#include "stm32f4xx.h"
#include "FreeRTOSConfig.h"
#include "FreeRTOS.h"
#include "task.h"
#include "pid.h"
#include "Remote_Control.h"
#include "CAN_Receive.h"

//PITCH 速度环PID参数 最大输出 积分限幅
#define PITCH_SPEED_KP 1.4f
#define PITCH_SPEED_KI 2.0f
#define PITCH_SPEED_KD 0.1f
#define PITCH_SPEED_MAX_OUT 30000.0f
#define PITCH_SPEED_MAX_IOUT 4000.0f
//YAW 速度环PID参数 最大输出 积分限幅
#define YAW_SPEED_KP 1.2f
#define YAW_SPEED_KI 1.0f
#define YAW_SPEED_KD 0.5f
#define YAW_SPEED_MAX_OUT 30000.0f
#define YAW_SPEED_MAX_IOUT 4000.0f
//PITCH 角度环PID参数 最大输出 积分限幅
#define PITCH_ANGLE_KP 100.0f
#define PITCH_ANGLE_KI 1.1f
#define PITCH_ANGLE_KD 50.0f
#define PITCH_ANGLE_MAX_OUT 10000.0f
#define PITCH_ANGLE_MAX_IOUT 4000.0f
//YAW 角度环PID参数 最大输出 积分限幅
#define YAW_ANGLE_KP 300.0f
#define YAW_ANGLE_KI 2.1f
#define YAW_ANGLE_KD 50.0f
#define YAW_ANGLE_MAX_OUT 10000.0f
#define YAW_ANGLE_MAX_IOUT 4000.0f

//云台移动速度
#define pitch_rc_speed 0.8f
#define yaw_rc_speed 2.0f
//云台转动最大角度
#define PITCH_MAX_ANGLE 400
#define YAW_MAX_ANGLE 1000

//电机码盘值最大以及中值
#define Half_ecd_range 4096
#define ecd_range 8191
//电机角度绝对零点
#define PITCH_Zero 4096
#define YAW_Zero 4096
//电机是否反装
#define PITCH_IF_TURN 0
#define YAW_IF_TURN 0
//反装
#define TURN 1
//未反装
#define UN_TURN 0

//云台校准时间
#define Check_Max_Time 1000

typedef enum
{
  GIMBAL_ZERO_FORCE = 0, //云台无力
  GIMBAL_RC_CONTROL,  //遥控器或PC控制
	GIMBAL_RC_AUTO,
} Gimbal_Mode;

typedef enum
{
  UP = 0,
  MID,  
	DOWN,
} Gimbal_check_Mode;//左拨杆云台模式

extern const RC_ctrl_t *GIMBAL_RC;
extern const RC_ctrl_t *LAST_GIMBAL_RC;
//云台电机CAN发送电流值
extern int16_t current_pitch;
extern int16_t current_yaw;

//云台校准初始化
extern int16_t Check_Time;

//偏航云台偏航角计算
extern fp32 INS_YAW;
extern fp32 GIMBAL_INS_YAW;
extern fp32 GIMBAL_INS_YAW_TEMP;

extern const motor_measure_t *moto_yaw;

//云台PID初始化
extern void gimbal_init(void);
//判断电机是否反装
extern void gimbal_turn_check(int16_t PITCH, int16_t YAW);
//不同模式下云台行为
extern void gimbal_mode_behaviour(void);
//检测左拨杆云台状态
extern void gimbal_mode_check(void);
extern void mode_change(void);
//云台电机驱动函数
extern void CAN_CMD_GIMBAL_SIMPLE(int16_t PITCH, int16_t YAW);
	
#endif

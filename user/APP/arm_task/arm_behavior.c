#include "arm_behavior.h"
#include "user_lib.h"
#include "User_Task.h"
#include "pid.h"
#include "CAN_Receive.h"
#include "relay.h"
#include "keyboard_control.h"

//机械臂角度参数
int32_t angle_arm_init = 0;
int32_t angle_arm = 0;
int32_t angle_arm_remain = 0;
int32_t angle_arm_out = 0;

//初始化电流初值
int16_t current_arm_left = 0;
int16_t current_arm_right = 0;

//机械臂3508电机PID结构体
PidTypeDef arm_angle, arm_speed;

//滑台2006电机PID结构体
PidTypeDef table_angle, table_speed;

//机械臂3508电机PID参数定义
static const fp32 PID_ARM_SPEED[] = {ARM_SPEED_KP, ARM_SPEED_KI, ARM_SPEED_KD};
static const fp32 PID_ARM_ANGLE[] = {ARM_ANGLE_KP, ARM_ANGLE_KI, ARM_ANGLE_KD};

//滑台2006电机PID参数定义
static const fp32 PID_TABLE_SPEED[] = {TABLE_SPEED_KP, TABLE_SPEED_KI, TABLE_SPEED_KD};
static const fp32 PID_TABLE_ANGLE[] = {TABLE_ANGLE_KP, TABLE_ANGLE_KI, TABLE_ANGLE_KD};

//3508电机结构体定义
const motor_measure_t *arm_left;
const motor_measure_t *arm_right;
//2006电机结构体定义
const motor_measure_t *table_left;
const motor_measure_t *table_right;

void arm_init(void)
{		
	  arm_left = get_Arm_Left_Motor_Measure_Point();
		table_left = get_Table_Left_Motor_Measure_Point();
		PID_Init(&arm_angle, PID_POSITION, PID_ARM_ANGLE, ARM_ANGLE_MAX_OUT, ARM_ANGLE_MAX_IOUT);
		PID_Init(&arm_speed, PID_POSITION, PID_ARM_SPEED, ARM_SPEED_MAX_OUT, ARM_SPEED_MAX_IOUT);
	
		PID_Init(&table_angle, PID_POSITION, PID_TABLE_ANGLE, TABLE_ANGLE_MAX_OUT, TABLE_ANGLE_MAX_IOUT);
		PID_Init(&table_speed, PID_POSITION, PID_TABLE_SPEED, TABLE_SPEED_MAX_OUT, TABLE_SPEED_MAX_IOUT);
		angle_arm_init = arm_left->total_ecd_out_3508;
}

void arm_mode_behaviour(void)
{
		if (MODE_ARM == ARM_KEY)
	{
		arm_left = get_Arm_Left_Motor_Measure_Point();
		table_left = get_Table_Left_Motor_Measure_Point();
		
//		angle_arm += rc_ctrl.mouse.z*1.0f;
		if(rc_ctrl.mouse.z > 0)
		{
			angle_arm += 10.0f;
		}
		else if(rc_ctrl.mouse.z < 0)
		{
			angle_arm -= 10.0f;
		}

		
		if(rc_ctrl.key.v == KEY_PRESSED_OFFSET_CTRL)
		{
			angle_arm = angle_arm - rc_ctrl.mouse.y/10;
		}
		if( angle_arm > 2000)
		angle_arm = 2000;
		if( angle_arm < 0)
		angle_arm = 0;
		angle_arm_out = angle_arm + angle_arm_init;
		
		angle_arm_remain = PID_Calc(&arm_angle, arm_left->total_ecd_out_3508, angle_arm_out);
	  current_arm_left = PID_Calc(&arm_speed, arm_left->speed_rpm, angle_arm_remain);
		current_arm_right = -current_arm_left;
		if(key_board_flag.press_l)
			arm_catch;
		else
			arm_drop;
		if(key_board_flag.key_b)
			table_down;
		else
			table_up;
			if (key_board_flag.key_z)
			{
		    CAN_CMD_ARM(current_arm_left, current_arm_right, -1500, -1500);
			}
			else
			{
		    CAN_CMD_ARM(current_arm_left, current_arm_right, 1500, 1500);
			}
	}
	if (MODE_ARM == ZERO_FORCE)
	{
		CAN_CMD_ARM(0, 0, 0 ,0);
	}
	if (MODE_ARM == ARM_RC)
	{
		arm_left = get_Arm_Left_Motor_Measure_Point();
		table_left = get_Table_Left_Motor_Measure_Point();
		angle_arm = angle_arm + rc_ctrl.rc.ch[3]/200;
		if( angle_arm > 2000)
			angle_arm = 2000;
		if( angle_arm < 0)
		angle_arm = 0;
		angle_arm_out = angle_arm + angle_arm_init;
		
		angle_arm_remain = PID_Calc(&arm_angle, arm_left->total_ecd_out_3508, angle_arm_out);
	  current_arm_left = PID_Calc(&arm_speed, arm_left->speed_rpm, angle_arm_remain);
		current_arm_right = -current_arm_left;
		if(key_board_flag.press_l)
			arm_catch;
		else
			arm_drop;
		if(key_board_flag.key_b)
			table_down;
		else
			table_up;
		CAN_CMD_ARM(current_arm_left, current_arm_right, 1500, 1500);
	}
}

#include "carry_task.h"
#include "user_lib.h"
#include "User_Task.h"
#include "pid.h"
#include "CAN_Receive.h"
#include "Remote_Control.h"
#include "keyboard_control.h"
#include "relay.h"
#include "power_ctrl.h"


#if INCLUDE_uxTaskGetStackHighWaterMark
uint32_t carry_task_stack;
#endif

//机械臂角度参数
int32_t angle_carryleft_init = 0;
int32_t angle_carryleft = 0;
int32_t angle_carryleft_remain = 0;
int32_t angle_carryleft_out = 0;

int32_t angle_carryright_init = 0;
int32_t angle_carryright = 0;
int32_t angle_carryright_remain = 0;
int32_t angle_carryright_out = 0;

//初始化电流初值
int16_t current_carry_left = 0;
int16_t current_carry_right = 0;

//电机结构体定义
const motor_measure_t *carry_left;
const motor_measure_t *carry_right;

//搬运臂2006电机PID结构体
PidTypeDef carry_angle, carry_speed;

//搬运臂2006电机PID参数定义
static const fp32 PID_CARRY_SPEED[] = {CARRY_SPEED_KP, CARRY_SPEED_KI, CARRY_SPEED_KD};
static const fp32 PID_CARRY_ANGLE[] = {CARRY_ANGLE_KP, CARRY_ANGLE_KI, CARRY_ANGLE_KD};

void carry_task(void *pvParameters)
{
	  CAN_CMD_CARRY(1000, -1700, 0, 0);
		vTaskDelay(1000);
	  carry_left = get_Carryforward_Left_Motor_Measure_Point();
		carry_right = get_Carryforward_Right_Motor_Measure_Point();
		PID_Init(&carry_angle, PID_POSITION, PID_CARRY_ANGLE, CARRY_ANGLE_MAX_OUT, CARRY_ANGLE_MAX_IOUT);
		PID_Init(&carry_speed, PID_POSITION, PID_CARRY_SPEED, CARRY_SPEED_MAX_OUT, CARRY_SPEED_MAX_IOUT);
	
		angle_carryleft_init = carry_left->total_ecd_out_2006;
    angle_carryright_init = carry_right->total_ecd_out_2006;
    while (1)
    {
			//左上键盘控制
			if(rc_ctrl.rc.s[1] == RC_SW_UP)
			{
				carry_left = get_Carryforward_Left_Motor_Measure_Point();
				carry_right = get_Carryforward_Right_Motor_Measure_Point();
				if(rc_ctrl.key.v == KEY_PRESSED_OFFSET_SHIFT + KEY_PRESSED_OFFSET_W)
					{
						angle_carryleft = angle_carryleft  - 5;
						angle_carryright = angle_carryright  + 5;
					}
				if(rc_ctrl.key.v == KEY_PRESSED_OFFSET_SHIFT + KEY_PRESSED_OFFSET_S)
					{
						angle_carryleft = angle_carryleft  + 5;
						angle_carryright = angle_carryright  - 5;
					}
				if( angle_carryleft < -14000)
					angle_carryleft = -14000;
				if( angle_carryleft > 0)
					angle_carryleft = 0;
				if( angle_carryright > 14000)
					angle_carryright = 14000;
				if( angle_carryright < 0)
					angle_carryright = 0;
				
				angle_carryleft_out = angle_carryleft + angle_carryleft_init;
				angle_carryright_out = angle_carryright + angle_carryright_init;
				
				angle_carryleft_remain = PID_Calc(&carry_angle, carry_left->total_ecd_out_2006, angle_carryleft_out);
				angle_carryright_remain = PID_Calc(&carry_angle, carry_right->total_ecd_out_2006, angle_carryright_out);
				
				current_carry_left = PID_Calc(&carry_speed, carry_left->speed_rpm, angle_carryleft_remain);
				current_carry_right = PID_Calc(&carry_speed, carry_right->speed_rpm, angle_carryright_remain);
				
				//鼠标左键前板勾起与放下
				if(key_board_flag.key_c)
					carry_up;
				else
					carry_down;
				CAN_CMD_CARRY(current_carry_left, current_carry_right, 0, 0);
			}
			
			//左中无力
			if(rc_ctrl.rc.s[1] == RC_SW_MID)
				CAN_CMD_CARRY(0, 0, 0, 0);
			
			if(rc_ctrl.rc.s[1] == RC_SW_DOWN)
			{
				carry_left = get_Carryforward_Left_Motor_Measure_Point();
				carry_right = get_Carryforward_Right_Motor_Measure_Point();
//				if(rc_ctrl.key.v == KEY_PRESSED_OFFSET_SHIFT + KEY_PRESSED_OFFSET_W)
//					{
						angle_carryleft = angle_carryleft  - rc_ctrl.rc.ch[3]/80;
						angle_carryright = angle_carryright  + rc_ctrl.rc.ch[3]/80;
//					}
				if( angle_carryleft < -14000)
					angle_carryleft = -14000;
				if( angle_carryleft > 0)
					angle_carryleft = 0;
				if( angle_carryright > 14000)
					angle_carryright = 14000;
				if( angle_carryright < 0)
					angle_carryright = 0;
				
				angle_carryleft_out = angle_carryleft + angle_carryleft_init;
				angle_carryright_out = angle_carryright + angle_carryright_init;
				
				angle_carryleft_remain = PID_Calc(&carry_angle, carry_left->total_ecd_out_2006, angle_carryleft_out);
				angle_carryright_remain = PID_Calc(&carry_angle, carry_right->total_ecd_out_2006, angle_carryright_out);
				
				current_carry_left = PID_Calc(&carry_speed, carry_left->speed_rpm, angle_carryleft_remain);
				current_carry_right = PID_Calc(&carry_speed, carry_right->speed_rpm, angle_carryright_remain);
				
				//鼠标左键前板勾起与放下
				if(key_board_flag.key_c)
					carry_up;
				else
					carry_down;
				CAN_CMD_CARRY(current_carry_left, current_carry_right, 0, 0);
			}
			
			//救援卡的伸出与下降
			if(key_board_flag.key_r)
				help_out;
			else
				help_back;
			
			//系统延时
      vTaskDelay(1);
			
#if INCLUDE_uxTaskGetStackHighWaterMark
        carry_task_stack = uxTaskGetStackHighWaterMark(NULL);
#endif
		}
}

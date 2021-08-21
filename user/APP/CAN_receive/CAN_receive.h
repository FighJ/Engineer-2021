#ifndef CANTASK_H
#define CANTASK_H
#include "main.h"

#define CHASSIS_CAN CAN2

//CAN发送和接收的ID
typedef enum
{
	  CAN_ARM_ALL_ID = 0x200,
    CAN_ARM_LEFT_ID = 0x201,//左臂3508电机
		CAN_ARM_RIGHT_ID = 0x202,//右臂3508电机
    CAN_TABLE_LEFT_ID = 0x203,//左滑台2006电机
	  CAN_TABLE_RIGHT_ID = 0x204,//右滑台2006电机

    CAN_CARRY_ALL_ID = 0x1FF,
    CAN_CARRYUP_LEFT_ID = 0x205,//障碍块上下左2006电机
    CAN_CARRYUP_RIGHT_ID = 0x206,//障碍块上下右2006电机
	  CAN_CARRYFORWARD_ID = 0x207,//障碍块前后2006电机

    CAN_CHASSIS_ALL_ID = 0x200,
    CAN_3508_M1_ID = 0x201,//左前
    CAN_3508_M2_ID = 0x202,//左后
    CAN_3508_M3_ID = 0x203,//右前
    CAN_3508_M4_ID = 0x204,//右后
} can_msg_id_e;

//RM电机统一数据结构体
typedef struct
{
    uint16_t ecd;
    int16_t speed_rpm;
    int16_t given_current;
    uint8_t temperate;
    int16_t last_ecd;
	
	  //以下为根据原始数据的推算量
		uint16_t	offset_ecd;
		int32_t		round_cnt;  //理论可记录524352圈
		int32_t		total_ecd;  //理论可记录4294967295编码值
		
		int32_t		total_ecd_out_2006;  //理论可记录14565圈
		int32_t		total_ecd_out_3508;  //理论可记录27305圈
		int32_t		total_ecd_out_6020;  //理论可记录524352圈
	
} motor_measure_t;

typedef struct
{
	uint8_t motor_yaw;
	uint8_t motor_pit;
	uint8_t motor_trigger;
	
	uint8_t motor_user[4];
	uint8_t motor_chassis[4];
	
}motor_feedback_time_t;

extern motor_feedback_time_t motor_feedback_time;

//CAN 发送 0x700的ID的数据，会引发M3508进入快速设置ID模式
extern void CAN_CMD_CHASSIS_RESET_ID(void);
//发送0x201-0x204机械臂电机控制命令
extern void CAN_CMD_ARM(int16_t User_Motor1, int16_t User_Motor2, int16_t User_Motor3, int16_t User_Motor4);
//发送0x205-0x208机械臂电机控制命令
extern void CAN_CMD_CARRY(int16_t User_Motor1, int16_t User_Motor2, int16_t User_Motor3, int16_t User_Motor4);
//发送底盘电机控制命令
extern void CAN_CMD_CHASSIS(int16_t motor1, int16_t motor2, int16_t motor3, int16_t motor4);

//返回机械臂左电机变量地址，通过指针方式获取原始数据
extern const motor_measure_t *get_Arm_Left_Motor_Measure_Point(void);
//返回机械臂右电机变量地址，通过指针方式获取原始数据
extern const motor_measure_t *get_Arm_Right_Motor_Measure_Point(void);
//返回滑台左电机变量地址，通过指针方式获取原始数据
extern const motor_measure_t *get_Table_Left_Motor_Measure_Point(void);
//返回滑台右电机变量地址，通过指针方式获取原始数据
extern const motor_measure_t *get_Table_Right_Motor_Measure_Point(void);
//返回搬运障碍块前后电机变量地址，通过指针方式获取原始数据
extern const motor_measure_t *get_Carryforward_Motor_Measure_Point(void);
//返回搬运障碍块上下左电机变量地址，通过指针方式获取原始数据
extern const motor_measure_t *get_Carryforward_Left_Motor_Measure_Point(void);
//返回搬运障碍块上下右电机变量地址，通过指针方式获取原始数据
extern const motor_measure_t *get_Carryforward_Right_Motor_Measure_Point(void);
//返回0x201-0x204其他大疆电机变量地址，通过指针方式获取原始数据
extern const motor_measure_t *get_User_Motor_Measure_Point(uint8_t i);
//返回底盘电机变量地址，通过指针方式获取原始数据
extern const motor_measure_t *get_Chassis_Motor_Measure_Point(uint8_t i);
extern	motor_measure_t motor_arm_left, motor_arm_right, motor_table_left, motor_table_right, motor_carryforward, motor_carryup_left, motor_carryup_right, motor_chassis[4];

#if GIMBAL_MOTOR_6020_CAN_LOSE_SLOVE
extern void GIMBAL_lose_slove(void);
#endif

#endif

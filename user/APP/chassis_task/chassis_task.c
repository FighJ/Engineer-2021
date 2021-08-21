#include "chassis_task.h"
#include "user_lib.h"

#if INCLUDE_uxTaskGetStackHighWaterMark
uint32_t chassis_task_stack;
#endif
int count = 0;
int power = 0;
int pick_count=0;//去障碍物夹爪标志位
int arm_count =0;//取矿夹爪标志位
int jig_count=0;//取矿夹爪伸缩标志位

void chassis_task(void *pvParameters)
{
	//底盘PID初始化
	chassis_init();
    while (1)
    {
			if(rc_ctrl.rc.s[0] == RC_SW_UP)
			{
				//底盘键盘操作
				MODE_CHASSIS = CHASSIS_KEY_CONTROL;
			}
			if(rc_ctrl.rc.s[0] == RC_SW_MID)
			{
				//底盘无力模式
				MODE_CHASSIS = CHASSIS_ZERO_FORCE;
			}
			if(rc_ctrl.rc.s[0] == RC_SW_DOWN)
			{
				//底盘遥控器操作
				MODE_CHASSIS = CHASSIS_RC_CONTROL;
			}

			chassis_mode_behaviour();
			
			//系统延时
      vTaskDelay(1);
			
#if INCLUDE_uxTaskGetStackHighWaterMark
        chassis_task_stack = uxTaskGetStackHighWaterMark(NULL);
#endif
    }
}

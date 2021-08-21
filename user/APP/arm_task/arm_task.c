#include "arm_task.h"
#include "user_lib.h"
#include "User_Task.h"
#include "pid.h"
#include "CAN_Receive.h"
#include "Remote_Control.h"
#include "relay.h"

#if INCLUDE_uxTaskGetStackHighWaterMark
uint32_t arm_task_stack;
#endif

uint8_t MODE_ARM = ZERO_FORCE;

void arm_task(void *pvParameters)
{
		//机械臂抬起
		table_up;
  	//时延1秒
		vTaskDelay(2000);
	  //机械臂数据初始化
		arm_init();
    while (1)
    {
			if(rc_ctrl.rc.s[1] == RC_SW_UP)
			{
				MODE_ARM = ARM_KEY;
			}
			if(rc_ctrl.rc.s[1] == RC_SW_MID)
			{
				MODE_ARM = ZERO_FORCE;
			}
			if(rc_ctrl.rc.s[1] == RC_SW_DOWN)
			{
				MODE_ARM = ARM_RC;
			}
			arm_mode_behaviour();
			
			//系统延时
      vTaskDelay(1);
			
#if INCLUDE_uxTaskGetStackHighWaterMark
        arm_task_stack = uxTaskGetStackHighWaterMark(NULL);
#endif
    }
}

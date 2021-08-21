#include "gimbal_task.h"
#include "User_Task.h"
#include "pwm.h"
#include "rc.h"
#include "Remote_Control.h"

#include "keyboard_control.h"

#include "FreeRTOSConfig.h"
#include "FreeRTOS.h"
#include "task.h"

#if INCLUDE_uxTaskGetStackHighWaterMark
uint32_t gimbal_task_stack;
#endif

int pitch_angle_zero = 0;
int pitch_angle = 0;
int cnt = 0;

void GIMBAL_task(void *pvParameters)
{

    while (1)
    {
			keyboard_flag_scan();
			if(rc_ctrl.rc.s[1] == RC_SW_UP)
			{
				if( (rc_ctrl.mouse.y < -10 && rc_ctrl.key.v != KEY_PRESSED_OFFSET_CTRL) || rc_ctrl.key.v == KEY_PRESSED_OFFSET_CTRL + KEY_PRESSED_OFFSET_W)
				{
					cnt++;
					if( cnt == 20)
					{
						pitch_angle = pitch_angle + 1;
						if(pitch_angle > gimbal_pitch_max_real_angle)
						pitch_angle = gimbal_pitch_max_real_angle;
						cnt=0;
					}
				}
				if( (rc_ctrl.mouse.y > 10 && rc_ctrl.key.v != KEY_PRESSED_OFFSET_CTRL) || rc_ctrl.key.v == KEY_PRESSED_OFFSET_CTRL + KEY_PRESSED_OFFSET_S)
				{
					cnt++;
					if( cnt == 20)
					{
						pitch_angle = pitch_angle - 1;
						if(pitch_angle < gimbal_pitch_min_real_angle)
							pitch_angle = gimbal_pitch_min_real_angle;
						cnt=0;
					}
				}
				Gimbal_Angle_control(pitch_angle_zero + pitch_angle);
			}
			else
				Gimbal_Angle_control(pitch_angle_zero);

			//ÏµÍ³ÑÓÊ±
      vTaskDelay(1);
			
#if INCLUDE_uxTaskGetStackHighWaterMark
        gimbal_task_stack = uxTaskGetStackHighWaterMark(NULL);
#endif
    }
}

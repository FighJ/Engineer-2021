#include "main.h"
#include "stm32f4xx.h"
#include "buzzer.h"
#include "delay.h"
#include "led.h"
#include "rc.h"
#include "pwm.h"
#include "rng.h"
#include "sys.h"
#include "timer.h"
#include "FreeRTOSConfig.h"
#include "FreeRTOS.h"
#include "task.h"
#include "remote_control.h"
#include "start_task.h"
#include "can.h"
#include "relay.h"
void BSP_init(void);

int main(void)
{
    BSP_init();
    delay_ms(200);
    startTast();
    vTaskStartScheduler();

    while (1)
    {

    }
}

void BSP_init(void)
{
    //中断组 4
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
    //初始化滴答时钟
    delay_init(configTICK_RATE_HZ);
    //LED初始化
    led_configuration();
	  //遥控器初始化
    remote_control_init();
		//云台舵机初始化
		Gimbal_PWM_Init();
		//CAN接口初始化
    CAN1_mode_init(CAN_SJW_1tq, CAN_BS2_2tq, CAN_BS1_6tq, 5, CAN_Mode_Normal);
    CAN2_mode_init(CAN_SJW_1tq, CAN_BS2_2tq, CAN_BS1_6tq, 5, CAN_Mode_Normal);
	  //GPIO初始化
		gpio_relays_init();
}

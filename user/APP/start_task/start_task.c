#include "Start_Task.h"
#include "FreeRTOSConfig.h"
#include "FreeRTOS.h"
#include "task.h"
#include "User_Task.h"
#include "gimbal_task.h"
#include "chassis_task.h"
#include "carry_task.h"

#define User_TASK_PRIO 4
#define User_STK_SIZE 256
static TaskHandle_t UserTask_Handler;

#define START_TASK_PRIO 1
#define START_STK_SIZE 512
static TaskHandle_t StartTask_Handler;

#define GIMBAL_TASK_PRIO 19
#define GIMBAL_STK_SIZE 512
TaskHandle_t GIMBALTask_Handler;

#define Chassis_TASK_PRIO 18
#define Chassis_STK_SIZE 512
TaskHandle_t ChassisTask_Handler;

#define Arm_TASK_PRIO 18
#define Arm_STK_SIZE 512
TaskHandle_t ArmTask_Handler;

#define Carry_TASK_PRIO 18
#define Carry_STK_SIZE 512
TaskHandle_t CarryTask_Handler;

void start_task(void *pvParameters)
{
    taskENTER_CRITICAL();

    xTaskCreate((TaskFunction_t)UserTask,
                (const char *)"UserTask",
                (uint16_t)User_STK_SIZE,
                (void *)NULL,
                (UBaseType_t)User_TASK_PRIO,
                (TaskHandle_t *)&UserTask_Handler);
		
		xTaskCreate((TaskFunction_t)GIMBAL_task,
						(const char *)"GIMBAL_task",
						(uint16_t)GIMBAL_STK_SIZE,
						(void *)NULL,
						(UBaseType_t)GIMBAL_TASK_PRIO,
						(TaskHandle_t *)&GIMBALTask_Handler);
						
		xTaskCreate((TaskFunction_t)chassis_task,
					(const char *)"ChassisTask",
					(uint16_t)Chassis_STK_SIZE,
					(void *)NULL,
					(UBaseType_t)Chassis_TASK_PRIO,
					(TaskHandle_t *)&ChassisTask_Handler);
					
		xTaskCreate((TaskFunction_t)arm_task,
					(const char *)"ArmTask",
					(uint16_t)Arm_STK_SIZE,
					(void *)NULL,
					(UBaseType_t)Arm_TASK_PRIO,
					(TaskHandle_t *)&ArmTask_Handler);
					
    xTaskCreate((TaskFunction_t)carry_task,
					(const char *)"CarryTask",
					(uint16_t)Carry_STK_SIZE,
					(void *)NULL,
					(UBaseType_t)Carry_TASK_PRIO,
					(TaskHandle_t *)&CarryTask_Handler);

    vTaskDelete(StartTask_Handler); //删除开始任务
    taskEXIT_CRITICAL();            //退出临界区
}

void startTast(void)
{
    xTaskCreate((TaskFunction_t)start_task,          //任务函数
                (const char *)"start_task",          //任务名称
                (uint16_t)START_STK_SIZE,            //任务堆栈大小
                (void *)NULL,                        //传递给任务函数的参数
                (UBaseType_t)START_TASK_PRIO,        //任务优先级
                (TaskHandle_t *)&StartTask_Handler); //任务句柄
}

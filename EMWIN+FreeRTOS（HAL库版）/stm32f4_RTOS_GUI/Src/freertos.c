/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */     
#include "lcd_config.h"
#include "GUI.h"
#include "touch.h"
#include "GUIDemo.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
extern _m_tp_dev tp_dev;
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
osThreadId LED_taskHandle;
uint32_t LED_taskBuffer[ 512 ];
osStaticThreadDef_t LED_taskControlBlock;
osThreadId LCD_TaskHandle;
uint32_t LCD_TaskBuffer[ 512 ];
osStaticThreadDef_t LCD_TaskControlBlock;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
   
/* USER CODE END FunctionPrototypes */

void Start_LED_Task(void const * argument);
void Start_LCD_Task(void const * argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* GetIdleTaskMemory prototype (linked to static allocation support) */
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize );

/* USER CODE BEGIN GET_IDLE_TASK_MEMORY */
static StaticTask_t xIdleTaskTCBBuffer;
static StackType_t xIdleStack[configMINIMAL_STACK_SIZE];
  
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize )
{
  *ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
  *ppxIdleTaskStackBuffer = &xIdleStack[0];
  *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
  /* place for user code */
}                   
/* USER CODE END GET_IDLE_TASK_MEMORY */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */
       
  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of LED_task */
  osThreadStaticDef(LED_task, Start_LED_Task, osPriorityNormal, 0, 512, LED_taskBuffer, &LED_taskControlBlock);
  LED_taskHandle = osThreadCreate(osThread(LED_task), NULL);

  /* definition and creation of LCD_Task */
  osThreadStaticDef(LCD_Task, Start_LCD_Task, osPriorityIdle, 0, 512, LCD_TaskBuffer, &LCD_TaskControlBlock);
  LCD_TaskHandle = osThreadCreate(osThread(LCD_Task), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_Start_LED_Task */
/**
  * @brief  Function implementing the LED_task thread.
  * @param  argument: Not used 
  * @retval None
  */
/* USER CODE END Header_Start_LED_Task */
void Start_LED_Task(void const * argument)
{  
  /* USER CODE BEGIN Start_LED_Task */
	MainTask();
  /* Infinite loop */
  for(;;)
  {
		GUI_Exec(); 
		osDelay(1);
  }
  /* USER CODE END Start_LED_Task */
}

/* USER CODE BEGIN Header_Start_LCD_Task */
/**
* @brief Function implementing the LCD_Task thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Start_LCD_Task */
void Start_LCD_Task(void const * argument)
{
  /* USER CODE BEGIN Start_LCD_Task */
  /* Infinite loop */
	//u32 x = 20, y = 20;
//	LCD_Clear(GREEN);//ÇåÆÁ
//	TP_Adjust();  //ÆÁÄ»Ð£×¼ 
//	TP_Save_Adjdata();
  for(;;)
  {
//		LCD_Fill(100,100,200,200,RED);
		//TP_Scan(1);
//		GUI_DispBinAt(tp_dev.sta,0,10,8);
//		GUI_DispDecAt(tp_dev.x[0],0,20,5);
//		GUI_DispDecAt(tp_dev.y[0],0,30,5);
//		CreateMyWin();
//		while(1){
//			GUI_Delay(1);
//		GUI_TOUCH_Exec();
//			osDelay(10);
//		}
		GUI_TOUCH_Exec();
		
		osDelay(5);
  }
  /* USER CODE END Start_LCD_Task */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */
     
/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

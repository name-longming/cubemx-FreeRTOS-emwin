#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "ILI93xx.h"
#include "led.h"
#include "sram.h"
#include "malloc.h"
#include "touch.h"
#include "GUI.h"
#include "timer.h"
#include "GUIDemo.h"
/************************************************
 ALIENTEK 探索者STM32F407开发板 
 STemWin STemWin移植实验
 技术支持：www.openedv.com
 淘宝店铺：http://eboard.taobao.com 
 关注微信公众平台微信号："正点原子"，免费获取STM32资料。
 广州市星翼电子科技有限公司  
 作者：正点原子 @ALIENTEK
************************************************/

int main(void)
{	
	delay_init(168);       	//延时初始化
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);  	//中断分组配置
	
	uart_init(115200);    	//串口波特率设置
	LED_Init(); 			//LED初始化
	TFTLCD_Init();  		//LCD初始化
	TP_Init();				//触摸屏初始化
	FSMC_SRAM_Init(); 		//SRAM初始化
	TIM3_Int_Init(999,83); 	//1KHZ 定时器3设置为1ms
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_CRC,ENABLE); //使能GPIOD的时钟
	mem_init(SRAMIN); 		//初始化内部内存池
//	mem_init(SRAMEX);  		//初始化外部内存池
	mem_init(SRAMCCM); 		//初始化CCM内存池
	
	TIM4_Int_Init(999,839);  //触摸屏扫描速度,100HZ.
	WM_SetCreateFlags(WM_CF_MEMDEV);
	GUI_Init();
	GUIDEMO_Main();
	
//	GUI_SetBkColor(GUI_BLUE);
//	GUI_Clear();
	while(1)
	{
	
	
	 GUI_Exec();  
	
	}
}

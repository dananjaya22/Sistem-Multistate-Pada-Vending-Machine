/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f4xx.h"
#include "stm32f4_discovery.h"
#include "device.h"
#include "sensor.h"
#include "hardwareinit.h"
#include "uart.h"
#include "seos.h"
#include "lcd_16x2.h"
#include "task.h"

			
int main(void)
{
	HAL_Init();
	SystemClock_Config();
	MX_GPIO_Init();
	MX_USART2_UART_Init();
	SCH_init(2);

	LCD1602_Begin4BIT(RS_GPIO_Port, RS_Pin, E_Pin, D4_GPIO_Port, D4_Pin, D5_Pin, D6_Pin, D7_Pin);

	while(1){
		/* User code here      -----------------------------------------------*/
		//		HAL_GPIO_TogglePin(led0_GPIO_Port,led0_Pin);
		//		HAL_Delay(1000);
		/* User code here      -----------------------------------------------*/


	}
}


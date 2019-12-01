/*
 * task.c
 *
 *  Created on: nov 24, 2019
 *      Author: dananjaya22
 */
#include "task.h"
#include "stm32f4xx.h"
#include "device.h"
#include "uart.h"
#include "sensor.h"
#include "task.h"




//Private constant-----------------------
#define LAMA_MERAH	500
#define LAMA_KUNING	1000
#define LAMA_HIJAU	200
#define LAMA_MERAH_KUNING	3

#define MerahON   HAL_GPIO_WritePin(led0_GPIO_Port,led0_Pin,GPIO_PIN_SET)
#define MerahOFF  HAL_GPIO_WritePin(led0_GPIO_Port,led0_Pin,GPIO_PIN_RESET)

#define KuningON  HAL_GPIO_WritePin(led1_GPIO_Port,led1_Pin,GPIO_PIN_SET)
#define KuningOFF HAL_GPIO_WritePin(led1_GPIO_Port,led1_Pin,GPIO_PIN_RESET)

#define HijauON	   HAL_GPIO_WritePin(led2_GPIO_Port,led2_Pin,GPIO_PIN_SET)
#define HijauOFF  HAL_GPIO_WritePin(led2_GPIO_Port,led2_Pin,GPIO_PIN_RESET)

#define BiruON 	  HAL_GPIO_WritePin(led3_GPIO_Port,led3_Pin,GPIO_PIN_SET)
#define BiruOFF   HAL_GPIO_WritePin(led3_GPIO_Port,led3_Pin,GPIO_PIN_RESET)

#define CoklatON 	HAL_GPIO_WritePin(led4_GPIO_Port,led4_Pin,GPIO_PIN_SET)
#define CoklatOFF   HAL_GPIO_WritePin(led4_GPIO_Port,led4_Pin,GPIO_PIN_RESET)


//Private variable-----------------------
//enum state {merah, kuning, hijau, merah_kuning } stateku;
enum state {mulai,stawal,st500, st1000, st500kembali, st1000kembali, stakhir} stateku;
unsigned int Time_in_state=0, c500=0, c1000=0, BTN=0, proses=0, batal=0;

/* -------------------------------------- *
	Traffic_Light_Init()
	Set kondisi pertama ke merah
-* -------------------------------------- */

void Task_Init(void){
	stateku=mulai;
}

void Task_Run(void){
	/*if(Detected500()){
	 	c500 = 1;
	}
	if (Detected1000()){
		c1000=1;
	}
	if (prosesDetected()){
		proses=1;
	}
	if (batalDetected()){
		batal=1;
	}*/

	//	USARTPutStr("."); //current state
	switch(stateku)
	{
	case mulai:
	{
		printf("******EEPIS VENDING MACHINE****** \n\r");
		printf("**********MASUKKAN UANG*********** \n\r");
		stateku=stawal;
		break;

	}
	case stawal:
	{

		MerahON;
		KuningON;
		HijauON;
		BiruON;
		CoklatON;
		//printf("Merah ON \n\r");
		//printf("Masukkan Uang \n\r");
		//print_UART2("masuk \n\r" ,8);
		//UART_Print("*******MASUKKAN UANG******* \n\r");
		if(Detected500()){
			UART_Print("Uang Anda Rp.500 \n\r");
			stateku=st500;

		}
		else if(Detected1000()){
			UART_Print("Uang Anda Rp.1000 \n\r");
			stateku=stakhir;


		}



		/*if (++Time_in_state==LAMA_MERAH)
		{
			if(BTN==0){
				stateku=merah_kuning;
			}
			else  {
				stateku=merah;
				BTN=0;
			}
			Time_in_state=0;
		}*/

		break;
	}

	case st500:
	{
		MerahOFF;
		KuningON;
		HijauON;
		BiruON;
		CoklatON;
		//printf("Merah_kuning ON \n\r");
		//printf("Rp.500 \n\r");
		//HAL_GPIO_WritePin(led2_GPIO_Port,led2_Pin,GPIO_PIN_SET);
		if(Detected500()){
			UART_Print("Uang Anda Rp.1000 \n\r");
			stateku=stakhir;

		}
		else if(Detected1000()){
			UART_Print("Uang Kembali Rp.500 \n\r");
			UART_Print("Uang Anda Rp.1000 \n\r");
			stateku=st500kembali;

		}

		if(batalDetected()){
			//printf("Uang Keluar \n\r");
			UART_Print("Uang Keluar \n\r");
			stateku=stawal;

		}
		/*if (++Time_in_state==LAMA_MERAH_KUNING)
		{
			if(BTN==0){
				stateku=hijau;
			}
			else {
				stateku=merah;
				BTN=0;
			}
			Time_in_state=0;

		}*/
		break;
	}

	case st1000:
	{

		MerahON;
		KuningON;
		HijauOFF;
		BiruON;
		CoklatON;
		if(++Time_in_state==LAMA_KUNING){
		//printf("Rp.1000 \n\r");
		stateku=stawal;
		Time_in_state=0;
		}
		//printf("Kuning ON \n\r");

		//HAL_GPIO_WritePin(led1_GPIO_Port,led1_Pin,GPIO_PIN_SET);
		/*if(Detected500()){
			stateku=st500kembali;

		}
		else if(Detected1000()){
			stateku=st500kembali;

		}

		if(batalDetected()){
			printf("Uang Keluar \n\r");
			stateku=stawal;

		}*/
		/*if (++Time_in_state==LAMA_KUNING)
		 	{
			if(BTN==0){


				stateku=merah;
			}
			else{
				stateku=merah;
				BTN=0;
			}
			Time_in_state=0;
		}*/

		break;
	}

	case stakhir:
	{
		MerahON;
		KuningOFF;
		HijauON;
		BiruON;
		CoklatON;

		if(Detected500()){
			UART_Print("Uang Kembali Rp.500 \n\r");
			UART_Print("Uang Anda Rp.1000 \n\r");
			stateku=st500kembali;
		}
		else if(Detected1000()){
			UART_Print("Uang Kembali Rp.1000 \n\r");
			UART_Print("Uang Anda Rp.1000 \n\r");
			stateku=st1000kembali;
		}

		if(batalDetected()){
			UART_Print("Uang Keluar \n\r");
			stateku=stawal;
		}
		//printf("Hijau ON \n\r");
		//HAL_GPIO_WritePin(led2_GPIO_Port,led2_Pin,GPIO_PIN_SET);
		if(prosesDetected()){
			UART_Print("Permen Keluar \n\r");
			stateku=st1000;

		}

		/*if (++Time_in_state==LAMA_HIJAU)
		{
			if(BTN==0){
				stateku=kuning;
			}
			else {
				stateku=merah;
				BTN=0;
			}
			Time_in_state=0;
		}*/

		break;
	}

	case st500kembali:
	{
		//HAL_GPIO_WritePin(led3_GPIO_Port,led3_Pin,GPIO_PIN_SET);
		MerahON;
		KuningON;
		HijauON;
		BiruOFF;
		CoklatON;
		//printf("kembali Rp.500 \n\r");
		if(++Time_in_state==LAMA_MERAH){
			//printf("Rp.1000 \n\r");
			stateku=stakhir;
				Time_in_state=0;
			}


		break;
	}
	case st1000kembali:
	{
		MerahON;
		KuningON;
		HijauON;
		BiruON;
		CoklatOFF;
		//printf("kembali Rp.1000 \n\r");
		if(++Time_in_state==LAMA_MERAH){
			//printf("Rp.1000 \n\r");
			stateku=stakhir;
			Time_in_state=0;
		}


		break;
	}

	}

}


/*
 * sensor.c
 *
 *  Created on: Nov 24, 2019
 *      Author: dananjaya22
 */
#include "sensor.h"
#include "stm32f4xx.h"
#include "device.h"
#include "stdint.h"


uint8_t prosesDetected(void){
	static unsigned char debounce=0xFF;
	unsigned char detectedFLag=0;
	if(HAL_GPIO_ReadPin(pbLeft_GPIO_Port,pbLeft_Pin)== GPIO_PIN_RESET){
		debounce=(debounce<<1);
	} else {
		debounce= (debounce<<1)|1;
	}
	if (debounce==0x03) {
		detectedFLag=1;
	}
	return detectedFLag;
}

uint8_t batalDetected(void){
	static unsigned char debounce=0xFF;
	unsigned char detectedFLag=0;
	if(HAL_GPIO_ReadPin(pbUp_GPIO_Port,pbUp_Pin)== GPIO_PIN_RESET){
		debounce=(debounce<<1);
	} else {
		debounce= (debounce<<1)|1;
	}
	if (debounce==0x03) {
		detectedFLag=1;
	}
	return detectedFLag;
}

uint8_t Detected500(void){
	static unsigned char debounce=0xFF;
		unsigned char detectedFLag=0;
		if(HAL_GPIO_ReadPin(pbDown_GPIO_Port,pbDown_Pin)== GPIO_PIN_RESET){
			debounce=(debounce<<1);
		} else {
			debounce= (debounce<<1)|1;
		}
		if (debounce==0x03) {
			detectedFLag=1;
		}
		return detectedFLag;
}

uint8_t Detected1000(void){
	static unsigned char debounce=0xFF;
		unsigned char detectedFLag=0;
		if(HAL_GPIO_ReadPin(pbRight_GPIO_Port,pbRight_Pin)== GPIO_PIN_RESET){
			debounce=(debounce<<1);
		} else {
			debounce= (debounce<<1)|1;
		}
		if (debounce==0x03) {
			detectedFLag=1;
		}
		return detectedFLag;
}


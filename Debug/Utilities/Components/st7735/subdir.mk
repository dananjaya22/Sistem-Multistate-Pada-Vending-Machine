################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Utilities/Components/st7735/st7735.c 

OBJS += \
./Utilities/Components/st7735/st7735.o 

C_DEPS += \
./Utilities/Components/st7735/st7735.d 


# Each subdirectory must supply rules for building sources it contributes
Utilities/Components/st7735/st7735.o: ../Utilities/Components/st7735/st7735.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F407VGTx -DSTM32F4 -DSTM32F4DISCOVERY -DSTM32 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I"E:/Prak_Sistem_Embeded/state_vending_machine/inc" -I"E:/Prak_Sistem_Embeded/state_vending_machine/HAL_Driver/Inc" -I"E:/Prak_Sistem_Embeded/state_vending_machine/HAL_Driver/Inc/Legacy" -I"E:/Prak_Sistem_Embeded/state_vending_machine/Utilities/Components/wm8994" -I"E:/Prak_Sistem_Embeded/state_vending_machine/Utilities/Components/n25q256a" -I"E:/Prak_Sistem_Embeded/state_vending_machine/Utilities/Components/exc7200" -I"E:/Prak_Sistem_Embeded/state_vending_machine/Utilities/Components/stmpe811" -I"E:/Prak_Sistem_Embeded/state_vending_machine/Utilities/Components/ov2640" -I"E:/Prak_Sistem_Embeded/state_vending_machine/Utilities/Components/Common" -I"E:/Prak_Sistem_Embeded/state_vending_machine/Utilities/Components/ampire480272" -I"E:/Prak_Sistem_Embeded/state_vending_machine/Utilities/Components/ls016b8uy" -I"E:/Prak_Sistem_Embeded/state_vending_machine/Utilities/Components/s5k5cag" -I"E:/Prak_Sistem_Embeded/state_vending_machine/Utilities/Components/s25fl512s" -I"E:/Prak_Sistem_Embeded/state_vending_machine/Utilities/Components/cs43l22" -I"E:/Prak_Sistem_Embeded/state_vending_machine/Utilities/Components/ampire640480" -I"E:/Prak_Sistem_Embeded/state_vending_machine/Utilities/Components/ili9341" -I"E:/Prak_Sistem_Embeded/state_vending_machine/Utilities/Components/stmpe1600" -I"E:/Prak_Sistem_Embeded/state_vending_machine/Utilities/Components/st7789h2" -I"E:/Prak_Sistem_Embeded/state_vending_machine/Utilities/Components/lsm303dlhc" -I"E:/Prak_Sistem_Embeded/state_vending_machine/Utilities/Components/ili9325" -I"E:/Prak_Sistem_Embeded/state_vending_machine/Utilities/Components/ft6x06" -I"E:/Prak_Sistem_Embeded/state_vending_machine/Utilities/Components/lis302dl" -I"E:/Prak_Sistem_Embeded/state_vending_machine/Utilities/Components/l3gd20" -I"E:/Prak_Sistem_Embeded/state_vending_machine/Utilities/Components/mfxstm32l152" -I"E:/Prak_Sistem_Embeded/state_vending_machine/Utilities/Components/otm8009a" -I"E:/Prak_Sistem_Embeded/state_vending_machine/Utilities/Components/lis3dsh" -I"E:/Prak_Sistem_Embeded/state_vending_machine/Utilities/Components/st7735" -I"E:/Prak_Sistem_Embeded/state_vending_machine/Utilities/Components/n25q128a" -I"E:/Prak_Sistem_Embeded/state_vending_machine/Utilities/Components/n25q512a" -I"E:/Prak_Sistem_Embeded/state_vending_machine/Utilities/Components/ts3510" -I"E:/Prak_Sistem_Embeded/state_vending_machine/Utilities" -I"E:/Prak_Sistem_Embeded/state_vending_machine/Utilities/STM32F4-Discovery" -I"E:/Prak_Sistem_Embeded/state_vending_machine/CMSIS/core" -I"E:/Prak_Sistem_Embeded/state_vending_machine/CMSIS/device" -O0 -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Utilities/Components/st7735/st7735.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"


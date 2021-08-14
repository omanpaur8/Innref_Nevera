################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/Components/vl53l1x/platform/vl53l1_platform.c 

OBJS += \
./Drivers/BSP/Components/vl53l1x/platform/vl53l1_platform.o 

C_DEPS += \
./Drivers/BSP/Components/vl53l1x/platform/vl53l1_platform.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/Components/vl53l1x/platform/vl53l1_platform.o: ../Drivers/BSP/Components/vl53l1x/platform/vl53l1_platform.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DUSE_STM32L0XX_NUCLEO -DUSE_HAL_DRIVER -DSTM32L073xx -DDEBUG -c -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -I../Drivers/BSP/Components/Common -I../Drivers/BSP/Components/stspin220 -I../Drivers/BSP/Components/vl53l0x/Inc -I../Drivers/BSP/STM32L0xx_Nucleo -I../Drivers/BSP/X-NUCLEO-IHMxx -I../Core/Headers -I../Drivers/BSP/Components/vl53l1x/core -I../Drivers/BSP/Components/vl53l1x/platform -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/Components/vl53l1x/platform/vl53l1_platform.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"


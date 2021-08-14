################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/Components/vl53l0x/Src/vl53l0x_api.c \
../Drivers/BSP/Components/vl53l0x/Src/vl53l0x_api_calibration.c \
../Drivers/BSP/Components/vl53l0x/Src/vl53l0x_api_core.c \
../Drivers/BSP/Components/vl53l0x/Src/vl53l0x_api_ranging.c \
../Drivers/BSP/Components/vl53l0x/Src/vl53l0x_api_strings.c \
../Drivers/BSP/Components/vl53l0x/Src/vl53l0x_platform.c \
../Drivers/BSP/Components/vl53l0x/Src/vl53l0x_platform_log.c 

OBJS += \
./Drivers/BSP/Components/vl53l0x/Src/vl53l0x_api.o \
./Drivers/BSP/Components/vl53l0x/Src/vl53l0x_api_calibration.o \
./Drivers/BSP/Components/vl53l0x/Src/vl53l0x_api_core.o \
./Drivers/BSP/Components/vl53l0x/Src/vl53l0x_api_ranging.o \
./Drivers/BSP/Components/vl53l0x/Src/vl53l0x_api_strings.o \
./Drivers/BSP/Components/vl53l0x/Src/vl53l0x_platform.o \
./Drivers/BSP/Components/vl53l0x/Src/vl53l0x_platform_log.o 

C_DEPS += \
./Drivers/BSP/Components/vl53l0x/Src/vl53l0x_api.d \
./Drivers/BSP/Components/vl53l0x/Src/vl53l0x_api_calibration.d \
./Drivers/BSP/Components/vl53l0x/Src/vl53l0x_api_core.d \
./Drivers/BSP/Components/vl53l0x/Src/vl53l0x_api_ranging.d \
./Drivers/BSP/Components/vl53l0x/Src/vl53l0x_api_strings.d \
./Drivers/BSP/Components/vl53l0x/Src/vl53l0x_platform.d \
./Drivers/BSP/Components/vl53l0x/Src/vl53l0x_platform_log.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/Components/vl53l0x/Src/vl53l0x_api.o: ../Drivers/BSP/Components/vl53l0x/Src/vl53l0x_api.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DUSE_STM32L0XX_NUCLEO -DUSE_HAL_DRIVER -DSTM32L073xx -DDEBUG -c -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -I../Drivers/BSP/Components/Common -I../Drivers/BSP/Components/stspin220 -I../Drivers/BSP/Components/vl53l0x/Inc -I../Drivers/BSP/STM32L0xx_Nucleo -I../Drivers/BSP/X-NUCLEO-IHMxx -I../Core/Headers -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/Components/vl53l0x/Src/vl53l0x_api.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/BSP/Components/vl53l0x/Src/vl53l0x_api_calibration.o: ../Drivers/BSP/Components/vl53l0x/Src/vl53l0x_api_calibration.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DUSE_STM32L0XX_NUCLEO -DUSE_HAL_DRIVER -DSTM32L073xx -DDEBUG -c -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -I../Drivers/BSP/Components/Common -I../Drivers/BSP/Components/stspin220 -I../Drivers/BSP/Components/vl53l0x/Inc -I../Drivers/BSP/STM32L0xx_Nucleo -I../Drivers/BSP/X-NUCLEO-IHMxx -I../Core/Headers -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/Components/vl53l0x/Src/vl53l0x_api_calibration.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/BSP/Components/vl53l0x/Src/vl53l0x_api_core.o: ../Drivers/BSP/Components/vl53l0x/Src/vl53l0x_api_core.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DUSE_STM32L0XX_NUCLEO -DUSE_HAL_DRIVER -DSTM32L073xx -DDEBUG -c -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -I../Drivers/BSP/Components/Common -I../Drivers/BSP/Components/stspin220 -I../Drivers/BSP/Components/vl53l0x/Inc -I../Drivers/BSP/STM32L0xx_Nucleo -I../Drivers/BSP/X-NUCLEO-IHMxx -I../Core/Headers -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/Components/vl53l0x/Src/vl53l0x_api_core.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/BSP/Components/vl53l0x/Src/vl53l0x_api_ranging.o: ../Drivers/BSP/Components/vl53l0x/Src/vl53l0x_api_ranging.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DUSE_STM32L0XX_NUCLEO -DUSE_HAL_DRIVER -DSTM32L073xx -DDEBUG -c -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -I../Drivers/BSP/Components/Common -I../Drivers/BSP/Components/stspin220 -I../Drivers/BSP/Components/vl53l0x/Inc -I../Drivers/BSP/STM32L0xx_Nucleo -I../Drivers/BSP/X-NUCLEO-IHMxx -I../Core/Headers -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/Components/vl53l0x/Src/vl53l0x_api_ranging.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/BSP/Components/vl53l0x/Src/vl53l0x_api_strings.o: ../Drivers/BSP/Components/vl53l0x/Src/vl53l0x_api_strings.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DUSE_STM32L0XX_NUCLEO -DUSE_HAL_DRIVER -DSTM32L073xx -DDEBUG -c -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -I../Drivers/BSP/Components/Common -I../Drivers/BSP/Components/stspin220 -I../Drivers/BSP/Components/vl53l0x/Inc -I../Drivers/BSP/STM32L0xx_Nucleo -I../Drivers/BSP/X-NUCLEO-IHMxx -I../Core/Headers -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/Components/vl53l0x/Src/vl53l0x_api_strings.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/BSP/Components/vl53l0x/Src/vl53l0x_platform.o: ../Drivers/BSP/Components/vl53l0x/Src/vl53l0x_platform.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DUSE_STM32L0XX_NUCLEO -DUSE_HAL_DRIVER -DSTM32L073xx -DDEBUG -c -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -I../Drivers/BSP/Components/Common -I../Drivers/BSP/Components/stspin220 -I../Drivers/BSP/Components/vl53l0x/Inc -I../Drivers/BSP/STM32L0xx_Nucleo -I../Drivers/BSP/X-NUCLEO-IHMxx -I../Core/Headers -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/Components/vl53l0x/Src/vl53l0x_platform.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/BSP/Components/vl53l0x/Src/vl53l0x_platform_log.o: ../Drivers/BSP/Components/vl53l0x/Src/vl53l0x_platform_log.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DUSE_STM32L0XX_NUCLEO -DUSE_HAL_DRIVER -DSTM32L073xx -DDEBUG -c -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -I../Drivers/BSP/Components/Common -I../Drivers/BSP/Components/stspin220 -I../Drivers/BSP/Components/vl53l0x/Inc -I../Drivers/BSP/STM32L0xx_Nucleo -I../Drivers/BSP/X-NUCLEO-IHMxx -I../Core/Headers -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/Components/vl53l0x/Src/vl53l0x_platform_log.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"


################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/Components/vl53l1x/core/vl53l1_api.c \
../Drivers/BSP/Components/vl53l1x/core/vl53l1_api_calibration.c \
../Drivers/BSP/Components/vl53l1x/core/vl53l1_api_core.c \
../Drivers/BSP/Components/vl53l1x/core/vl53l1_api_debug.c \
../Drivers/BSP/Components/vl53l1x/core/vl53l1_api_preset_modes.c \
../Drivers/BSP/Components/vl53l1x/core/vl53l1_api_strings.c \
../Drivers/BSP/Components/vl53l1x/core/vl53l1_core.c \
../Drivers/BSP/Components/vl53l1x/core/vl53l1_core_support.c \
../Drivers/BSP/Components/vl53l1x/core/vl53l1_error_strings.c \
../Drivers/BSP/Components/vl53l1x/core/vl53l1_register_funcs.c \
../Drivers/BSP/Components/vl53l1x/core/vl53l1_silicon_core.c \
../Drivers/BSP/Components/vl53l1x/core/vl53l1_wait.c 

OBJS += \
./Drivers/BSP/Components/vl53l1x/core/vl53l1_api.o \
./Drivers/BSP/Components/vl53l1x/core/vl53l1_api_calibration.o \
./Drivers/BSP/Components/vl53l1x/core/vl53l1_api_core.o \
./Drivers/BSP/Components/vl53l1x/core/vl53l1_api_debug.o \
./Drivers/BSP/Components/vl53l1x/core/vl53l1_api_preset_modes.o \
./Drivers/BSP/Components/vl53l1x/core/vl53l1_api_strings.o \
./Drivers/BSP/Components/vl53l1x/core/vl53l1_core.o \
./Drivers/BSP/Components/vl53l1x/core/vl53l1_core_support.o \
./Drivers/BSP/Components/vl53l1x/core/vl53l1_error_strings.o \
./Drivers/BSP/Components/vl53l1x/core/vl53l1_register_funcs.o \
./Drivers/BSP/Components/vl53l1x/core/vl53l1_silicon_core.o \
./Drivers/BSP/Components/vl53l1x/core/vl53l1_wait.o 

C_DEPS += \
./Drivers/BSP/Components/vl53l1x/core/vl53l1_api.d \
./Drivers/BSP/Components/vl53l1x/core/vl53l1_api_calibration.d \
./Drivers/BSP/Components/vl53l1x/core/vl53l1_api_core.d \
./Drivers/BSP/Components/vl53l1x/core/vl53l1_api_debug.d \
./Drivers/BSP/Components/vl53l1x/core/vl53l1_api_preset_modes.d \
./Drivers/BSP/Components/vl53l1x/core/vl53l1_api_strings.d \
./Drivers/BSP/Components/vl53l1x/core/vl53l1_core.d \
./Drivers/BSP/Components/vl53l1x/core/vl53l1_core_support.d \
./Drivers/BSP/Components/vl53l1x/core/vl53l1_error_strings.d \
./Drivers/BSP/Components/vl53l1x/core/vl53l1_register_funcs.d \
./Drivers/BSP/Components/vl53l1x/core/vl53l1_silicon_core.d \
./Drivers/BSP/Components/vl53l1x/core/vl53l1_wait.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/Components/vl53l1x/core/vl53l1_api.o: ../Drivers/BSP/Components/vl53l1x/core/vl53l1_api.c Drivers/BSP/Components/vl53l1x/core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DUSE_STM32L0XX_NUCLEO -DUSE_HAL_DRIVER -DSTM32L073xx -DDEBUG -c -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -I../Drivers/BSP/Components/Common -I../Drivers/BSP/Components/stspin220 -I../Drivers/BSP/Components/vl53l0x/Inc -I../Drivers/BSP/STM32L0xx_Nucleo -I../Drivers/BSP/X-NUCLEO-IHMxx -I../Core/Headers -I../Drivers/BSP/Components/vl53l1x/core -I../Drivers/BSP/Components/vl53l1x/platform -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/Components/vl53l1x/core/vl53l1_api.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/BSP/Components/vl53l1x/core/vl53l1_api_calibration.o: ../Drivers/BSP/Components/vl53l1x/core/vl53l1_api_calibration.c Drivers/BSP/Components/vl53l1x/core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DUSE_STM32L0XX_NUCLEO -DUSE_HAL_DRIVER -DSTM32L073xx -DDEBUG -c -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -I../Drivers/BSP/Components/Common -I../Drivers/BSP/Components/stspin220 -I../Drivers/BSP/Components/vl53l0x/Inc -I../Drivers/BSP/STM32L0xx_Nucleo -I../Drivers/BSP/X-NUCLEO-IHMxx -I../Core/Headers -I../Drivers/BSP/Components/vl53l1x/core -I../Drivers/BSP/Components/vl53l1x/platform -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/Components/vl53l1x/core/vl53l1_api_calibration.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/BSP/Components/vl53l1x/core/vl53l1_api_core.o: ../Drivers/BSP/Components/vl53l1x/core/vl53l1_api_core.c Drivers/BSP/Components/vl53l1x/core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DUSE_STM32L0XX_NUCLEO -DUSE_HAL_DRIVER -DSTM32L073xx -DDEBUG -c -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -I../Drivers/BSP/Components/Common -I../Drivers/BSP/Components/stspin220 -I../Drivers/BSP/Components/vl53l0x/Inc -I../Drivers/BSP/STM32L0xx_Nucleo -I../Drivers/BSP/X-NUCLEO-IHMxx -I../Core/Headers -I../Drivers/BSP/Components/vl53l1x/core -I../Drivers/BSP/Components/vl53l1x/platform -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/Components/vl53l1x/core/vl53l1_api_core.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/BSP/Components/vl53l1x/core/vl53l1_api_debug.o: ../Drivers/BSP/Components/vl53l1x/core/vl53l1_api_debug.c Drivers/BSP/Components/vl53l1x/core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DUSE_STM32L0XX_NUCLEO -DUSE_HAL_DRIVER -DSTM32L073xx -DDEBUG -c -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -I../Drivers/BSP/Components/Common -I../Drivers/BSP/Components/stspin220 -I../Drivers/BSP/Components/vl53l0x/Inc -I../Drivers/BSP/STM32L0xx_Nucleo -I../Drivers/BSP/X-NUCLEO-IHMxx -I../Core/Headers -I../Drivers/BSP/Components/vl53l1x/core -I../Drivers/BSP/Components/vl53l1x/platform -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/Components/vl53l1x/core/vl53l1_api_debug.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/BSP/Components/vl53l1x/core/vl53l1_api_preset_modes.o: ../Drivers/BSP/Components/vl53l1x/core/vl53l1_api_preset_modes.c Drivers/BSP/Components/vl53l1x/core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DUSE_STM32L0XX_NUCLEO -DUSE_HAL_DRIVER -DSTM32L073xx -DDEBUG -c -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -I../Drivers/BSP/Components/Common -I../Drivers/BSP/Components/stspin220 -I../Drivers/BSP/Components/vl53l0x/Inc -I../Drivers/BSP/STM32L0xx_Nucleo -I../Drivers/BSP/X-NUCLEO-IHMxx -I../Core/Headers -I../Drivers/BSP/Components/vl53l1x/core -I../Drivers/BSP/Components/vl53l1x/platform -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/Components/vl53l1x/core/vl53l1_api_preset_modes.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/BSP/Components/vl53l1x/core/vl53l1_api_strings.o: ../Drivers/BSP/Components/vl53l1x/core/vl53l1_api_strings.c Drivers/BSP/Components/vl53l1x/core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DUSE_STM32L0XX_NUCLEO -DUSE_HAL_DRIVER -DSTM32L073xx -DDEBUG -c -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -I../Drivers/BSP/Components/Common -I../Drivers/BSP/Components/stspin220 -I../Drivers/BSP/Components/vl53l0x/Inc -I../Drivers/BSP/STM32L0xx_Nucleo -I../Drivers/BSP/X-NUCLEO-IHMxx -I../Core/Headers -I../Drivers/BSP/Components/vl53l1x/core -I../Drivers/BSP/Components/vl53l1x/platform -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/Components/vl53l1x/core/vl53l1_api_strings.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/BSP/Components/vl53l1x/core/vl53l1_core.o: ../Drivers/BSP/Components/vl53l1x/core/vl53l1_core.c Drivers/BSP/Components/vl53l1x/core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DUSE_STM32L0XX_NUCLEO -DUSE_HAL_DRIVER -DSTM32L073xx -DDEBUG -c -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -I../Drivers/BSP/Components/Common -I../Drivers/BSP/Components/stspin220 -I../Drivers/BSP/Components/vl53l0x/Inc -I../Drivers/BSP/STM32L0xx_Nucleo -I../Drivers/BSP/X-NUCLEO-IHMxx -I../Core/Headers -I../Drivers/BSP/Components/vl53l1x/core -I../Drivers/BSP/Components/vl53l1x/platform -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/Components/vl53l1x/core/vl53l1_core.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/BSP/Components/vl53l1x/core/vl53l1_core_support.o: ../Drivers/BSP/Components/vl53l1x/core/vl53l1_core_support.c Drivers/BSP/Components/vl53l1x/core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DUSE_STM32L0XX_NUCLEO -DUSE_HAL_DRIVER -DSTM32L073xx -DDEBUG -c -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -I../Drivers/BSP/Components/Common -I../Drivers/BSP/Components/stspin220 -I../Drivers/BSP/Components/vl53l0x/Inc -I../Drivers/BSP/STM32L0xx_Nucleo -I../Drivers/BSP/X-NUCLEO-IHMxx -I../Core/Headers -I../Drivers/BSP/Components/vl53l1x/core -I../Drivers/BSP/Components/vl53l1x/platform -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/Components/vl53l1x/core/vl53l1_core_support.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/BSP/Components/vl53l1x/core/vl53l1_error_strings.o: ../Drivers/BSP/Components/vl53l1x/core/vl53l1_error_strings.c Drivers/BSP/Components/vl53l1x/core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DUSE_STM32L0XX_NUCLEO -DUSE_HAL_DRIVER -DSTM32L073xx -DDEBUG -c -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -I../Drivers/BSP/Components/Common -I../Drivers/BSP/Components/stspin220 -I../Drivers/BSP/Components/vl53l0x/Inc -I../Drivers/BSP/STM32L0xx_Nucleo -I../Drivers/BSP/X-NUCLEO-IHMxx -I../Core/Headers -I../Drivers/BSP/Components/vl53l1x/core -I../Drivers/BSP/Components/vl53l1x/platform -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/Components/vl53l1x/core/vl53l1_error_strings.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/BSP/Components/vl53l1x/core/vl53l1_register_funcs.o: ../Drivers/BSP/Components/vl53l1x/core/vl53l1_register_funcs.c Drivers/BSP/Components/vl53l1x/core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DUSE_STM32L0XX_NUCLEO -DUSE_HAL_DRIVER -DSTM32L073xx -DDEBUG -c -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -I../Drivers/BSP/Components/Common -I../Drivers/BSP/Components/stspin220 -I../Drivers/BSP/Components/vl53l0x/Inc -I../Drivers/BSP/STM32L0xx_Nucleo -I../Drivers/BSP/X-NUCLEO-IHMxx -I../Core/Headers -I../Drivers/BSP/Components/vl53l1x/core -I../Drivers/BSP/Components/vl53l1x/platform -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/Components/vl53l1x/core/vl53l1_register_funcs.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/BSP/Components/vl53l1x/core/vl53l1_silicon_core.o: ../Drivers/BSP/Components/vl53l1x/core/vl53l1_silicon_core.c Drivers/BSP/Components/vl53l1x/core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DUSE_STM32L0XX_NUCLEO -DUSE_HAL_DRIVER -DSTM32L073xx -DDEBUG -c -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -I../Drivers/BSP/Components/Common -I../Drivers/BSP/Components/stspin220 -I../Drivers/BSP/Components/vl53l0x/Inc -I../Drivers/BSP/STM32L0xx_Nucleo -I../Drivers/BSP/X-NUCLEO-IHMxx -I../Core/Headers -I../Drivers/BSP/Components/vl53l1x/core -I../Drivers/BSP/Components/vl53l1x/platform -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/Components/vl53l1x/core/vl53l1_silicon_core.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/BSP/Components/vl53l1x/core/vl53l1_wait.o: ../Drivers/BSP/Components/vl53l1x/core/vl53l1_wait.c Drivers/BSP/Components/vl53l1x/core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DUSE_STM32L0XX_NUCLEO -DUSE_HAL_DRIVER -DSTM32L073xx -DDEBUG -c -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -I../Drivers/BSP/Components/Common -I../Drivers/BSP/Components/stspin220 -I../Drivers/BSP/Components/vl53l0x/Inc -I../Drivers/BSP/STM32L0xx_Nucleo -I../Drivers/BSP/X-NUCLEO-IHMxx -I../Core/Headers -I../Drivers/BSP/Components/vl53l1x/core -I../Drivers/BSP/Components/vl53l1x/platform -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/Components/vl53l1x/core/vl53l1_wait.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"


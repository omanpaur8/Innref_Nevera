################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32L0xx_HAL_Driver/Src/subdir.mk
-include Drivers/BSP/X-NUCLEO-IHMxx/subdir.mk
-include Drivers/BSP/STM32L0xx_Nucleo/subdir.mk
-include Drivers/BSP/Components/vl53l1x/platform/subdir.mk
-include Drivers/BSP/Components/vl53l1x/core/subdir.mk
-include Drivers/BSP/Components/stspin220/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include Core/Sources/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Inventario_V2.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Inventario_V2.list \

OBJCOPY_BIN += \
Inventario_V2.bin \


# All Target
all: Inventario_V2.elf secondary-outputs

# Tool invocations
Inventario_V2.elf: $(OBJS) $(USER_OBJS) C:\Users\Omar\STM32CubeIDE\Nevera_2\Inventario_V2\STM32L073RZTX_FLASH.ld
	arm-none-eabi-gcc -o "Inventario_V2.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m0plus -T"C:\Users\Omar\STM32CubeIDE\Nevera_2\Inventario_V2\STM32L073RZTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Inventario_V2.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -u _printf_float -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Inventario_V2.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Inventario_V2.list"
	@echo 'Finished building: $@'
	@echo ' '

Inventario_V2.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "Inventario_V2.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

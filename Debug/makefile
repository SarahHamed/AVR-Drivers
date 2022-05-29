################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/WDT/subdir.mk
-include MCAL/UART/subdir.mk
-include MCAL/Timer0/subdir.mk
-include MCAL/Global_Interrupt/subdir.mk
-include MCAL/External_Interrupt/subdir.mk
-include MCAL/ADC/subdir.mk
-include MCAL/01-DIO/subdir.mk
-include APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
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
LSS += \
07_UART.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: 07_UART.elf secondary-outputs

# Tool invocations
07_UART.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,07_UART.map -mmcu=atmega32 -o "07_UART.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

07_UART.lss: 07_UART.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S 07_UART.elf  >"07_UART.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: 07_UART.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 07_UART.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) 07_UART.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

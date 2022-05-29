################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/Global_Interrupt/GIE_prog.c 

OBJS += \
./MCAL/Global_Interrupt/GIE_prog.o 

C_DEPS += \
./MCAL/Global_Interrupt/GIE_prog.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/Global_Interrupt/%.o: ../MCAL/Global_Interrupt/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



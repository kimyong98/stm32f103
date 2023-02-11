################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../kernel/Src/sched.c \
../kernel/Src/task.c 

OBJS += \
./kernel/Src/sched.o \
./kernel/Src/task.o 

C_DEPS += \
./kernel/Src/sched.d \
./kernel/Src/task.d 


# Each subdirectory must supply rules for building sources it contributes
kernel/Src/%.o kernel/Src/%.su: ../kernel/Src/%.c kernel/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32F103RBTx -DSTM32 -DSTM32F1 -DNUCLEO_F103RB -c -I../Inc -I"C:/Users/injog/Desktop/MCU1/MCU1/kernel/Inc" -I"C:/Users/injog/Desktop/MCU1/MCU1/driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-kernel-2f-Src

clean-kernel-2f-Src:
	-$(RM) ./kernel/Src/sched.d ./kernel/Src/sched.o ./kernel/Src/sched.su ./kernel/Src/task.d ./kernel/Src/task.o ./kernel/Src/task.su

.PHONY: clean-kernel-2f-Src


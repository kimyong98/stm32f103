################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../driver/Src/driver_gpio.c \
../driver/Src/driver_i2c.c \
../driver/Src/driver_interrupt.c \
../driver/Src/driver_leg.c \
../driver/Src/driver_rcc.c \
../driver/Src/driver_spi.c \
../driver/Src/driver_timer.c \
../driver/Src/driver_usart.c 

OBJS += \
./driver/Src/driver_gpio.o \
./driver/Src/driver_i2c.o \
./driver/Src/driver_interrupt.o \
./driver/Src/driver_leg.o \
./driver/Src/driver_rcc.o \
./driver/Src/driver_spi.o \
./driver/Src/driver_timer.o \
./driver/Src/driver_usart.o 

C_DEPS += \
./driver/Src/driver_gpio.d \
./driver/Src/driver_i2c.d \
./driver/Src/driver_interrupt.d \
./driver/Src/driver_leg.d \
./driver/Src/driver_rcc.d \
./driver/Src/driver_spi.d \
./driver/Src/driver_timer.d \
./driver/Src/driver_usart.d 


# Each subdirectory must supply rules for building sources it contributes
driver/Src/%.o driver/Src/%.su: ../driver/Src/%.c driver/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32F103RBTx -DSTM32 -DSTM32F1 -DNUCLEO_F103RB -c -I../Inc -I"C:/Users/injog/Desktop/MCU1/MCU1/kernel/Inc" -I"C:/Users/injog/Desktop/MCU1/MCU1/driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-driver-2f-Src

clean-driver-2f-Src:
	-$(RM) ./driver/Src/driver_gpio.d ./driver/Src/driver_gpio.o ./driver/Src/driver_gpio.su ./driver/Src/driver_i2c.d ./driver/Src/driver_i2c.o ./driver/Src/driver_i2c.su ./driver/Src/driver_interrupt.d ./driver/Src/driver_interrupt.o ./driver/Src/driver_interrupt.su ./driver/Src/driver_leg.d ./driver/Src/driver_leg.o ./driver/Src/driver_leg.su ./driver/Src/driver_rcc.d ./driver/Src/driver_rcc.o ./driver/Src/driver_rcc.su ./driver/Src/driver_spi.d ./driver/Src/driver_spi.o ./driver/Src/driver_spi.su ./driver/Src/driver_timer.d ./driver/Src/driver_timer.o ./driver/Src/driver_timer.su ./driver/Src/driver_usart.d ./driver/Src/driver_usart.o ./driver/Src/driver_usart.su

.PHONY: clean-driver-2f-Src


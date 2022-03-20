################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Inc/nRF24L01/nRF24L01.c 

OBJS += \
./Inc/nRF24L01/nRF24L01.o 

C_DEPS += \
./Inc/nRF24L01/nRF24L01.d 


# Each subdirectory must supply rules for building sources it contributes
Inc/nRF24L01/%.o: ../Inc/nRF24L01/%.c Inc/nRF24L01/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F411CEUx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Inc-2f-nRF24L01

clean-Inc-2f-nRF24L01:
	-$(RM) ./Inc/nRF24L01/nRF24L01.d ./Inc/nRF24L01/nRF24L01.o

.PHONY: clean-Inc-2f-nRF24L01


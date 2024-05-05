################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/SENSOR/LM35.c \
../Core/SENSOR/LM393.c \
../Core/SENSOR/SENSOR.c 

OBJS += \
./Core/SENSOR/LM35.o \
./Core/SENSOR/LM393.o \
./Core/SENSOR/SENSOR.o 

C_DEPS += \
./Core/SENSOR/LM35.d \
./Core/SENSOR/LM393.d \
./Core/SENSOR/SENSOR.d 


# Each subdirectory must supply rules for building sources it contributes
Core/SENSOR/%.o Core/SENSOR/%.su Core/SENSOR/%.cyclo: ../Core/SENSOR/%.c Core/SENSOR/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"D:/project-stm32/BTL_LTN_L01_04/Core/LCD" -I"D:/project-stm32/BTL_LTN_L01_04/Core/SENSOR" -I"D:/project-stm32/BTL_LTN_L01_04/Core/ESP8266" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-SENSOR

clean-Core-2f-SENSOR:
	-$(RM) ./Core/SENSOR/LM35.cyclo ./Core/SENSOR/LM35.d ./Core/SENSOR/LM35.o ./Core/SENSOR/LM35.su ./Core/SENSOR/LM393.cyclo ./Core/SENSOR/LM393.d ./Core/SENSOR/LM393.o ./Core/SENSOR/LM393.su ./Core/SENSOR/SENSOR.cyclo ./Core/SENSOR/SENSOR.d ./Core/SENSOR/SENSOR.o ./Core/SENSOR/SENSOR.su

.PHONY: clean-Core-2f-SENSOR


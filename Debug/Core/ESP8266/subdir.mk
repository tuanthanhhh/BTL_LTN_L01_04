################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/ESP8266/ESP8266.c 

OBJS += \
./Core/ESP8266/ESP8266.o 

C_DEPS += \
./Core/ESP8266/ESP8266.d 


# Each subdirectory must supply rules for building sources it contributes
Core/ESP8266/%.o Core/ESP8266/%.su Core/ESP8266/%.cyclo: ../Core/ESP8266/%.c Core/ESP8266/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/LE TUAN THANH/STM32CubeIDE/workspace_1.13.1/BTL_LTN_L01_04/Core/LCD" -I"C:/Users/LE TUAN THANH/STM32CubeIDE/workspace_1.13.1/BTL_LTN_L01_04/Core/SENSOR" -I"C:/Users/LE TUAN THANH/STM32CubeIDE/workspace_1.13.1/BTL_LTN_L01_04/Core/ESP8266" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-ESP8266

clean-Core-2f-ESP8266:
	-$(RM) ./Core/ESP8266/ESP8266.cyclo ./Core/ESP8266/ESP8266.d ./Core/ESP8266/ESP8266.o ./Core/ESP8266/ESP8266.su

.PHONY: clean-Core-2f-ESP8266


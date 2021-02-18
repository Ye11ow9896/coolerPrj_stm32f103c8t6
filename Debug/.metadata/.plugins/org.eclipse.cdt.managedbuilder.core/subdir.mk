################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../.metadata/.plugins/org.eclipse.cdt.managedbuilder.core/spec.c 

OBJS += \
./.metadata/.plugins/org.eclipse.cdt.managedbuilder.core/spec.o 

C_DEPS += \
./.metadata/.plugins/org.eclipse.cdt.managedbuilder.core/spec.d 


# Each subdirectory must supply rules for building sources it contributes
.metadata/.plugins/org.eclipse.cdt.managedbuilder.core/spec.o: ../.metadata/.plugins/org.eclipse.cdt.managedbuilder.core/spec.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"D:/Programming/Cube/coolerPrj_stm32f103c8t6/CMSIS" -I"D:/Programming/Cube/coolerPrj_stm32f103c8t6/CMSIS/inc" -I"D:/Programming/Cube/coolerPrj_stm32f103c8t6/Code/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF".metadata/.plugins/org.eclipse.cdt.managedbuilder.core/spec.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"


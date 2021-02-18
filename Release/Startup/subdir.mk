################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Startup/startup_stm32f103x6.s 

OBJS += \
./Startup/startup_stm32f103x6.o 

S_DEPS += \
./Startup/startup_stm32f103x6.d 


# Each subdirectory must supply rules for building sources it contributes
Startup/startup_stm32f103x6.o: ../Startup/startup_stm32f103x6.s
	arm-none-eabi-gcc -mcpu=cortex-m3 -c -x assembler-with-cpp -MMD -MP -MF"Startup/startup_stm32f103x6.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@" "$<"


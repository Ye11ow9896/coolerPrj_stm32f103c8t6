################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Code/src/adc.c \
../Code/src/main.c \
../Code/src/pidRegulator.c \
../Code/src/pwm.c \
../Code/src/sysInit.c \
../Code/src/usart.c 

OBJS += \
./Code/src/adc.o \
./Code/src/main.o \
./Code/src/pidRegulator.o \
./Code/src/pwm.o \
./Code/src/sysInit.o \
./Code/src/usart.o 

C_DEPS += \
./Code/src/adc.d \
./Code/src/main.d \
./Code/src/pidRegulator.d \
./Code/src/pwm.d \
./Code/src/sysInit.d \
./Code/src/usart.d 


# Each subdirectory must supply rules for building sources it contributes
Code/src/adc.o: ../Code/src/adc.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"D:/Programming/Cube/coolerPrj_stm32f103c8t6/CMSIS" -I"D:/Programming/Cube/coolerPrj_stm32f103c8t6/CMSIS/inc" -I"D:/Programming/Cube/coolerPrj_stm32f103c8t6/Code/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Code/src/adc.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Code/src/main.o: ../Code/src/main.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"D:/Programming/Cube/coolerPrj_stm32f103c8t6/CMSIS" -I"D:/Programming/Cube/coolerPrj_stm32f103c8t6/CMSIS/inc" -I"D:/Programming/Cube/coolerPrj_stm32f103c8t6/Code/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Code/src/main.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Code/src/pidRegulator.o: ../Code/src/pidRegulator.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"D:/Programming/Cube/coolerPrj_stm32f103c8t6/CMSIS" -I"D:/Programming/Cube/coolerPrj_stm32f103c8t6/CMSIS/inc" -I"D:/Programming/Cube/coolerPrj_stm32f103c8t6/Code/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Code/src/pidRegulator.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Code/src/pwm.o: ../Code/src/pwm.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"D:/Programming/Cube/coolerPrj_stm32f103c8t6/CMSIS" -I"D:/Programming/Cube/coolerPrj_stm32f103c8t6/CMSIS/inc" -I"D:/Programming/Cube/coolerPrj_stm32f103c8t6/Code/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Code/src/pwm.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Code/src/sysInit.o: ../Code/src/sysInit.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"D:/Programming/Cube/coolerPrj_stm32f103c8t6/CMSIS" -I"D:/Programming/Cube/coolerPrj_stm32f103c8t6/CMSIS/inc" -I"D:/Programming/Cube/coolerPrj_stm32f103c8t6/Code/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Code/src/sysInit.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Code/src/usart.o: ../Code/src/usart.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"D:/Programming/Cube/coolerPrj_stm32f103c8t6/CMSIS" -I"D:/Programming/Cube/coolerPrj_stm32f103c8t6/CMSIS/inc" -I"D:/Programming/Cube/coolerPrj_stm32f103c8t6/Code/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Code/src/usart.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"


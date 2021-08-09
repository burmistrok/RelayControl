################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/gpio.c \
../Core/Src/main.c \
../Core/Src/stm32l0xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32l0xx.c \
../Core/Src/usart.c 

OBJS += \
./Core/Src/gpio.o \
./Core/Src/main.o \
./Core/Src/stm32l0xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32l0xx.o \
./Core/Src/usart.o 

C_DEPS += \
./Core/Src/gpio.d \
./Core/Src/main.d \
./Core/Src/stm32l0xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32l0xx.d \
./Core/Src/usart.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DSTM32L011xx -DUSE_FULL_LL_DRIVER -DHSE_VALUE=8000000 -DHSE_STARTUP_TIMEOUT=100 -DLSE_STARTUP_TIMEOUT=5000 -DLSE_VALUE=32768 -DMSI_VALUE=2097000 -DHSI_VALUE=16000000 -DLSI_VALUE=37000 -DVDD_VALUE=3300 -DPREFETCH_ENABLE=0 -DINSTRUCTION_CACHE_ENABLE=1 -DDATA_CACHE_ENABLE=1 -c -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -I"D:/repositoriu/RelayControl/Software/EmbeddedSoft/RelayControl/Source/Utils/CircularFIFOBuffer" -I"D:/repositoriu/RelayControl/Software/EmbeddedSoft/RelayControl/Source/Services/SchM" -I"D:/repositoriu/RelayControl/Software/EmbeddedSoft/RelayControl/Source/Services/Kernel" -I"D:/repositoriu/RelayControl/Software/EmbeddedSoft/RelayControl/Source/Inlude" -I"D:/repositoriu/RelayControl/Software/EmbeddedSoft/RelayControl/Source/Common" -I"D:/repositoriu/RelayControl/Software/EmbeddedSoft/RelayControl/Source/Cdd/Led" -I"D:/repositoriu/RelayControl/Software/EmbeddedSoft/RelayControl/Source/Utils" -I"D:/repositoriu/RelayControl/Software/EmbeddedSoft/RelayControl/Source/Peripherals/HAL_USART" -I"D:/repositoriu/RelayControl/Software/EmbeddedSoft/RelayControl/Source/TheApp" -I"D:/repositoriu/RelayControl/Software/EmbeddedSoft/RelayControl/Source/Cdd/74HC595" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"


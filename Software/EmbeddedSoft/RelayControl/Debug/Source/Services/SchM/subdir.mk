################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Source/Services/SchM/SchM.c \
../Source/Services/SchM/SchM_Callouts.c 

OBJS += \
./Source/Services/SchM/SchM.o \
./Source/Services/SchM/SchM_Callouts.o 

C_DEPS += \
./Source/Services/SchM/SchM.d \
./Source/Services/SchM/SchM_Callouts.d 


# Each subdirectory must supply rules for building sources it contributes
Source/Services/SchM/SchM.o: ../Source/Services/SchM/SchM.c Source/Services/SchM/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DSTM32L011xx -DUSE_FULL_LL_DRIVER '-DHSE_VALUE=8000000' '-DHSE_STARTUP_TIMEOUT=100' '-DLSE_STARTUP_TIMEOUT=5000' '-DLSE_VALUE=32768' '-DMSI_VALUE=2097000' '-DHSI_VALUE=16000000' '-DLSI_VALUE=37000' '-DVDD_VALUE=3300' '-DPREFETCH_ENABLE=0' '-DINSTRUCTION_CACHE_ENABLE=1' '-DDATA_CACHE_ENABLE=1' -c -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -I"D:/repositoriu/RelayControl/Software/EmbeddedSoft/RelayControl/Source/Utils/CircularFIFOBuffer" -I"D:/repositoriu/RelayControl/Software/EmbeddedSoft/RelayControl/Source/Services/SchM" -I"D:/repositoriu/RelayControl/Software/EmbeddedSoft/RelayControl/Source/Services/Kernel" -I"D:/repositoriu/RelayControl/Software/EmbeddedSoft/RelayControl/Source/Inlude" -I"D:/repositoriu/RelayControl/Software/EmbeddedSoft/RelayControl/Source/Common" -I"D:/repositoriu/RelayControl/Software/EmbeddedSoft/RelayControl/Source/Cdd/Led" -I"D:/repositoriu/RelayControl/Software/EmbeddedSoft/RelayControl/Source/Utils" -I"D:/repositoriu/RelayControl/Software/EmbeddedSoft/RelayControl/Source/Peripherals/HAL_USART" -I"D:/repositoriu/RelayControl/Software/EmbeddedSoft/RelayControl/Source/TheApp" -I"D:/repositoriu/RelayControl/Software/EmbeddedSoft/RelayControl/Source/Cdd/74HC595" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Source/Services/SchM/SchM.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Source/Services/SchM/SchM_Callouts.o: ../Source/Services/SchM/SchM_Callouts.c Source/Services/SchM/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DSTM32L011xx -DUSE_FULL_LL_DRIVER '-DHSE_VALUE=8000000' '-DHSE_STARTUP_TIMEOUT=100' '-DLSE_STARTUP_TIMEOUT=5000' '-DLSE_VALUE=32768' '-DMSI_VALUE=2097000' '-DHSI_VALUE=16000000' '-DLSI_VALUE=37000' '-DVDD_VALUE=3300' '-DPREFETCH_ENABLE=0' '-DINSTRUCTION_CACHE_ENABLE=1' '-DDATA_CACHE_ENABLE=1' -c -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -I"D:/repositoriu/RelayControl/Software/EmbeddedSoft/RelayControl/Source/Utils/CircularFIFOBuffer" -I"D:/repositoriu/RelayControl/Software/EmbeddedSoft/RelayControl/Source/Services/SchM" -I"D:/repositoriu/RelayControl/Software/EmbeddedSoft/RelayControl/Source/Services/Kernel" -I"D:/repositoriu/RelayControl/Software/EmbeddedSoft/RelayControl/Source/Inlude" -I"D:/repositoriu/RelayControl/Software/EmbeddedSoft/RelayControl/Source/Common" -I"D:/repositoriu/RelayControl/Software/EmbeddedSoft/RelayControl/Source/Cdd/Led" -I"D:/repositoriu/RelayControl/Software/EmbeddedSoft/RelayControl/Source/Utils" -I"D:/repositoriu/RelayControl/Software/EmbeddedSoft/RelayControl/Source/Peripherals/HAL_USART" -I"D:/repositoriu/RelayControl/Software/EmbeddedSoft/RelayControl/Source/TheApp" -I"D:/repositoriu/RelayControl/Software/EmbeddedSoft/RelayControl/Source/Cdd/74HC595" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Source/Services/SchM/SchM_Callouts.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"


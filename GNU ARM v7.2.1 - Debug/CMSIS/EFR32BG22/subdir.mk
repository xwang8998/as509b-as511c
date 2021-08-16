################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../CMSIS/EFR32BG22/startup_gcc_efr32bg22.s 

C_SRCS += \
../CMSIS/EFR32BG22/system_efr32bg22.c 

OBJS += \
./CMSIS/EFR32BG22/startup_gcc_efr32bg22.o \
./CMSIS/EFR32BG22/system_efr32bg22.o 

C_DEPS += \
./CMSIS/EFR32BG22/system_efr32bg22.d 


# Each subdirectory must supply rules for building sources it contributes
CMSIS/EFR32BG22/%.o: ../CMSIS/EFR32BG22/%.s
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Assembler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m33 -mthumb -c -x assembler-with-cpp -I"E:/AS509/EFR32BG22C112F352GM32/EFR32BG22C112F352GM32/hal-config" -I"D:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.7//platform/halconfig/inc/hal-config" -I"D:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.7//hardware/kit/common/halconfig" -I"D:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.7//hardware/kit/common/drivers" -I"D:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.7//hardware/kit/common/bsp" -I"D:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.7//platform/Device/SiliconLabs/EFR32BG22/Include" -I"D:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.7//platform/CMSIS/Include" -I"D:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.7//platform/emlib/inc" '-DHAL_CONFIG=1' '-DEFR32BG22C112F352GM32=1' -mfpu=fpv5-sp-d16 -mfloat-abi=softfp -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

CMSIS/EFR32BG22/system_efr32bg22.o: ../CMSIS/EFR32BG22/system_efr32bg22.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DHAL_CONFIG=1' '-DEFR32BG22C112F352GM32=1' -I"E:/AS509/EFR32BG22C112F352GM32/EFR32BG22C112F352GM32/hal-config" -I"D:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.7//platform/halconfig/inc/hal-config" -I"D:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.7//hardware/kit/common/halconfig" -I"D:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.7//hardware/kit/common/drivers" -I"D:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.7//hardware/kit/common/bsp" -I"D:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.7//platform/Device/SiliconLabs/EFR32BG22/Include" -I"D:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.7//platform/CMSIS/Include" -I"D:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.7//platform/emlib/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv5-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"CMSIS/EFR32BG22/system_efr32bg22.d" -MT"CMSIS/EFR32BG22/system_efr32bg22.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



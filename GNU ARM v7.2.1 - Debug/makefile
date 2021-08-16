################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include emlib/subdir.mk
-include CMSIS/EFR32BG22/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: EFR32BG22C112F352GM32.axf

# Tool invocations
EFR32BG22C112F352GM32.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU ARM C Linker'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m33 -mthumb -T "EFR32BG22C112F352GM32.ld" -Xlinker --gc-sections -Xlinker -Map="EFR32BG22C112F352GM32.map" -mfpu=fpv5-sp-d16 -mfloat-abi=softfp --specs=nano.specs -o EFR32BG22C112F352GM32.axf "./CMSIS/EFR32BG22/startup_gcc_efr32bg22.o" "./CMSIS/EFR32BG22/system_efr32bg22.o" "./emlib/em_acmp.o" "./emlib/em_adc.o" "./emlib/em_aes.o" "./emlib/em_assert.o" "./emlib/em_burtc.o" "./emlib/em_can.o" "./emlib/em_cmu.o" "./emlib/em_core.o" "./emlib/em_cryotimer.o" "./emlib/em_crypto.o" "./emlib/em_csen.o" "./emlib/em_dac.o" "./emlib/em_dbg.o" "./emlib/em_dma.o" "./emlib/em_ebi.o" "./emlib/em_emu.o" "./emlib/em_eusart.o" "./emlib/em_gpcrc.o" "./emlib/em_gpio.o" "./emlib/em_i2c.o" "./emlib/em_iadc.o" "./emlib/em_idac.o" "./emlib/em_int.o" "./emlib/em_lcd.o" "./emlib/em_ldma.o" "./emlib/em_lesense.o" "./emlib/em_letimer.o" "./emlib/em_leuart.o" "./emlib/em_mpu.o" "./emlib/em_msc.o" "./emlib/em_opamp.o" "./emlib/em_pcnt.o" "./emlib/em_pdm.o" "./emlib/em_prs.o" "./emlib/em_qspi.o" "./emlib/em_rmu.o" "./emlib/em_rtc.o" "./emlib/em_rtcc.o" "./emlib/em_se.o" "./emlib/em_system.o" "./emlib/em_timer.o" "./emlib/em_usart.o" "./emlib/em_vcmp.o" "./emlib/em_vdac.o" "./emlib/em_wdog.o" "./src/Si5356D.o" "./src/main.o" "./src/moni_I2C_A.o" -Wl,--start-group -lgcc -lc -lnosys -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

	@echo 'Building hex file: EFR32BG22C112F352GM32.hex'
	arm-none-eabi-objcopy -O ihex "EFR32BG22C112F352GM32.axf" "EFR32BG22C112F352GM32.hex"
	@echo ' '

	@echo 'Building bin file: EFR32BG22C112F352GM32.bin'
	arm-none-eabi-objcopy -O binary "EFR32BG22C112F352GM32.axf" "EFR32BG22C112F352GM32.bin"
	@echo ' '

	@echo 'Building s37 file: EFR32BG22C112F352GM32.s37'
	arm-none-eabi-objcopy -O srec "EFR32BG22C112F352GM32.axf" "EFR32BG22C112F352GM32.s37"
	@echo ' '

	@echo 'Running size tool'
	arm-none-eabi-size "EFR32BG22C112F352GM32.axf" -A
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) EFR32BG22C112F352GM32.axf
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

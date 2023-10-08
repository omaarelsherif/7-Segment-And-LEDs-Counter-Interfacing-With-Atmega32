################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/subdir.mk
-include HAL/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
7SEG.lss \

FLASH_IMAGE += \
7SEG.hex \

EEPROM_IMAGE += \
7SEG.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: 7SEG.elf secondary-outputs

# Tool invocations
7SEG.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,7SEG.map -mmcu=atmega32 -o "7SEG.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

7SEG.lss: 7SEG.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S 7SEG.elf  >"7SEG.lss"
	@echo 'Finished building: $@'
	@echo ' '

7SEG.hex: 7SEG.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex 7SEG.elf  "7SEG.hex"
	@echo 'Finished building: $@'
	@echo ' '

7SEG.eep: 7SEG.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex 7SEG.elf  "7SEG.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: 7SEG.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 7SEG.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) 7SEG.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

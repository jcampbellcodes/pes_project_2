RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include utilities/subdir.mk
-include startup/subdir.mk
-include source/pc_implementation/subdir.mk
-include source/fb_implementation/subdir.mk
-include source/subdir.mk
-include drivers/subdir.mk
-include board/subdir.mk
-include CMSIS/subdir.mk
-include subdir.mk
-include objects.mk

# runs all rules
#all: pc_run fb_run

# dependencies create the output and build dirs and then compile/link all the code 
#pc_run: output/pc_run 
#fb_run: output/pes_project2.axf

output/pc_run: $(PC_OBJS)
	$(CC) ${CFLAGS} -DDEBUG -o $@ $^ 

# Tool invocations
output/pes_project2.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -Xlinker --gc-sections -Xlinker -Map="pes_project2.map" -Xlinker -print-memory-usage -Xlinker --sort-section=alignment -Xlinker --cref -mcpu=cortex-m0plus -mthumb -T "pes_project2_Release.ld" -o "output/pes_project2.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) pes_project2.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "pes_project2.axf"; # arm-none-eabi-objcopy -v -O binary "pes_project2.axf" "pes_project2.bin" ; # checksum -p MKL25Z128xxx4 -d "pes_project2.bin";
	-@echo ' '

.PHONY: all clean dependents post-build

-include ../makefile.targets

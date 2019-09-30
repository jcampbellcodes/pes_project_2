# defines for the pc builds
PC_SRC_REL_ROOT = ../source/pc_implementation
PC_SRCS = $(wildcard $(PC_SRC_REL_ROOT)/*.c)
PC_OBJS = $(patsubst ../%.c, bin/%.o, $(PC_SRCS)) bin/source/pc_implementation/main.o
# compiler
CC = gcc
# flags
CFLAGS  = -g -Wall -Werror -I../include
RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include utilities/subdir.mk
-include startup/subdir.mk
-include source/fb_implementation/subdir.mk
-include source/subdir.mk
-include drivers/subdir.mk
-include board/subdir.mk
-include CMSIS/subdir.mk
-include subdir.mk
-include objects.mk

# runs all rules
all: pc_debug fb_debug

# dependencies create the output and build dirs and then compile/link all the code 
pc_debug: output/pc_debug 
fb_debug: output/pes_project2_debug.axf

output/pc_debug: $(PC_OBJS)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -DDEBUG -o $@ $^ 

# Tool invocations
output/pes_project2.axf: $(OBJS) $(USER_OBJS)
	mkdir -p $(dir $@)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -Werror -Wall -nostdlib -Xlinker --gc-sections -Xlinker -Map="pes_project2.map" -Xlinker -print-memory-usage -Xlinker --sort-section=alignment -Xlinker --cref -mcpu=cortex-m0plus -mthumb -T pes_project_2_Debug.ld -o "output/pes_project2.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# making object targets for all the source files
bin/source/pc_implementation/%.o: $(PC_SRC_REL_ROOT)/%.c
	mkdir -p $(dir $@)
	gcc -c -o $@ $< $(CFLAGS) -DDEBUG 
	
# special case main, which is not in the platform specific dir
bin/source/pc_implementation/main.o: ../source/main.c
	mkdir -p $(dir $@)
	gcc -c -o $@ $< $(CFLAGS) -DDEBUG 
	
# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS)$(PC_OBJS) output/pc_debug output/pes_project2.axf source/pc_implementation/main.o */*.o */*/*.o
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "output/pes_project2.axf"; # arm-none-eabi-objcopy -v -O binary "pes_project2.axf" "pes_project2.bin" ; # checksum -p MKL25Z128xxx4 -d "pes_project2.bin";
	-@echo ' '

.PHONY: all clean dependents post-build
	
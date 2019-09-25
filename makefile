#SRCS = $(wildcard source/*.c) \
#       $(wildcard source/pc_implementation/*.c))
#       
SUBDIRS := source  source/pc_implementation source/fb_implementation
OBJDIRS := $(patsubst %, build/%, $(SUBDIRS))
#
#OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS  = -g -Wall -Iinclude

all: pc_run pc_debug fb_run fb_debug

pc_run: $(OBJDIRS) make_output_dir output/pc_run 
fb_run: $(OBJDIRS) make_output_dir output/fb_run 
pc_debug: $(OBJDIRS) make_output_dir output/pc_debug 
fb_debug: $(OBJDIRS) make_output_dir output/fb_debug 

output/pc_run: build/source/main.o build/source/pc_implementation/delay.o build/source/pc_implementation/handle_led.o build/source/pc_implementation/setup_teardown.o
	$(CC) ${CFLAGS} -o $@ $^ 
	
output/pc_debug: build/source/main.o build/source/pc_implementation/delay.o build/source/pc_implementation/handle_led.o build/source/pc_implementation/setup_teardown.o
	$(CC) ${CFLAGS} -DDEBUG -o $@ $^ 
	
output/fb_run: build/source/main.o build/source/fb_implementation/delay.o build/source/fb_implementation/handle_led.o build/source/fb_implementation/setup_teardown.o
	$(CC) ${CFLAGS} -o $@ $^ 
	
output/fb_debug: build/source/main.o build/source/fb_implementation/delay.o build/source/fb_implementation/handle_led.o build/source/fb_implementation/setup_teardown.o
	$(CC) ${CFLAGS} -DDEBUG -o $@ $^ 

# creating the build dir
$(OBJDIRS):
	mkdir -p $@ 

# creating the output dir
make_output_dir:
	mkdir -p output

# making object targets for all the source files
build/%.o: %.c $(DEPS)
	gcc -c -o $@ $< $(CFLAGS)

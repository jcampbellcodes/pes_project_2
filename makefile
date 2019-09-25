PC_SRCS = $(wildcard source/*.c) \
          $(wildcard source/pc_implementation/*.c)

FB_SRCS = $(wildcard source/*.c) \
          $(wildcard source/fb_implementation/*.c)

PC_OBJS = $(patsubst %.c, build/%.o, $(PC_SRCS))
FB_OBJS = $(patsubst %.c, build/%.o, $(FB_SRCS))

# used for output and build dir creation
SUBDIRS := source  source/pc_implementation source/fb_implementation
OBJDIRS := $(patsubst %, build/%, $(SUBDIRS))

# compiler
CC = gcc

# flags
CFLAGS  = -g -Weverything -Wall -Iinclude

# runs all rules
all: pc_run pc_debug fb_run fb_debug

# dependencies create the output and build dirs and then compile/link all the code 
pc_run: $(OBJDIRS) make_output_dir output/pc_run 
fb_run: $(OBJDIRS) make_output_dir output/fb_run 
pc_debug: $(OBJDIRS) make_output_dir output/pc_debug 
fb_debug: $(OBJDIRS) make_output_dir output/fb_debug 

output/pc_run: $(PC_OBJS)
	$(CC) ${CFLAGS} -o $@ $^ 
	
output/pc_debug: $(PC_OBJS)
	$(CC) ${CFLAGS} -DDEBUG -o $@ $^ 
	
output/fb_run: $(FB_OBJS)
	$(CC) ${CFLAGS} -o $@ $^ 
	
output/fb_debug: $(FB_OBJS)
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

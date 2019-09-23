cmake_minimum_required(VERSION 3.14)
project(pes_project_2 C)

include_directories(include)
set(CMAKE_C_STANDARD 99)

#set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -DDEBUG")

set(
        FB_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/source/fb_implementation/delay.c
        ${CMAKE_CURRENT_SOURCE_DIR}/source/fb_implementation/handle_led.c
        ${CMAKE_CURRENT_SOURCE_DIR}/source/fb_implementation/setup_teardown.c
)

set(
        PC_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/source/pc_implementation/delay.c
        ${CMAKE_CURRENT_SOURCE_DIR}/source/pc_implementation/handle_led.c
        ${CMAKE_CURRENT_SOURCE_DIR}/source/pc_implementation/setup_teardown.c
)

add_executable(pes_project_2 source/main.c ${PC_SOURCES})
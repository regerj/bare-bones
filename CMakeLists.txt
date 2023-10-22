cmake_minimum_required(VERSION 3.18.0)

include(./toolchain.cmake)

enable_language(ASM-ATT)

set(MY_COMPILE_FLAGS "-std=gnu99 -ffreestanding -O2 -Wall -Wextra")
set(MY_LINKER_FLAGS "-ffreestanding -O2 -nostdlib -lgcc")

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${MY_LINKER_FLAGS}")
set(CMAKE_C)
project(timberline C)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${MY_COMPILE_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "-T ${CMAKE_SOURCE_DIR}/linker.ld ${CMAKE_EXE_LINKER_FLAGS}")

add_subdirectory(src)
add_subdirectory(stdlib)

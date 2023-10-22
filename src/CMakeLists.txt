add_library(
    kernel
    OBJECT
    kernel.c
)

target_include_directories(
    kernel
    PUBLIC
    .
)

add_library(
    vga
    OBJECT
    vga.c
)

target_include_directories(
    vga
    PUBLIC
    .
)

add_library(
    boot
    OBJECT
    boot.s
)

target_include_directories(
    boot
    PUBLIC
    .
)

add_executable(timberline)

target_link_libraries(
    vga
    PRIVATE
    stdstring
    stdmem
)

target_link_libraries(
    timberline
    PRIVATE
    boot 
    kernel
    vga
)

set_target_properties(
    timberline
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/build/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/build/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/build/bin"
)

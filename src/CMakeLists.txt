add_library(
    kernel
    OBJECT
    kernel.c
)

add_library(
    vga
    OBJECT
    vga.c
)

add_library(
    boot
    OBJECT
    boot.s
)

add_executable(timberline)

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
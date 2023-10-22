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

add_executable(Timberline)

target_link_libraries(
    Timberline
    PRIVATE
    boot 
    kernel
    vga
)
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#if defined(__linux__)
#error "Use a cross compiler idiot"
#endif

#if !defined(__i386__)
#error "You need to use an ix86-elf compiler"asm
#endif

#include "vga.h"

void kernel_main(void) {
    terminal_initialize();

    terminal_write_string("Hello world! -Kernel\n");
    terminal_write_string("Newlines now work!\n");
}
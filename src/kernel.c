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

    terminal_write_string("0\n");
    terminal_write_string("1\n");
    terminal_write_string("2\n");
    terminal_write_string("3\n");
    terminal_write_string("4\n");
    terminal_write_string("5\n");
    terminal_write_string("6\n");
    terminal_write_string("7\n");
    terminal_write_string("8\n");
    terminal_write_string("9\n");
    terminal_write_string("10\n");
    terminal_write_string("11\n");
    terminal_write_string("12\n");
    terminal_write_string("13\n");
    terminal_write_string("14\n");
    terminal_write_string("15\n");
    terminal_write_string("16\n");
    terminal_write_string("17\n");
    terminal_write_string("18\n");
    terminal_write_string("19\n");
    terminal_write_string("20\n");
    terminal_write_string("21\n");
    terminal_write_string("22\n");
    terminal_write_string("23\n");
    terminal_write_string("24\n");
    terminal_write_string("25\n");
    terminal_write_string("26\n");
    terminal_write_string("27\n");
    terminal_write_string("28\n");
    terminal_write_string("29\n");
    terminal_write_string("30\n");
}
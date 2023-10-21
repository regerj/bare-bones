#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#if defined(__linux__)
#error "Use a cross compiler idiot"
#endif

#if !defined(__i386__)
#error "You need to use an ix86-elf compiler"asm
#endif

enum vga_color {
    VGA_COLOR_BLACK = 0,
    VGA_COLOR_BLUE = 1,
    VGA_COLOR_GREEN = 2,
    VGA_COLOR_CYAN = 3,
    VGA_COLOR_RED = 4,
    VGA_COLOR_MAGENTA = 5,
    VGA_COLOR_BROWN = 6,
    VGA_COLOR_LIGHT_GREY = 7,
    VGA_COLOR_DARK_GREY = 8,
    VGA_COLOR_LIGHT_BLUE = 9,
    VGA_COLOR_LIGHT_GREEN = 10,
    VGA_COLOR_LIGHT_CYAN = 11,
    VGA_COLOR_LIGHT_RED = 12,
    VGA_COLOR_LIGHT_MAGENTA = 13,
    VGA_COLOR_LIGHT_BROWN = 14,
    VGA_COLOR_WHITE = 15,
};

union vga_color_structure {
    uint8_t raw;
    struct {
        uint8_t foreground : 4;
        uint8_t background : 4;
    } structure;
};

typedef union vga_color_structure vga_color_structure;

union vga_entry_structure {
    uint16_t raw;
    struct {
        vga_color_structure color;
        uint8_t character;
    } structure;
};

typedef union vga_entry_structure vga_entry_structure;


static inline vga_color_structure vga_entry_color(enum vga_color foreground, enum vga_color background) {
    vga_color_structure color = {.structure = {.foreground = foreground, .background = background}};
    return color;
}

static inline vga_entry_structure vga_entry(unsigned char character, vga_color_structure color) {
    vga_entry_structure entry = {.structure = {.color = color, .character = character}};
    return entry;
}

size_t string_length(const char *string) {
    size_t length = 0;
    while (string[length]) {
        length++;
    }
    return length;
}

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;

size_t terminal_row;
size_t terminal_column;
vga_color_structure terminal_color;
vga_entry_structure *terminal_buffer;

void terminal_initialize() {
    terminal_row = 0;
    terminal_column = 0;
    terminal_color ; vga_entry_color(VGA_COLOR_LIGHT_GREY,)
}
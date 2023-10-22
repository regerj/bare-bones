#include "vga.h"

#define VGA_TEXT_MODE_BUFFER 0xB8000

/***************************************************************************
 * Internal API
***************************************************************************/

static size_t string_length(const char *string) {
    size_t length = 0;
    while (string[length]) {
        length++;
    }
    return length;
}

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
        uint8_t character;
        vga_color_structure color;
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

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;

static size_t terminal_row;
static size_t terminal_column;
static vga_color_structure terminal_color;
static vga_entry_structure *terminal_buffer;

static void terminal_put_entry_at(char character, vga_color_structure color, size_t x, size_t y) {
    const size_t index = y * VGA_WIDTH + x;
    terminal_buffer[index] = vga_entry(character, color);
}

static void terminal_put_char(char character) {
    terminal_put_entry_at(character, terminal_color, terminal_column, terminal_row);
    if (++terminal_column == VGA_WIDTH) {
        terminal_column = 0;
        if (++terminal_row == VGA_HEIGHT) {
            terminal_row = 0;
        }
    }
}

static void terminal_write(const char *data, size_t size) {
    for (size_t i = 0; i < size; i++) {
        terminal_put_char(data[i]);
    }
}

/***************************************************************************
 * External API
***************************************************************************/

void terminal_initialize() {
    terminal_row = 0;
    terminal_column = 0;
    terminal_color = vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
    terminal_buffer = (vga_entry_structure *) VGA_TEXT_MODE_BUFFER;
    for (size_t y = 0; y < VGA_HEIGHT; y++) {
        for (size_t x = 0; x < VGA_WIDTH; x++) {
            const size_t index = y * VGA_WIDTH + x;
            terminal_buffer[index] = vga_entry(' ', terminal_color);
        }
    }
}

void terminal_set_color(vga_color foreground_color, vga_color background_color) {
    vga_color_structure color_structure = {
        .structure = {
            .foreground = foreground_color,
            .background = background_color
        }
    };

    terminal_color = color_structure;
}

void terminal_write_string(const char *data) {
    terminal_write(data, string_length(data));
}

/* Define the entry point of the program, this is in boot.s */
ENTRY(_start)

/* Define where to place the sections of memory */
SECTIONS{
    /* Begin loading at 1 megabyte, which is a convinient spot */
    . = 1M;

    /* Place a 4K block, 4K aligned, begining with multiboot header
     * and finishing with the actual code. Multiboot must be early
     * in order to be recongized by the bootloader. */
    .text BLOCK(4K) : ALIGN(4K) {
        *(.multiboot)
        *(.text)
    }

    .rodata BLOCK(4K) : ALIGN(4K) {
        *(.rodata)
    }

    .data BLOCK(4K) : ALIGN(4K) {
        *(.data)
    }

    .bss BLOCK(4K) : ALIGN(4K) {
        *(COMMON)
        *(.bss)
    }
}
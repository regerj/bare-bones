.set ALIGN,     1<<0            /* align loaded modules on page boundaries */
.set MEMINFO,   1<<1            /* provide memory map */
.set FLAGS,     ALIGN | MEMINFO /* this is the Multiboot 'flag' field */
.set MAGIC,     0x1BADB002      /* 'magic number' lets bootloader find the header */
.set CHECKSUM,  -(MAGIC + FLAGS)/* checksum of above, to prove we are multiboot */

.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

.section .bss
.align 16
stack_bottom:
.skip 16384
stack_top:

.section .text
.global _start
.type _start, @function
_start:
    mov $stack_top, %esp # sets up the stack top pointer, what about stack base?

    call kernel_main

    cli # clear interupt flasgs (disable interrupts)
1:  hlt # wait for an interrupt
    jmp 1b # jump back to hlt instruction if, for some reason, the beast awakens

.size _start, . - _start

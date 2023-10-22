#ifndef STD_MEM_H
#define STD_MEM_H

#include <stdint.h>
#include <stddef.h>

void mem_copy(void *source, void *destination, size_t size) {
    uint8_t * _source = (uint8_t *)source;
    uint8_t *_destination = (uint8_t *)destination;
    for (size_t i = 0; i < size; i++) {
        *_destination++ = *_source++;
    }
}

#endif

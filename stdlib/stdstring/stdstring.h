#ifndef STD_STRING_H
#define STD_STRING_H

#include <stddef.h>

size_t string_length(const char *string) {
    size_t length = 0;
    while (string[length]) {
        length++;
    }
    return length;
}

#endif

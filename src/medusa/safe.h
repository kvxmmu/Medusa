#ifndef MDSU_SAFE_H
#define MDSU_SAFE_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#include "compiler.h"

static inline void *safe_realloc(void *ptr, size_t to_size) {
    void *new_ptr = realloc(ptr, to_size);
    if (unlikely(new_ptr == NULL)) {
        fprintf(stderr, "Medusa error: failed to allocate %zu bytes\n", to_size);
        abort();
    }

    return new_ptr;
}

#endif

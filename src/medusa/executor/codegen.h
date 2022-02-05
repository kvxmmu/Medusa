#ifndef MDSU_CODEGEN_H
#define MDSU_CODEGEN_H

#include <inttypes.h>
#include <inttypes.h>
#include <stddef.h>
#include <stdlib.h>

#include "insn.h"
#include "../safe.h"

typedef struct {
    size_t insns;
    size_t capacity;

    uint32_t *buffer;
} VMEmitter;

static inline void emitter_new(VMEmitter *emitter, size_t capacity) {
    emitter->insns = 0;
    emitter->capacity = capacity;
    emitter->buffer = (uint32_t *)calloc(4, capacity);
}

static inline void emitter_twice_capacity(VMEmitter *emitter) {
    size_t new_cap = emitter->capacity << 1u;
    emitter->buffer = (uint32_t *)safe_realloc(emitter->buffer, new_cap * 4);
}

void emitter_emit(
    VMEmitter *emitter,
    uint32_t mode,
    uint32_t insn,
    uint32_t args
);

static inline void emitter_free(VMEmitter *emitter) {
    if (unlikely(emitter->buffer == NULL)) {
        return;
    }

    free(emitter->buffer);
}

#endif

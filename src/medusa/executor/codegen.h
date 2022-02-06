#ifndef MDSU_CODEGEN_H
#define MDSU_CODEGEN_H

#include <inttypes.h>
#include <inttypes.h>
#include <stddef.h>
#include <stdlib.h>

#include "insn.h"
#include "../safe.h"

#define MF_JOIN2(a, b) a##_##b
#define GEN_OFFSET_INSN(name, insn) static inline insn_off_t MF_JOIN2(emitter_emit, name)(VMEmitter *emitter, insn_off_t global_offset, reg_t hreg1) { \
    insn_off_t flag; \
    insn_off_t chunk; \
    insn_off_t reg1 = hreg1; \
    if (global_offset <= MAX20BIT) { \
        flag = FULL_INSN; \
    } else { \
        flag          = PARTIAL_INSN; \
        chunk         = global_offset >> 20u;\
        global_offset = global_offset & MAX20BIT; \
    } \
    emitter_emit( \
        emitter, \
        MACHINIC, \
        (insn), \
        (reg1 << 20) | (global_offset) | flag \
    ); \
    if (global_offset > MAX20BIT) { \
        emitter_emit( \
            emitter, \
            EXTENDED, \
            CONST_CHUNK, \
            chunk   \
        ); \
        return 2; \
    } else { \
        return 1; \
    } \
}

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

void emitter_emit_noop(
    VMEmitter *emitter
);

void emitter_emit_iprint(
    VMEmitter *emitter,
    reg_t reg
);

static inline void emitter_free(VMEmitter *emitter) {
    if (unlikely(emitter->buffer == NULL)) {
        return;
    }

    free(emitter->buffer);
}

GEN_OFFSET_INSN(jmp, JMP)

#endif

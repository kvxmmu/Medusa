#include "codegen.h"

void emitter_emit(
    VMEmitter *emitter,
    uint32_t mode,
    uint32_t insn,
    uint32_t args
) {
    if (emitter->capacity < emitter->insns+1) {
        emitter_twice_capacity(emitter);
    }

    uint32_t op = (((mode << 6u) | insn) << 24u) | args;
    emitter->buffer[emitter->insns++] = op;
}

void emitter_emit_noop(
    VMEmitter *emitter
) {
    emitter_emit(
        emitter,
        MACHINIC,
        NOOP,
        0
    );
}

void emitter_emit_iprint(
    VMEmitter *emitter,
    reg_t reg
) {
    emitter_emit(
        emitter,
        MACHINIC,
        IPRINT,
        reg
    );
}

#include "codegen.h"

void emitter_emit(
    VMEmitter *emitter,
    uint32_t mode,
    uint32_t insn,
    uint32_t args
) {
    uint32_t op = (((mode << 6u) | insn) << 24u) | args;
    emitter->buffer[emitter->insns++] = op;
}

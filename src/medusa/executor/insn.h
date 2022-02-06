#ifndef MDSU_INSN_H
#define MDSU_INSN_H

#include <inttypes.h>

typedef uint8_t  reg_t;
typedef uint32_t insn_off_t;

#define MACHINIC   0b00  // base machine commands
#define CONSTANT   0b01  // 24Bit constant
#define CALL       0b10  // Optimized call
#define EXTENDED   0b11  // Extended constant definition

#define MAX20BIT       ((1u << 20u) - 1)
#define PARTIAL_INSN   (1u << 19u)
#define FULL_INSN      (0u << 19u)

// REGISTERS

#define R0   0b0001
#define R1   0b0010
#define R2   0b0011
#define R3   0b0100
#define R4   0b0101
#define R5   0b0110
#define R6   0b0111
#define R7   0b1000
#define R8   0b1001
#define R9   0b1010
#define R10  0b1011
#define R11  0b1100
#define R12  0b1101
#define R13  0b1110

// MACHINIC commands

#define NOOP          0x0
#define PRINTLN       0x1   // Print string with 24bit length
#define JMP           0x2   // Unconditional jump
#define EJMP          0x3   // Conditional jump to 23bit global condition offset
#define NEJMP         0x4   // same as EJMP, but jumps if condition is false
#define IPRINT        0x5   // Print i32 constant(debugging)

// Arithmetic commands

#define ADD 0x0

// Extended

#define CONST_CHUNK   0x0  // argument continuation followed by other commands

#endif

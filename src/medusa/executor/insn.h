#ifndef MDSU_INSN_H
#define MDSU_INSN_H

#define MACHINIC   0b00  // base machine commands
#define CONSTANT   0b01  // 24Bit constant
#define CALL       0b10  // Optimized call
#define EXTENDED   0b11  // Extended constant definition

// REGISTERS

#define R0   0b00001
#define R1   0b00010
#define R2   0b00011
#define R3   0b00100
#define R4   0b00101
#define R5   0b00110
#define R6   0b00111
#define R7   0b01000
#define R8   0b01001
#define R9   0b01010
#define R10  0b01011
#define R11  0b01100
#define R12  0b01101

// MACHINIC commands

#define NOOP       0x0
#define PRINTLN    0x1   // Print string with length() from stack offset 
#define JMP        0x2   // Unconditional jump
#define EJMP       0x3   // Conditional jump
#define NEJMP      0x4
#define IPRINT     0x5  // Print i32 constant

#endif

// -------------------------------------------------------------------------------------------------------------------------------
//
// Title: Opcodes for the MOS 6502 Processor
//
// Author: Nicholas Juk
//
// File: mos6502_opcode.h
//
// Description:
//   Contains definitions for all of the 6502 opcodes.
//
// -------------------------------------------------------------------------------------------------------------------------------

#ifndef MOS_6502_OPCODES_H
#define MOS_6502_OPCODES_H

// -------------------------------------------------------------------------------------------------------------------------------
// Defines
// -------------------------------------------------------------------------------------------------------------------------------
// Add With Carry (ADC)
#define ADC_IMMEDIATE   0x69
#define ADC_ZERO_PAGE   0x65
#define ADC_ZERO_PAGE_X 0x75
#define ADC_ABSOLUTE    0x6D
#define ADC_ABSOLUTE_X  0x7D
#define ADC_ABSOLUTE_Y  0x79
#define ADC_INDIRECT_X  0x61
#define ADC_INDIRECT_Y  0x71

// Logical And (AND)
#define AND_IMMEDIATE   0x29
#define AND_ZERO_PAGE   0x25
#define AND_ZERO_PAGE_X 0x35
#define AND_ABSOLUTE    0x2D
#define AND_ABSOLUTE_X  0x3D
#define AND_ABSOLUTE_Y  0x39
#define AND_INDIRECT_X  0x21
#define AND_INDIRECT_Y  0x31

// Arithmetic Shift Left (ASL)
#define ASL_IMMEDIATE   0x0A
#define ASL_ZERO_PAGE   0x06
#define ASL_ZERO_PAGE_X 0x16
#define ASL_ABSOLUTE    0x0E
#define ASL_ABSOLUTE_X  0x1E

// Branch If Carry Is Clear (BCC)
#define BCC_RELATIVE    0x90

// Branch If Carry Is Set (BCS)
#define BCS_RELATIVE    0xB0

// Branch If Equal (BEQ)
#define BEQ_RELATIVE    0xF0

// Bit Test (BIT)
#define BIT_ZERO_PAGE   0x24
#define BIT_ABSOLUTE    0x2C

// Branch If Minus (BMI)
#define BMI_RELATIVE    0x30

// Branch If Not Equal (BNE)
#define BNE_RELATIVE    0xD0

// Branch If Positive (BPL)
#define BPL_RELATIVE    0x10

// Force Interrupt (BRK)
#define BRK_IMPLIED     0x00

// Branch If Overflow Clear (BVC)
#define BVC_RELATIVE    0x50

// Branch If Overflow Set (BVS)
#define BVS_RELATIVE    0x70

// Clear Carry Flag (CLC)
#define CLC_IMPLIED     0x18

// Clear Decimal Mode CLD
#define CLD_IMPLIED     0xD8

// Clear Interrupt Disable CLI
#define CLI_IMPLIED     0x58

// Clear Overflow Flag
#define CLV_IMPLIED     0xB8

// Compare (CMP)
#define CMP_IMMEDIATE   0xC9
#define CMP_ZERO_PAGE   0xC5
#define CMP_ZERO_PAGE_X 0xD5
#define CMP_ABSOLUTE    0xCD
#define CMP_ABSOLUTE_X  0xDD
#define CMP_ABSOLUTE_Y  0xD9
#define CMP_INDIRECT_X  0xC1
#define CMP_INDIRECT_Y  0xD1

// Compare X Register (CPX)
#define CPX_IMMEDIATE   0xE0
#define CPX_ZERO_PAGE   0xE4
#define CPX_ABSOLUTE    0xEC

// Compare Y Register (CPY)
#define CPY_IMMEDIATE   0xC0
#define CPY_ZERO_PAGE   0xC4
#define CPY_ABSOLUTE    0xCC

// Decrement Memory (DEC)
#define DEC_ZERO_PAGE   0xC6
#define DEC_ZERO_PAGE_X 0xD6
#define DEC_ABSOLUTE    0xCE
#define DEC_ABSOLUTE_X  0xDE

// Decrement X Register (DEX)
#define DEX_IMPLIED     0xCA

// Decrement Y Register (DEY)
#define DEY_IMPLIED     0x88

// Exclusive Or (EOR)
#define EOR_IMMEDIATE   0x49
#define EOR_ZERO_PAGE   0x45
#define EOR_ZERO_PAGE_X 0x55
#define EOR_ABSOLUTE    0x4D
#define EOR_ABSOLUTE_X  0x5D
#define EOR_ABSOLUTE_Y  0x59
#define EOR_INDIRECT_X  0x41
#define EOR_INDIRECT_Y  0x51

// Increment Memory (INC)
#define INC_ZERO_PAGE   0xE6
#define INC_ZERO_PAGE_X 0xF6
#define INC_ABSOLUTE    0xEE
#define INC_ABSOLUTE_X  0xFE

// Increment X Register (INX)
#define INX_IMPLIED     0xE8

// Increment Y Register (INY)
#define INY_IMPLIED     0xC8

// Jump (JMP)
#define JMP_ABSOLUTE    0x4C
#define JMP_INDIRECT    0x6C

// Jump To Subroutine (JSR)
#define JSR_ABSOLUTE    0x20

// Load Accumulator (LDA)
#define LDA_IMMEDIATE   0xA9
#define LDA_ZERO_PAGE   0xA5
#define LDA_ZERO_PAGE_X 0xB5
#define LDA_ABSOLUTE    0xAD
#define LDA_ABSOLUTE_X  0xBD
#define LDA_ABSOLUTE_Y  0xB9
#define LDA_INDIRECT_X  0xA1
#define LDA_INDIRECT_Y  0xB1

// Load X Register (LDX)
#define LDX_IMMEDIATE   0xA2
#define LDX_ZERO_PAGE   0xA6
#define LDX_ZERO_PAGE_Y 0xB6
#define LDX_ABSOLUTE    0xAE
#define LDX_ABSOLUTE_Y  0xBE

// Load Y Register (LDY)
#define LDY_IMMEDIATE   0xA0
#define LDY_ZERO_PAGE   0xA4
#define LDY_ZERO_PAGE_X 0xB4
#define LDY_ABSOLUTE    0xAC
#define LDY_ABSOLUTE_X  0xBC

// Logical Shift Register (LSR)
#define LSP_ACCUMULATOR 0x4A
#define LSR_ZERO_PAGE   0x46
#define LSR_ZERO_PAGE_X 0x56
#define LSR_ABSOLUTE    0x4E
#define LSR_ABSOLUTE_X  0x5E

// No Operation (NOP)
#define NOP_IMPLIED     0xEA

// Logical Inclusive Or (ORA)
#define ORA_IMMEDIATE   0x09
#define ORA_ZERO_PAGE   0x05
#define ORA_ZERO_PAGE_X 0x15
#define ORA_ABSOLUTE    0x0D
#define ORA_ABSOLUTE_X  0x1D
#define ORA_ABSOLUTE_Y  0x19
#define ORA_INDIRECT_X  0x01
#define ORA_INDIRECT_Y  0x11

// Push Accumulator (PHA)
#define PHA_IMPLIED     0x48

// Push Processor Status (PHP)
#define PHP_IMPLIED     0x08

// Pull Processor Status (PLP)
#define PLP_IMPLIED     0x28

// Rotate Left (ROL)
#define ROL_ACCUMULATOR 0x2A
#define ROL_ZERO_PAGE   0x26
#define ROL_ZERO_PAGE_X 0x36
#define ROL_ABSOLUTE    0x2E
#define ROL_ABSOLUTE_X  0x3E

// Rotate Right (ROR)
#define ROR_ACCUMULATOR 0x6A
#define ROR_ZERO_PAGE   0x66
#define ROR_ZERO_PAGE_X 0x76
#define ROR_ABSOLUTE    0x6E
#define ROR_ABSOLUTE_X  0x7E

// Return From Interrupt (RTI)
#define RTI_IMPLIED     0x40

// Return From Subroutine (RTS)
#define RTS_IMPLIED     0x60

// Subtract With Carry (SBC)
#define SBC_IMMEDIATE   0xE9
#define SBC_ZERO_PAGE   0xE5
#define SBC_ZERO_PAGE_X 0xF5
#define SBC_ABSOLUTE    0xED
#define SBC_ABSOLUTE_X  0xFD
#define SBC_ABSOLUTE_Y  0xF9
#define SBC_INDIRECT_X  0xE1
#define SBC_INDIRECT_Y  0xF1

// Set Carry Flag (SEC)
#define SEC_IMPLIED     0x38

// Set Decimal Flag (SED)
#define SED_IMPLIED     0xF8

// Set Interrupt Disable (SEI)
#define SEI_IMPLIED     0x78

// Store Accumulator (STA)
#define STA_ZERO_PAGE   0x85
#define STA_ZERO_PAGE_X 0x95
#define STA_ABSOLUTE    0x8D
#define STA_ABSOLUTE_X  0x9D
#define STA_ABSOLUTE_Y  0x99
#define STA_INDIRECT_X  0x81
#define STA_INDIRECT_Y  0x91

// Store X Register (STX)
#define STX_ZERO_PAGE   0x86
#define STX_ZERO_PAGE_Y 0x96
#define STX_ABSOLUTE    0x8E

// Store Y Register (STY)
#define STY_ZERO_PAGE   0x84
#define STY_ZERO_PAGE_X 0x94
#define STY_ABSOLUTE    0x8C

// Transfer Accumulator To X (TAX)
#define TAX_IMPLIED     0xAA

// Transfer Accumulator To Y (TAY)
#define TAY_IMPLIED     0xA8

// Transfer Stack Pointer To X (TSX)
#define TSX_IMPLIED     0xBA

// Transfer X to Accumulator (TXA)
#define TXA_IMPLIED     0x8A

// Transfer X to Stack Pointer (TXS)
#define TXS_IMPLIED     0x9A

// Transfer Y to Accumulator (TYA)
#define TYA_IMPLIED     0x98

#endif // MOS_6502_OPCODES_H
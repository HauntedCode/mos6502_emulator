// -------------------------------------------------------------------------------------------------------------------------------
//
// Title: MOS 6502 Emulator Header File
//
// Author: Nicholas Juk
//
// File: mos6502_emulator.h
//
// Description:
//   Contains the funtion prototypes and data types needed to emulate the MOS 6502 processor
//
// -------------------------------------------------------------------------------------------------------------------------------

#ifndef MOS_6502_EMULATOR_H
#define MOS_6502_EMULATOR_H

// -------------------------------------------------------------------------------------------------------------------------------
// Defines
// -------------------------------------------------------------------------------------------------------------------------------
// Memory Size (64 kB)
#define MOS_6502_MEM_SIZE 65536

// Reserved Memory Locations
#define INTERRUPT_HANDLER_1 0xFFFA
#define INTERRUPT_HANDLER_2 0xFFFB
#define RESET_LOCATION_1    0xFFFC
#define RESET_LOCATION_2    0xFFFD
#define INTERRUPT_REQUEST_1 0xFFFE
#define INTERRUPT_REQUEST_2 0xFFFF

// Stack Base Address
#define STACK_BASE_ADDR 0x0100

// Stack Memory Size
#define STACK_SIZE 256

// Zero Page Memory Size
#define ZERO_PAGE_SIZE 256

// -------------------------------------------------------------------------------------------------------------------------------
// Data Types
// -------------------------------------------------------------------------------------------------------------------------------
// Processor Status Bits
typedef struct t_struct_processor_status {
    unsigned char carry_flag : 1;
    unsigned char zero_flag : 1;
    unsigned char interrupt_disable : 1;
    unsigned char decimal_mode : 1;
    unsigned char break_command : 1;
    unsigned char overflow_flag : 1;
    unsigned char negative_flag : 1;
} t_processor_status;

// Registers Structure
typedef struct t_struct_registers {
    unsigned short program_counter;
    unsigned char stack_pointer;
    unsigned char accumulator;
    unsigned char register_x;
    unsigned char register_y;
    t_processor_status processor_status;
} t_registers;

// -------------------------------------------------------------------------------------------------------------------------------
// Function Prototypes
// -------------------------------------------------------------------------------------------------------------------------------
// Reset MOS 6502
extern void reset_mos6502(unsigned char *, t_registers *);

// Print Registers
extern void print_registers_mos6502(t_registers *);

// Execute Instructions 
extern void execute_mos6502(unsigned char *, t_registers *);

#endif // MOS_6502_EMULATOR_H
// -------------------------------------------------------------------------------------------------------------------------------
//
// Title: MOS 6502 Emulator
//
// Author: Nicholas Juk
//
// File: mos6502_emulator.c
//
// Description:
//   Emulates the MOS 6502 Processor
//
// -------------------------------------------------------------------------------------------------------------------------------

// -------------------------------------------------------------------------------------------------------------------------------
// Libraries
// -------------------------------------------------------------------------------------------------------------------------------
// Standard
#include <stdio.h>

// Local
#include "mos6502_opcode.h"
#include "mos6502_emulator.h"

// -------------------------------------------------------------------------------------------------------------------------------
// Types
// -------------------------------------------------------------------------------------------------------------------------------
// Enumerated type for zero page access type
typedef enum {
    ZERO_PAGE, 
    ZERO_PAGE_X, 
    ZERO_PAGE_Y,
    ABSOLUTE,
    ABSOLUTE_X,
    ABSOLUTE_Y,
    INDIRECT,
    INDEXED_INDIRECT,
    INDIRECT_INDEXED
} t_memory_access;

// -------------------------------------------------------------------------------------------------------------------------------
// Function Prototypes
// -------------------------------------------------------------------------------------------------------------------------------
// Fetches an instruction
static unsigned char fetch(unsigned char *, t_registers *);

// Reads the zero page in memory
static unsigned char read_memory(unsigned char *, t_registers *, unsigned short, t_memory_access);

// Sets the processor status flags
static void set_zero_page(t_registers *, unsigned char);
static void set_negative_flag(t_registers *, unsigned char);
static void set_carry_flag(t_registers *, short);

// -------------------------------------------------------------------------------------------------------------------------------
// Reset MOS 6502
//   Inputs: Memory, Registers
// -------------------------------------------------------------------------------------------------------------------------------
extern void reset_mos6502(unsigned char *memory, t_registers *registers) {

    // Set program counter to the power on reset location
    registers->program_counter = RESET_LOCATION_1;
    
    // Clear all other registers
    registers->register_x = 0;
    registers->register_y = 0;
    registers->accumulator = 0;
    registers->stack_pointer = 0;

    // Clear processor status bits
    registers->processor_status.carry_flag = 0;
    registers->processor_status.zero_flag = 0;
    registers->processor_status.interrupt_disable = 0;
    registers->processor_status.decimal_mode = 0;
    registers->processor_status.break_command = 0;
    registers->processor_status.overflow_flag = 0;
    registers->processor_status.negative_flag = 0;

    // Clear the zero page in memory
    for (int i = 0; i < ZERO_PAGE_SIZE; i++) {
        memory[i] = 0;
    }

    // Clear the stack
    for (int i = 0; i < STACK_SIZE; i++) {
        memory[STACK_BASE_ADDR + i] = 0;
    }
}

// -------------------------------------------------------------------------------------------------------------------------------
// Print the contents of the MOS 6502 registers
//   Inputs: Registers
// -------------------------------------------------------------------------------------------------------------------------------
extern void print_registers_mos6502(t_registers *registers) {
    printf("MOS 6502 Register Contents:\n");
    printf("\tProgram Counter:   %d\n", registers->program_counter);
    printf("\tRegister X:        %d\n", registers->register_x);
    printf("\tRegister Y:        %d\n", registers->register_y);
    printf("\tAccumulator:       %d\n", registers->accumulator);
    printf("\tStack Pointer:     %d\n", registers->stack_pointer);
    printf("\tCarry Flag:        %d\n", registers->processor_status.carry_flag);
    printf("\tZero Flag:         %d\n", registers->processor_status.zero_flag);
    printf("\tInterrupt Disable: %d\n", registers->processor_status.interrupt_disable);
    printf("\tDecimal Mode:      %d\n", registers->processor_status.decimal_mode);
    printf("\tBreak Command:     %d\n", registers->processor_status.break_command);
    printf("\tOverflow Flag:     %d\n", registers->processor_status.overflow_flag);
    printf("\tNegative Flag:     %d\n", registers->processor_status.negative_flag);
}

// -------------------------------------------------------------------------------------------------------------------------------
// Executes instructions
//   Inputs: Memory, Registers
// -------------------------------------------------------------------------------------------------------------------------------
extern void execute_mos6502(unsigned char *memory, t_registers *registers) {

    // Fetch instruction
    unsigned char instruction = fetch(memory, registers);

    // Execute
    switch (instruction) {

        case ADC_IMMEDIATE: {
            // Grab immediate value to be added
            signed char value = fetch(memory, registers);
            short sum = (short) (value + (signed char) registers->accumulator + (signed char) registers->processor_status.carry_flag);

        } break;

        case LDA_IMMEDIATE: {
            // Grab value to be stored
            unsigned char value = fetch(memory, registers);
            registers->accumulator = value;
            // Set processor status register bits
            set_negative_flag(registers, value);
            set_zero_flag(registers, value);
        } break;

        case LDA_ZERO_PAGE: {
            // Grab zero page address
            unsigned short address = (unsigned short) fetch(memory, registers);
            unsigned char value = read_memory(memory, registers, address, ZERO_PAGE);
            registers->accumulator = value;
            // Set processor status register bits
            set_negative_flag(registers, value);
            set_zero_flag(registers, value);
        } break;

        case LDA_ZERO_PAGE_X: {
            // Grab zero page address
            unsigned short address = (unsigned short) fetch(memory, registers);
            unsigned char value = read_memory(memory, registers, address, ZERO_PAGE_X);
            registers->accumulator = value;
            // Set processor status register bits
            set_negative_flag(registers, value);
            set_zero_flag(registers, value);
        } break;

        case LDA_ABSOLUTE: {
            // Calculate memory address
            unsigned short address_msb = (unsigned short) fetch(memory, registers);
            unsigned short address_lsb = (unsigned short) fetch(memory, registers);
            unsigned short address = (address_msb << 8) + address_lsb;
            // Read memory
            unsigned char value = read_memory(memory, registers, address, ABSOLUTE);
            registers->accumulator = value;
            // Set process status register bits
            set_negative_flag(registers, value);
            set_zero_flag(registers, value);
        } break;

        case LDA_ABSOLUTE_X: {
            // Calculate memory address
            unsigned short address_msb = (unsigned short) fetch(memory, registers);
            unsigned short address_lsb = (unsigned short) fetch(memory, registers);
            unsigned short address = (address_msb << 8) + address_lsb;
            // Read memory
            unsigned char value = read_memory(memory, registers, address, ABSOLUTE_X);
            registers->accumulator = value;
            // Set process status register bits
            set_negative_flag(registers, value);
            set_zero_flag(registers, value);
        } break;

        case LDA_ABSOLUTE_Y: {  
            // Calculate memory address
            unsigned short address_msb = (unsigned short) fetch(memory, registers);
            unsigned short address_lsb = (unsigned short) fetch(memory, registers);
            unsigned short address = (address_msb << 8) + address_lsb;
            // Read memory
            unsigned char value = read_memory(memory, registers, address, ABSOLUTE_Y);
            registers->accumulator = value;
            // Set process status register bits
            set_negative_flag(registers, value);
            set_zero_flag(registers, value);
        } break;
        
        case LDA_INDIRECT_X: {
            // Read memory
            unsigned short address = (unsigned short) fetch(memory, registers);
            unsigned char value = read_memory(memory, registers, address, INDEXED_INDIRECT);
            registers->accumulator = value;
            // Set process status register bits
            set_negative_flag(registers, value);
            set_zero_flag(registers, value);
        } break;

        case LDA_INDIRECT_Y: {
            // Read memory
            unsigned short address = (unsigned short) fetch(memory, registers);
            unsigned char value = read_memory(memory, registers, address, INDIRECT_INDEXED);
            registers->accumulator = value;
            // Set process status register bits
            set_negative_flag(registers, value);
            set_zero_flag(registers, value);
        } break;

        default:
            printf("Error: Instruction, %02hhX, not supported!!\n", (unsigned char) instruction);
    }
}

// -------------------------------------------------------------------------------------------------------------------------------
// Fetch instruction and increment program counter
//   Inputs: Memory, Registers
// -------------------------------------------------------------------------------------------------------------------------------
static unsigned char fetch(unsigned char *memory, t_registers *registers) {
    unsigned char instruction = memory[registers->program_counter];
    registers->program_counter++;
    return instruction;
}

// -------------------------------------------------------------------------------------------------------------------------------
// Reads zero page in memory
//   Inputs: Memory, Read Address
// -------------------------------------------------------------------------------------------------------------------------------
static unsigned char read_memory(unsigned char *memory, t_registers *registers, unsigned short address, t_memory_access access_type) {
        
    switch (access_type) {

        case ABSOLUTE:
        case ZERO_PAGE: {
            return memory[address];
        } break;

        case ZERO_PAGE_X: {
            address += (unsigned short) registers->register_x;
            if (address > 255) {
                // Need to wrap around if address ends up being greater than 255 so that we stay in the zero page
                address -= 255;
            }
            return memory[address];
        } break;

        case ABSOLUTE_X: {
            address += (unsigned short) registers->register_x;
            return memory[address];
        } break;

        case ABSOLUTE_Y: {
            address += (unsigned short) registers->register_y;
            return memory[address];
        } break;

        case INDEXED_INDIRECT: {
            // Calculate address of pointer 
            address += (unsigned short) registers->register_x;
            if (address > 255) {
                // Need to wrap around if address ends up being greater than 255 so that we stay in the zero page
                address -= 255;
            }
            // Grab pointer
            unsigned short pointer = (memory[address] << 8) + memory[address + 1];
            // Grab data
            return memory[pointer]; 
        } break;

        case INDIRECT_INDEXED: {
            // Grab pointer
            unsigned short pointer = (memory[address] << 8) + memory[address + 1];
            // Grab data
            return memory[pointer + registers->register_y];
        } break;

        default: {
            printf("ERROR: Memory access type, %d, does not exist!!", access_type);
        }
    }
}

// -------------------------------------------------------------------------------------------------------------------------------
// Sets the Zero Flag in the Processor Status Register
//   Inputs Register, Value
// -------------------------------------------------------------------------------------------------------------------------------
static void set_zero_flag(t_registers *registers, unsigned char value) {
    if (value == 0) {
        registers->processor_status.zero_flag = 1;
    } else {
        registers->processor_status.zero_flag = 0;
    }
}

// -------------------------------------------------------------------------------------------------------------------------------
// Sets the Negative Flag in the Processor Status Register
//   Inputs: Registers, Value
// -------------------------------------------------------------------------------------------------------------------------------
static void set_negative_flag(t_registers *registers, unsigned char value) {
    if ((value >> 7) == 1) {
        registers->processor_status.negative_flag = 1;
    } else {
        registers->processor_status.negative_flag = 0;
    }
}

// -------------------------------------------------------------------------------------------------------------------------------
// Sets the Carry Flag in the Processor Status Register
//   Inputs: Registers, 16 bit version of the arithmetic result
// -------------------------------------------------------------------------------------------------------------------------------
static void set_carry_flag(t_registers *registers, short value) {
    if (value > 127 || value < -128) {
        // Outside range of signed 8 bit value. Therefore, carry flag needs to be set.
        registers->processor_status.carry_flag = 1; 
    } else {
        registers->processor_status.carry_flag = 0;
    }
}
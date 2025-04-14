/* MIT License

Copyright (c) 2025 AlienAnomaly

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE. */

#include "machine.h"

// initializes all memory in the emulator.
void init_machine(machine_t* machine) {
    memset(machine->regs, 0, sizeof(machine->regs));
    memset(machine->ram, 0, sizeof(machine->ram));
    machine->i_reg = 0;
    machine->pc = 0x200;
    memset(machine->stack, 0, sizeof(machine->stack));
    machine->sp = 0;
    machine->dt = 0;
    machine->st = 0;
    memset(machine->keys, false, sizeof(machine->keys));
    memset(machine->display, false, sizeof(machine->display));
}

// fetches data from the ram to make up a 16-bit opcode, sets the 
// current opcode in the object, and returns to function caller.
uint16_t fetch_instruction(machine_t* machine) {
    uint8_t first = machine->ram[machine->pc];
    uint8_t second = machine->ram[machine->pc+1];

    uint16_t opcode = first;
    opcode <<= 8;
    opcode |= second;

    machine->cur_opcode = (opcode_t){ 
        .upper_half = first, 
        .lower_half = second, 
        .op = opcode 
    };

    machine->pc+=2;

    return opcode;
}

// Receives an opcode and decodes it by using either the first few digits of the opcode,
// or the last few digits, and calls the relevant emulated instruction implementation.
void decode_instruction(uint16_t opcode) {
    switch(opcode & 0xF000)
    {
        case 0x0:
        {
            printf("Opcode: %x\n", opcode);
        } break;

        case 0x6:
        {
            printf("Opcode: 0x6\n", opcode);
        } break;
    }
}

// main execution wrapper function
void execute_instruction(machine_t* machine) {
    uint16_t opcode = fetch_instruction(machine);
    decode_instruction(opcode);
}   

// loads a set of byte data into ram at location 0x200 (program counter).
void load_rom(machine_t* machine, const char* rom_path) {
    FILE* file = fopen(rom_path, "rb");
    if(!file) {
        printf("Failed to open path: %s\n", rom_path);
        exit(EXIT_FAILURE);
    }

    fseek(file, 0, SEEK_END);
    size_t file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    fread(machine->ram + machine->pc, file_size, sizeof(char), file);
    fclose(file);
}

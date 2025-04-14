
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

#pragma once

#include <inttypes.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define DISPLAY_SIZE 64*32

// #####################################################
//                       STRUCTS
// #####################################################
typedef struct {
    uint8_t lower_half;
    uint8_t upper_half;
    uint16_t op;
} opcode_t;

typedef struct {
    uint8_t regs[0xF];
    uint8_t ram[0x1000];
    uint16_t i_reg;
    uint16_t pc;
    uint16_t stack[0xF];
    uint8_t sp;
    uint8_t dt;
    uint8_t st;
    bool keys[0xF];
    bool display[DISPLAY_SIZE];
    opcode_t cur_opcode;
} machine_t;

// #####################################################
//                      FUNCTIONS
// #####################################################
void init_machine(machine_t* machine);
uint16_t fetch_instruction(machine_t* machine);
void decode_instruction(uint16_t opcode);
void execute_instruction(machine_t* machine);
void load_rom(machine_t* machine, const char* rom_path);

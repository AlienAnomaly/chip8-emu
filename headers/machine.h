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
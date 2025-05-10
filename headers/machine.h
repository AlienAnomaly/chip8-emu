#pragma once

#include <cstdint>

namespace chip8
{
    class Machine
    {
    public:
        Machine();
        ~Machine();
    public:
        uint8_t ram[0x1000];
        uint8_t regs[0xF];
        uint16_t stack[0xF];
        uint16_t pc;
        uint8_t sp;
        uint16_t i_reg;
        uint8_t dt;
        uint8_t st;
        bool keys[0xF];
        bool display[64*32];
        uint16_t opcode;
    public:
        void load_rom(const char* filepath);
        uint16_t fetch_opcode();
        void execute();
    };

    void reset_machine(Machine* machine, const char* rom_path);
    void init_machine(Machine* machine);
}
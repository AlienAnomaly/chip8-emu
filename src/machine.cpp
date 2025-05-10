#include "machine.h"

#include <iostream>
#include <cstring>

namespace chip8
{
    Machine::Machine()
    {

    }

    Machine::~Machine()
    {

    }

    void Machine::load_rom(const char* filepath)
    {   
        FILE* file = fopen(filepath, "rb");
        if(!file)
        {
            std::cout 
                << "Failed to open path: " 
                << filepath
                << "\n";
            
            exit(EXIT_FAILURE);
        }

        fseek(file, 0, SEEK_END);
        size_t size = ftell(file);
        rewind(file);
        memset(ram, 0, sizeof(ram));

        fread(&ram[0x200], sizeof(uint8_t), size, file);
        fclose(file);
    }

    uint16_t Machine::fetch_opcode()
    {
        uint8_t part_1 = ram[pc];
        uint8_t part_2 = ram[pc+1];
        uint16_t opcode = (part_1 << 8) | part_2;
        pc += 2;
        this->opcode = opcode;

        return opcode;
    }

    void Machine::execute()
    {
        switch(opcode & 0xF000)
        {
            // 00E0 && 00EE && 0NNN
            case 0x0:
            {
                switch(opcode & 0x000F) 
                {
                    case 0xE:
                    {

                    } break;

                    case 0x0:
                    {

                    } break;

                    // This default switch case will act as the 0NNN instruction.tg
                    default:
                    {

                    } break;
                }
            } break;

            // 1NNN
            case 0x1:
            {

            } break;

            // 2NNN
            case 0x2:
            {

            } break;
        }

        
    }

    // #######################################################
    //                  NON-MEMBER FUNCTIONS
    // #######################################################
    void reset_machine(Machine* machine, const char* rom_path) 
    {
        memset(machine->ram, 0, sizeof(machine->ram));
        memset(machine->regs, 0, sizeof(machine->regs));
        memset(machine->stack, 0, sizeof(machine->stack));
        machine->pc = machine->ram[0x200];
        machine->sp = 0;
        machine->i_reg = 0;
        machine->dt = 0;
        machine->st = 0;
        memset(machine->keys, false, sizeof(machine->keys));
        memset(machine->display, false, sizeof(machine->display));
        machine->load_rom(rom_path);
        machine->pc = machine->ram[0x200];
    }
}
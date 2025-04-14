#include "machine.h"
#include "sdl_context.h"

int main () {
    // create and initialize machine
    machine_t machine = {};
    init_machine(&machine);
    load_rom(&machine, "roms/ibm.ch8");

    // initialize sdl and create a window context
    sdl_context_t ctx = {};
    init_sdl(&ctx, "Game Window", 800, 600);

    // main program loop
    bool running = true;
    SDL_Event event;
    while(running) {   
        while(SDL_PollEvent(&event) != 0) {
            switch(event.type) 
            {   
                case SDL_EVENT_QUIT:
                {   
                    running = false;
                } break;
            }
        }

        if(machine.pc > sizeof(machine.ram)) {
            machine.pc = 0x200;
        }

        execute_instruction(&machine);
    }

    sdl_exit(&ctx);
}
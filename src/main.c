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
#include "sdl_context.h"
#include "update_context.h"

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

        clear_display(&ctx);
        update_display(&ctx);
    }

    sdl_exit(&ctx);
}

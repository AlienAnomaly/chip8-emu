#include <iostream>

#include "sdl_context.h"
#include "machine.h"

void poll_events(bool* running_state)
{
    SDL_Event event;
    
    while(SDL_PollEvent(&event) != 0)
    {
        switch(event.type)
        {   
            case SDL_EVENT_QUIT:
            {
                *running_state = false;
            } break;
        }
    }
}

void render(chip8::Context* context)
{
    SDL_RenderClear(&context->get_renderer());
    SDL_RenderPresent(&context->get_renderer());
}

int main(int argc, char* argv[]) 
{
    if(argc < 2)
    {
        std::cout 
            << "Usage: chip8 'rom path...'\n";

        exit(EXIT_FAILURE);
    } 
    else 
    {

        bool running = true;

        chip8::Context context("Chip8 Emulator", 800, 600);
        chip8::Machine machine;
        reset_machine(&machine, argv[1]);

        while(running)
        {
            poll_events(&running);
            render(&context);
        }
    }
}
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

void render()
{

}

int main(int argc, char* argv[]) 
{
    bool running = true;

    chip8::Context context("Chip8 Emulator", 800, 600);
    chip8::Machine machine;
    reset_machine(&machine, argv[1]);
    init_machine(&machine);

    while(running)
    {
        poll_events(&running);
    }
}
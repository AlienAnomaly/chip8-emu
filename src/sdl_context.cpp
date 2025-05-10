#include "sdl_context.h"

#include <cstdlib>

namespace chip8 
{
    SDL_Window* Context::window = nullptr;
    SDL_Renderer* Context::renderer = nullptr;

    Context::Context(const char* title, uint32_t width, uint32_t height)
    {   
        if(!init_context(title, width, height)) 
        {   
            exit(EXIT_FAILURE);
        }
    }

    Context::~Context()
    {
        SDL_DestroyRenderer(this->renderer);
        SDL_DestroyWindow(this->window);
        SDL_Quit();
    }

    bool Context::init_context(const char* title, uint32_t width, uint32_t height)
    {
        if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_EVENTS) < 0) 
        {
            return false;
        }

        this->window = SDL_CreateWindow (
            title,
            width,
            height,
            SDL_WINDOW_RESIZABLE
        );

        this->renderer = SDL_CreateRenderer (
            this->window,
            NULL
        );

        return true;
    }
}
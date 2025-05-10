#pragma once

#include <SDL3/SDL.h>

namespace chip8 
{
    class Context 
    {
    public:
        Context(const char* title, uint32_t width, uint32_t height);
        ~Context();
    private:
        static SDL_Window* window;
        static SDL_Renderer* renderer;
    private:
        bool init_context(const char* title, uint32_t width, uint32_t height);
    };
}
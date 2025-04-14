#pragma once

#include <SDL3/SDL.h>

typedef struct {
    SDL_Window* window;
    SDL_Renderer* renderer;
} sdl_context_t;

bool init_sdl(sdl_context_t* ctx, const char* title, uint32_t width, uint32_t height);
void sdl_exit(sdl_context_t* ctx);
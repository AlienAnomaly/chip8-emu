#include "sdl_context.h"

bool init_sdl(sdl_context_t* ctx, const char* title, uint32_t width, uint32_t height) {
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        return false;
    }

    ctx->window = SDL_CreateWindow(title, width, height, SDL_WINDOW_RESIZABLE);

    return true;
}   

void sdl_exit(sdl_context_t* ctx) {
    SDL_DestroyRenderer(ctx->renderer);
    SDL_DestroyWindow(ctx->window);
    SDL_Quit();
}
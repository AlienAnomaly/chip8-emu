#include "update_context.h"

void clear_display(sdl_context_t* ctx) {
	SDL_RenderClear(ctx->renderer);
}

void update_display(sdl_context_t* ctx) {
	SDL_RenderPresent(ctx->renderer);
}

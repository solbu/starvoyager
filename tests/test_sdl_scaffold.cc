/*
	test_sdl_scaffold.cc
	
	SDL testing scaffold implementation
*/

#include "test_sdl_scaffold.h"
#include <stdio.h>

bool SDLTestScaffold::sdl_initialized = false;
SDL_Surface* SDLTestScaffold::test_surface = nullptr;

bool SDLTestScaffold::init_sdl() {
	if (sdl_initialized) {
		return true;
	}
	
	// Initialize SDL with minimal video mode
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL init failed: %s\n", SDL_GetError());
		return false;
	}
	
	// Create a minimal test surface
	test_surface = SDL_SetVideoMode(640, 480, 16, SDL_SWSURFACE);
	if (!test_surface) {
		printf("SDL video mode failed: %s\n", SDL_GetError());
		SDL_Quit();
		return false;
	}
	
	sdl_initialized = true;
	return true;
}

void SDLTestScaffold::cleanup_sdl() {
	if (sdl_initialized) {
		if (test_surface) {
			SDL_FreeSurface(test_surface);
			test_surface = nullptr;
		}
		SDL_Quit();
		sdl_initialized = false;
	}
}

bool SDLTestScaffold::is_initialized() {
	return sdl_initialized;
}
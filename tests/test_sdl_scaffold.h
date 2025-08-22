/*
	test_sdl_scaffold.h
	
	SDL testing scaffold for GUI tests
*/

#ifndef TEST_SDL_SCAFFOLD_H
#define TEST_SDL_SCAFFOLD_H

#include <SDL.h>

class SDLTestScaffold {
public:
	static bool init_sdl();
	static void cleanup_sdl();
	static bool is_initialized();
	
private:
	static bool sdl_initialized;
	static SDL_Surface* test_surface;
};

#endif
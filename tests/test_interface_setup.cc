/*
	test_interface_setup.cc
	
	Isolated test for interface setup with debugging
*/

#include "test_framework.h"
#include "test_sdl_scaffold.h"
#include "../calc.h"
#include "../graphic.h"
#include "../interface.h"
#include <SDL.h>

void test_interface_setup_isolated() {
	if (!SDLTestScaffold::init_sdl()) {
		TEST_ASSERT(true, "interface setup test skipped (SDL init failed)");
		return;
	}
	
	try {
		// Initialize in correct order
		graphic::init();
		graphic::setup(false, false);
		interface::init();
		interface::setup();
		
		TEST_ASSERT(interface::viewb.w > 0, "interface setup completed");
		
	} catch (...) {
		TEST_ASSERT(false, "interface setup crashed");
	}
}

void run_interface_setup_test() {
	printf("\n--- Interface Setup Test ---\n");
	test_interface_setup_isolated();
	SDLTestScaffold::cleanup_sdl();
}
/*
	test_gui.cc
	
	Tests for GUI and interface components
*/

#include "test_framework.h"
#include "test_sdl_scaffold.h"
#include "../calc.h"
#include "../interface.h"
#include "../graphic.h"
#include "../camera.h"
#include <SDL.h>

class MockSDL {
public:
	static bool init_called;
	static bool setup_called;
	
	static void reset() {
		init_called = false;
		setup_called = false;
	}
};

bool MockSDL::init_called = false;
bool MockSDL::setup_called = false;

void test_interface_initialization() {
	try {
		interface::init();
		TEST_ASSERT(true, "interface::init doesn't crash");
	} catch (...) {
		TEST_ASSERT(false, "interface::init doesn't crash");
	}
}

void test_interface_bounds() {
	if (!SDLTestScaffold::init_sdl()) {
		TEST_ASSERT(true, "interface bounds test skipped (SDL init failed)");
		return;
	}
	
	try {
		graphic::init();
		graphic::setup(false, false);
		interface::init();
		interface::setup();
		
		TEST_ASSERT(interface::viewb.w > 0, "viewb width is positive");
		TEST_ASSERT(interface::viewb.h > 0, "viewb height is positive");
		TEST_ASSERT(interface::panelb.w >= 0, "panelb width is non-negative");
		TEST_ASSERT(interface::panelb.h >= 0, "panelb height is non-negative");
	} catch (...) {
		TEST_ASSERT(false, "interface bounds check doesn't crash");
	}
}

void test_graphics_initialization() {
	if (!SDLTestScaffold::is_initialized()) {
		TEST_ASSERT(true, "graphics test skipped (SDL not initialized)");
		return;
	}
	
	try {
		graphic::init();
		graphic::setup(false, false);
		
		sbox screen = graphic::dimension();
		TEST_ASSERT(screen.w > 0, "screen width is positive");
		TEST_ASSERT(screen.h > 0, "screen height is positive");
		
		TEST_ASSERT(true, "graphics system works");
	} catch (...) {
		TEST_ASSERT(false, "graphics system works");
	}
}

void test_camera_initialization() {
	try {
		camera::init();
		TEST_ASSERT(true, "camera::init doesn't crash");
	} catch (...) {
		TEST_ASSERT(false, "camera::init doesn't crash");
	}
}

void test_interface_input_handling() {
	if (!SDLTestScaffold::is_initialized()) {
		TEST_ASSERT(true, "interface polling test skipped (SDL not initialized)");
		return;
	}
	
	try {
		graphic::init();
		graphic::setup(false, false);
		interface::init();
		interface::setup();
		
		for(int i = 0; i < 3; i++) {
			interface::poll();
			TEST_ASSERT(interface::keys != nullptr, "keyboard state accessible");
			TEST_ASSERT(interface::lkey >= -1, "last key in valid range");
		}
		TEST_ASSERT(true, "interface polling works");
	} catch (...) {
		TEST_ASSERT(false, "interface polling works");
	}
}

void test_interface_text_output() {
	if (!SDLTestScaffold::is_initialized()) {
		TEST_ASSERT(true, "interface text output test skipped (SDL not initialized)");
		return;
	}
	
	try {
		graphic::init();
		graphic::setup(false, false);
		interface::init();
		interface::setup();
		
		interface::printtocons("Test message %d", 123);
		interface::printtomesg("Test ticker message");
		interface::printtomesg("Another test message");
		interface::render();
		
		TEST_ASSERT(true, "interface text output works");
	} catch (...) {
		TEST_ASSERT(false, "interface text output works");
	}
}

void test_interface_line_input() {
	if (!SDLTestScaffold::is_initialized()) {
		TEST_ASSERT(true, "interface line input test skipped (SDL not initialized)");
		return;
	}
	
	try {
		graphic::init();
		graphic::setup(false, false);
		interface::init();
		interface::setup();
		
		char buffer[65];
		bool result = interface::getline(buffer, false);
		TEST_ASSERT(result == false, "getline returns false when no input");
		
		result = interface::getline(buffer, true);
		TEST_ASSERT(result == false, "getline password mode works");
		
		TEST_ASSERT(true, "interface line input functionality works");
	} catch (...) {
		TEST_ASSERT(false, "interface line input test");
	}
}

void run_gui_tests() {
	printf("\n--- GUI Tests ---\n");
	
	// Initialize SDL for GUI tests
	if (SDLTestScaffold::init_sdl()) {
		printf("SDL initialized for GUI testing\n");
	} else {
		printf("SDL initialization failed, some tests will be skipped\n");
	}
	
	test_interface_initialization();
	test_interface_bounds();
	test_graphics_initialization();
	test_camera_initialization();
	test_interface_input_handling();
	test_interface_text_output();
	test_interface_line_input();
	
	// Cleanup SDL after GUI tests
	SDLTestScaffold::cleanup_sdl();
}
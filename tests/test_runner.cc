/*
	test_runner.cc
	
	Main test runner for Star Voyager automated testing
*/

#include "test_framework.h"
#include "test_sdl_scaffold.h"
#include <SDL.h>

// Test function declarations
void run_game_logic_tests();
void run_gui_tests();
void run_integration_tests();
void run_gameplay_tests();
void run_interface_setup_test();

int main(int argc, char* argv[]) {
	bool headless = false;
	bool quick = false;
	
	// Parse command line arguments
	for (int i = 1; i < argc; i++) {
		if (strcmp(argv[i], "--headless") == 0) {
			headless = true;
		} else if (strcmp(argv[i], "--quick") == 0) {
			quick = true;
		} else if (strcmp(argv[i], "--help") == 0) {
			printf("Star Voyager Test Runner\n");
			printf("Usage: %s [options]\n", argv[0]);
			printf("Options:\n");
			printf("  --headless  Run without GUI initialization\n");
			printf("  --quick     Run only critical tests\n");
			printf("  --help      Show this help\n");
			return 0;
		}
	}
	
	TestFramework::init();
	
	// SDL initialization is handled by individual test suites
	
	// Run test suites
	run_game_logic_tests();
	run_gameplay_tests();
	
	if (!headless) {
		run_gui_tests();
		run_interface_setup_test();
	}
	
	if (!quick) {
		run_integration_tests();
	}
	
	TestFramework::print_results();
	
	return TestFramework::get_failed_count() > 0 ? 1 : 0;
}
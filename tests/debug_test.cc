/*
	debug_test.cc
	
	Generic debug program for testing segfaults with GDB
*/

#include "test_framework.h"
#include "test_sdl_scaffold.h"
#include <stdio.h>
#include <string.h>

// Test function declarations
void run_game_logic_tests();
void run_gui_tests();
void run_integration_tests();
void run_gameplay_tests();
void run_interface_setup_test();

int main(int argc, char* argv[]) {
	char* test_name = "all";
	
	if (argc > 1) {
		test_name = argv[1];
	}
	
	printf("Starting debug session for: %s\n", test_name);
	TestFramework::init();
	
	try {
		if (strcmp(test_name, "logic") == 0) {
			run_game_logic_tests();
		} else if (strcmp(test_name, "gui") == 0) {
			run_gui_tests();
		} else if (strcmp(test_name, "integration") == 0) {
			run_integration_tests();
		} else if (strcmp(test_name, "gameplay") == 0) {
			run_gameplay_tests();
		} else if (strcmp(test_name, "interface") == 0) {
			run_interface_setup_test();
		} else {
			// Run all tests
			run_game_logic_tests();
			run_gameplay_tests();
			run_gui_tests();
			run_interface_setup_test();
			run_integration_tests();
		}
		
		TestFramework::print_results();
		return TestFramework::get_failed_count() > 0 ? 1 : 0;
		
	} catch (...) {
		printf("Exception caught during test execution\n");
		return 1;
	}
}
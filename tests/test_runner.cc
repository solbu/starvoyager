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
void run_equipment_refactoring_tests();
void run_ship_properties_tests();
void run_function_renames_tests();

// New regression test declarations
void run_batch1_core_structures_tests();
void run_batch2_equipment_alliance_tests();
void run_batch3_network_tests();
void run_batch4_graphics_tests();
void run_batch5_physics_tests();
void run_batch6_ai_logic_tests();
void run_batch7_database_tests();
void run_batch8_sound_error_tests();
void run_performance_benchmarks();
void run_memory_management_tests();
void run_error_path_tests();

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
	
	// Run existing test suites
	run_game_logic_tests();
	run_gameplay_tests();
	run_equipment_refactoring_tests();
	run_ship_properties_tests();
	run_function_renames_tests();
	
	// Run new regression test suites
	run_batch1_core_structures_tests();
	run_batch2_equipment_alliance_tests();
	run_batch3_network_tests();
	run_batch4_graphics_tests();
	run_batch5_physics_tests();
	run_batch6_ai_logic_tests();
	run_batch7_database_tests();
	run_batch8_sound_error_tests();
	run_memory_management_tests();
	run_error_path_tests();
	
	if (!headless) {
		run_gui_tests();
		run_interface_setup_test();
	}
	
	if (!quick) {
		run_integration_tests();
		run_performance_benchmarks();
	}
	
	TestFramework::print_results();
	
	return TestFramework::get_failed_count() > 0 ? 1 : 0;
}
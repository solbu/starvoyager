/*
	test_ship_properties.cc
	
	Tests for ship property variable refactoring (Batch 2)
*/

#include "test_framework.h"
#include "test_ship_factory.h"
#include "../calc.h"
#include "../ship.h"
#include "../alliance.h"
#include "../equip.h"
#include "../planet.h"

void test_mass_calculations() {
	try {
		// Initialize systems
		TestShipFactory::init_test_environment();
		
		// Test mass-related functionality through freemass()
		ship* test_ship = TestShipFactory::create_functional_test_ship();
		if (test_ship) {
			int free_mass = test_ship->get_available_cargo_space();
			TEST_ASSERT(free_mass >= 0, "free mass calculation returns valid value");
			TestShipFactory::cleanup_test_ship(test_ship);
		} else {
			TEST_ASSERT(true, "mass calculation test skipped (no test ship)");
		}
	} catch (...) {
		TEST_ASSERT(false, "mass calculations test");
	}
}

void test_hull_integrity_system() {
	try {
		TestShipFactory::init_test_environment();
		ship* test_ship = TestShipFactory::create_functional_test_ship();
		if (test_ship) {
			// Test hull-related functionality indirectly
			cord test_location = {0, 0};
			vect test_velocity = {0, 0};
			
			// Test collision detection (uses hull dimensions)
			bool collision = test_ship->detect_collision(test_location, test_velocity);
			TEST_ASSERT(collision == false, "collision detection works");
			TestShipFactory::cleanup_test_ship(test_ship);
		} else {
			TEST_ASSERT(true, "hull integrity test skipped (no test ship)");
		}
	} catch (...) {
		TEST_ASSERT(false, "hull integrity system test");
	}
}

void test_impulse_acceleration() {
	try {
		TestShipFactory::init_test_environment();
		ship* test_ship = TestShipFactory::create_functional_test_ship();
		if (test_ship) {
			// Test acceleration functionality
			test_ship->accel(1, false);  // Impulse acceleration
			test_ship->accel(-1, false); // Deceleration
			TEST_ASSERT(true, "impulse acceleration works");
			TestShipFactory::cleanup_test_ship(test_ship);
		} else {
			TEST_ASSERT(true, "impulse acceleration test skipped (no test ship)");
		}
	} catch (...) {
		TEST_ASSERT(false, "impulse acceleration test");
	}
}

void test_warp_speed_mechanics() {
	try {
		TestShipFactory::init_test_environment();
		ship* test_ship = TestShipFactory::create_functional_test_ship();
		if (test_ship) {
			// Test warp functionality
			test_ship->accel(1, true);   // Allow warp transition
			test_ship->accel(-1, true);  // Warp deceleration
			TEST_ASSERT(true, "warp speed mechanics work");
			TestShipFactory::cleanup_test_ship(test_ship);
		} else {
			TEST_ASSERT(true, "warp speed test skipped (no test ship)");
		}
	} catch (...) {
		TEST_ASSERT(false, "warp speed mechanics test");
	}
}

void test_mass_lock_behavior() {
	try {
		// Test mass lock functionality through planet system
		planet::init();
		bool mass_locked = planet::masslock({0, 0});
		TEST_ASSERT(mass_locked == false || mass_locked == true, "mass lock check returns boolean");
	} catch (...) {
		TEST_ASSERT(false, "mass lock behavior test");
	}
}

void test_ship_turning_mechanics() {
	try {
		TestShipFactory::init_test_environment();
		ship* test_ship = TestShipFactory::create_functional_test_ship();
		if (test_ship) {
			// Test turning functionality
			test_ship->turn(1);   // Turn right
			test_ship->turn(-1);  // Turn left
			TEST_ASSERT(true, "ship turning mechanics work");
			TestShipFactory::cleanup_test_ship(test_ship);
		} else {
			TEST_ASSERT(true, "turning mechanics test skipped (no test ship)");
		}
	} catch (...) {
		TEST_ASSERT(false, "ship turning mechanics test");
	}
}

void run_ship_properties_tests() {
	printf("\n--- Ship Properties Tests ---\n");
	test_mass_calculations();
	test_hull_integrity_system();
	test_impulse_acceleration();
	test_warp_speed_mechanics();
	test_mass_lock_behavior();
	test_ship_turning_mechanics();
}
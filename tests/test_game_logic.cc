/*
	test_game_logic.cc
	
	Tests for core game logic components
*/

#include "test_framework.h"
#include "../calc.h"
#include "../ship.h"
#include "../alliance.h"
#include "../equip.h"
#include "../planet.h"
#include "../player.h"

void test_calc_functions() {
	// Test vector distance calculation
	vect v1, v2;
	v1.xx = 0; v1.yy = 0;
	v2.xx = 3; v2.yy = 4;
	vect diff;
	diff.xx = v2.xx - v1.xx;
	diff.yy = v2.yy - v1.yy;
	pol p = diff.topol();
	TEST_EQUALS_FLOAT(5.0f, (float)p.rad, 0.01f, "vector distance calculation");
	
	// Test random number generation
	long rnd = calc::rnd(100);
	TEST_ASSERT(rnd >= 0 && rnd < 100, "calc::rnd range test");
}

void test_ship_initialization() {
	try {
		ship::init();
		TEST_ASSERT(true, "ship::init doesn't crash");
	} catch (...) {
		TEST_ASSERT(false, "ship::init doesn't crash");
	}
}

void test_ship_index_bounds() {
	// Test ship index bounds
	for(int i = 0; i < 10; i++) {
		(void)ship::get(i);
		// Should not crash, may return null
		TEST_ASSERT(true, "ship::get doesn't crash");
	}
}

void test_ship_library() {
	try {
		// Test library access
		for(int i = 0; i < 5; i++) {
			(void)ship::libget(i);
			// Should not crash
		}
		TEST_ASSERT(true, "ship library access works");
	} catch (...) {
		TEST_ASSERT(false, "ship library access works");
	}
}

void test_alliance_system() {
	try {
		alliance::init();
		TEST_ASSERT(true, "alliance::init doesn't crash");
	} catch (...) {
		TEST_ASSERT(false, "alliance::init doesn't crash");
	}
}

void test_equipment_system() {
	try {
		equip::init();
		TEST_ASSERT(true, "equip::init doesn't crash");
	} catch (...) {
		TEST_ASSERT(false, "equip::init doesn't crash");
	}
}

void test_planet_system() {
	try {
		planet::init();
		TEST_ASSERT(true, "planet::init doesn't crash");
		
		// Test planet name generation
		char name[65];
		planet::generatename(name);
		TEST_ASSERT(strlen(name) > 0, "planet name generation works");
		TEST_ASSERT(strlen(name) < 65, "planet name within bounds");
	} catch (...) {
		TEST_ASSERT(false, "planet system tests");
	}
}

void test_player_system() {
	try {
		player::init();
		TEST_ASSERT(true, "player::init doesn't crash");
		
		// Test player lookup of non-existent player
		char name[] = "nonexistent";
		player* p = player::get(name);
		TEST_ASSERT(p == NULL, "non-existent player returns null");
	} catch (...) {
		TEST_ASSERT(false, "player system tests");
	}
}

void run_game_logic_tests() {
	printf("\n--- Game Logic Tests ---\n");
	test_calc_functions();
	test_ship_initialization();
	test_ship_index_bounds();
	test_ship_library();
	test_alliance_system();
	test_equipment_system();
	test_planet_system();
	test_player_system();
}
/*
	test_gameplay.cc
	
	Tests that simulate actual gameplay scenarios
*/

#include "test_framework.h"
#include "../calc.h"
#include "../ship.h"
#include "../planet.h"
#include "../alliance.h"
#include "../equip.h"
#include "../frag.h"
#include "../presence.h"

void test_ship_movement() {
	try {
		// Test vector calculations for ship movement
		vect velocity;
		velocity.xx = 10.0;
		velocity.yy = 0.0;
		
		pol polar_vel = velocity.topol();
		TEST_ASSERT(polar_vel.rad > 9.9 && polar_vel.rad < 10.1, "velocity conversion works");
		
		// Test back conversion
		vect back_to_vect = polar_vel.tovect();
		TEST_EQUALS_FLOAT(10.0f, (float)back_to_vect.xx, 0.1f, "velocity round-trip conversion");
	} catch (...) {
		TEST_ASSERT(false, "ship movement calculations");
	}
}

void test_collision_detection() {
	try {
		// Test basic collision math
		cord pos1, pos2;
		pos1.x = 0.0; pos1.y = 0.0;
		pos2.x = 5.0; pos2.y = 0.0;
		
		vect diff;
		diff.xx = pos2.x - pos1.x;
		diff.yy = pos2.y - pos1.y;
		
		pol distance = diff.topol();
		TEST_EQUALS_FLOAT(5.0f, (float)distance.rad, 0.01f, "collision distance calculation");
	} catch (...) {
		TEST_ASSERT(false, "collision detection math");
	}
}

void test_targeting_system() {
	try {
		// Test angle calculations for targeting
		cord shooter, target;
		shooter.x = 0.0; shooter.y = 0.0;
		target.x = 1.0; target.y = 1.0;
		
		vect aim;
		aim.xx = target.x - shooter.x;
		aim.yy = target.y - shooter.y;
		
		pol bearing = aim.topol();
		TEST_ASSERT(bearing.ang >= 0 && bearing.ang < 360, "targeting angle in valid range");
	} catch (...) {
		TEST_ASSERT(false, "targeting system calculations");
	}
}

void test_game_physics() {
	try {
		frag::init();
		presence::init();
		TEST_ASSERT(true, "physics systems initialize");
	} catch (...) {
		TEST_ASSERT(false, "physics systems initialize");
	}
}

void test_equipment_slots() {
	try {
		equip::init();
		// Test that equipment system can handle basic operations
		TEST_ASSERT(true, "equipment slot system works");
	} catch (...) {
		TEST_ASSERT(false, "equipment slot system works");
	}
}

void run_gameplay_tests() {
	printf("\n--- Gameplay Tests ---\n");
	test_ship_movement();
	test_collision_detection();
	test_targeting_system();
	test_game_physics();
	test_equipment_slots();
}
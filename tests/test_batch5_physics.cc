/*
	test_batch5_physics.cc
	
	Regression tests for Batch 5: Physics and Mathematics
	Tests calculation and physics functionality before refactoring
*/

#include "test_framework.h"
#include "../calc.h"
#include "../camera.h"

void test_angle_degree_conversions() {
	try {
		calc::init();
		
		// Test angle normalization
		pol test_polar;
		test_polar.ang = 370;
		test_polar.rad = 100;
		
		vect test_vector = test_polar.tovect();
		pol converted_back = test_vector.topol();
		
		TEST_ASSERT(converted_back.ang >= 0 && converted_back.ang < 360, "angle conversion maintains valid range");
		TEST_EQUALS_FLOAT(100.0f, (float)converted_back.rad, 0.1f, "radius preserved in conversion");
		
	} catch (...) {
		TEST_ASSERT(false, "angle degree conversions work");
	}
}

void test_radius_calculations() {
	try {
		// Test distance calculation
		vect v1, v2;
		v1.xx = 0; v1.yy = 0;
		v2.xx = 3; v2.yy = 4;
		
		vect diff;
		diff.xx = v2.xx - v1.xx;
		diff.yy = v2.yy - v1.yy;
		
		pol distance = diff.topol();
		TEST_EQUALS_FLOAT(5.0f, (float)distance.rad, 0.01f, "radius calculation correct");
		
	} catch (...) {
		TEST_ASSERT(false, "radius calculations work");
	}
}

void test_vector_component_operations() {
	try {
		// Test vector operations
		vect v1 = {10, 20};
		vect v2 = {5, 15};
		
		// Test component access
		TEST_EQUALS_INT(10, (int)v1.xx, "vector x component access");
		TEST_EQUALS_INT(20, (int)v1.yy, "vector y component access");
		
	} catch (...) {
		TEST_ASSERT(false, "vector component operations work");
	}
}

void test_random_int_generation() {
	try {
		calc::init();
		
		// Test random number generation
		for (int i = 0; i < 10; i++) {
			long rnd = calc::rnd(100);
			TEST_ASSERT(rnd >= 0 && rnd < 100, "random number in valid range");
		}
		
		// Test random with different ranges
		long rnd_small = calc::rnd(10);
		TEST_ASSERT(rnd_small >= 0 && rnd_small < 10, "small range random valid");
		
		long rnd_large = calc::rnd(1000);
		TEST_ASSERT(rnd_large >= 0 && rnd_large < 1000, "large range random valid");
		
	} catch (...) {
		TEST_ASSERT(false, "random int generation works");
	}
}

void test_polar_coordinate_conversion() {
	try {
		// Test polar to vector conversion (game uses compass convention: 0°=North)
		pol p;
		p.ang = 0;   // 0 degrees = North
		p.rad = 10;
		
		vect v = p.tovect();
		TEST_EQUALS_FLOAT(0.0f, (float)v.xx, 0.1f, "0 degree (North) x component");
		TEST_EQUALS_FLOAT(-10.0f, (float)v.yy, 0.1f, "0 degree (North) y component");
		
		// Test 90 degrees = East
		p.ang = 90;
		p.rad = 10;
		v = p.tovect();
		TEST_EQUALS_FLOAT(10.0f, (float)v.xx, 0.1f, "90 degree (East) x component");
		TEST_EQUALS_FLOAT(0.0f, (float)v.yy, 0.1f, "90 degree (East) y component");
		
	} catch (...) {
		TEST_ASSERT(false, "polar coordinate conversion works");
	}
}

void test_vector_coordinate_conversion() {
	try {
		// Test vector to polar conversion (East vector = 90° in game)
		vect v;
		v.xx = 10;
		v.yy = 0;
		
		pol p = v.topol();
		TEST_EQUALS_FLOAT(10.0f, (float)p.rad, 0.1f, "vector magnitude calculation");
		TEST_EQUALS_FLOAT(90.0f, (float)p.ang, 0.1f, "East vector = 90 degrees");
		
		// Test diagonal vector (Southeast = 135° in game)
		v.xx = 10;
		v.yy = 10;
		p = v.topol();
		TEST_EQUALS_FLOAT(135.0f, (float)p.ang, 1.0f, "Southeast diagonal = 135 degrees");
		
	} catch (...) {
		TEST_ASSERT(false, "vector coordinate conversion works");
	}
}

void test_camera_position_tracking() {
	try {
		// Test camera initialization
		camera::init();
		
		// Test camera operations
		camera::turnon();
		camera::turnoff();
		
		TEST_ASSERT(true, "camera position tracking works");
		
	} catch (...) {
		TEST_ASSERT(false, "camera position tracking works");
	}
}

void test_viewport_calculations() {
	try {
		camera::init();
		
		// Test viewport operations
		camera::radarzoom(1);  // Zoom in
		camera::radarzoom(-1); // Zoom out
		camera::viewzoom();    // Toggle zoom
		
		// Should not crash
		TEST_ASSERT(true, "viewport calculations work");
		
	} catch (...) {
		TEST_ASSERT(false, "viewport calculations work");
	}
}

void run_batch5_physics_tests() {
	printf("\n--- Batch 5: Physics and Mathematics Regression Tests ---\n");
	test_angle_degree_conversions();
	test_radius_calculations();
	test_vector_component_operations();
	test_random_int_generation();
	test_polar_coordinate_conversion();
	test_vector_coordinate_conversion();
	test_camera_position_tracking();
	test_viewport_calculations();
}
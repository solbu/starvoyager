/*
	test_framework.h
	
	Minimal testing framework for Star Voyager
	Provides automated regression testing for GUI and game logic
*/

#ifndef TEST_FRAMEWORK_H
#define TEST_FRAMEWORK_H

#include <stdio.h>
#include <string.h>

class TestFramework {
public:
	static void init();
	static void run_all_tests();
	static void assert_true(bool condition, const char* test_name);
	static void assert_equals(int expected, int actual, const char* test_name);
	static void assert_equals(float expected, float actual, float tolerance, const char* test_name);
	static void print_results();
	static int get_failed_count();

private:
	static int total_tests;
	static int passed_tests;
	static int failed_tests;
	static int skipped_tests;
	static char last_failure[256];
};

// Test macros for convenience
#define TEST_ASSERT(condition, name) TestFramework::assert_true(condition, name)
#define TEST_EQUALS_INT(expected, actual, name) TestFramework::assert_equals(expected, actual, name)
#define TEST_EQUALS_FLOAT(expected, actual, tolerance, name) TestFramework::assert_equals(expected, actual, tolerance, name)

#endif
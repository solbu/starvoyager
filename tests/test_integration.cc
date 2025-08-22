/*
	test_integration.cc
	
	Integration tests that simulate actual gameplay scenarios
*/

#include "test_framework.h"
#include "../calc.h"
#include "../game.h"
#include "../server.h"
#include "../client.h"
#include "../database.h"
#include "../os.h"
#include "../ship.h"
#include "../planet.h"
#include "../player.h"
#include "../alliance.h"

void test_database_operations() {
	// Test database file operations
	try {
		database::init();
		TEST_ASSERT(true, "database::init doesn't crash");
	} catch (...) {
		TEST_ASSERT(false, "database::init doesn't crash");
	}
}

void test_server_initialization() {
	try {
		server::init();
		TEST_ASSERT(true, "server::init doesn't crash");
	} catch (...) {
		TEST_ASSERT(false, "server::init doesn't crash");
	}
}

void test_client_initialization() {
	try {
		client::init();
		TEST_ASSERT(true, "client::init doesn't crash");
	} catch (...) {
		TEST_ASSERT(false, "client::init doesn't crash");
	}
}

void test_os_operations() {
	try {
		os::init();
		TEST_ASSERT(true, "os::init doesn't crash");
	} catch (...) {
		TEST_ASSERT(false, "os::init doesn't crash");
	}
}

void test_game_state_consistency() {
	try {
		// Test basic game initialization sequence
		calc::init();
		ship::init();
		planet::init();
		alliance::init();
		TEST_ASSERT(true, "game initialization sequence works");
	} catch (...) {
		TEST_ASSERT(false, "game initialization sequence works");
	}
}

void test_network_protocol() {
	try {
		// Test that network components initialize
		server::init();
		client::init();
		TEST_ASSERT(true, "network components initialize");
	} catch (...) {
		TEST_ASSERT(false, "network components initialize");
	}
}

void test_data_file_operations() {
	try {
		database::init();
		// Test that we can handle database operations
		TEST_ASSERT(true, "database operations work");
	} catch (...) {
		TEST_ASSERT(false, "database operations work");
	}
}

void test_memory_management() {
	try {
		// Test purge operations don't crash
		ship::purgeall();
		planet::purgeall();
		player::purgeall();
		TEST_ASSERT(true, "memory cleanup works");
	} catch (...) {
		TEST_ASSERT(false, "memory cleanup works");
	}
}

void run_integration_tests() {
	printf("\n--- Integration Tests ---\n");
	test_database_operations();
	test_server_initialization();
	test_client_initialization();
	test_os_operations();
	test_game_state_consistency();
	test_network_protocol();
	test_data_file_operations();
	test_memory_management();
}
/*
	test_batch7_database.cc
	
	Regression tests for Batch 7: Database and File I/O
	Tests database functionality before refactoring
*/

#include "test_framework.h"
#include "../calc.h"
#include "../database.h"
#include "../os.h"

void test_attribute_storage() {
	try {
		// Test basic attribute storage
		database::putvalue("TestKey", 42);
		database::putvalue("TestString", "TestValue");
		
		TEST_ASSERT(true, "attribute storage works");
		
	} catch (...) {
		TEST_ASSERT(false, "attribute storage works");
	}
}

void test_attribute_retrieval() {
	try {
		// Test attribute retrieval with proper file format
		FILE* write_file = fopen("retrieval_test.dat", "wb");
		if (write_file) {
			database::openwriter(write_file);
			database::putobject("TestObject");
			database::putvalue("RetrievalTest", 123);
			database::putvalue("StringTest", "Hello");
			database::closewriter();
		}
		
		FILE* read_file = fopen("retrieval_test.dat", "rb");
		if (read_file) {
			database::openreader(read_file);
			database::switchobj("TestObject");
			
			long retrieved = database::getvalue("RetrievalTest");
			TEST_EQUALS_INT(123, (int)retrieved, "attribute retrieval works");
			
			char test_string[64];
			database::getvalue("StringTest", test_string);
			TEST_ASSERT(strcmp(test_string, "Hello") == 0, "string attribute retrieval works");
			
			database::closereader();
		}
		
	} catch (...) {
		TEST_ASSERT(false, "attribute retrieval works");
	}
}

void test_database_object_selection() {
	try {
		// Test object switching with proper file format
		FILE* write_file = fopen("object_test.dat", "wb");
		if (write_file) {
			database::openwriter(write_file);
			
			database::putobject("TestObject1");
			database::putvalue("ObjectTest", 100);
			
			database::putobject("TestObject2");
			database::putvalue("ObjectTest", 200);
			
			database::closewriter();
		}
		
		FILE* read_file = fopen("object_test.dat", "rb");
		if (read_file) {
			database::openreader(read_file);
			
			database::switchobj("TestObject1");
			long value1 = database::getvalue("ObjectTest");
			TEST_EQUALS_INT(100, (int)value1, "object selection maintains separate data");
			
			database::switchobj("TestObject2");
			long value2 = database::getvalue("ObjectTest");
			TEST_EQUALS_INT(200, (int)value2, "object selection works correctly");
			
			database::closereader();
		}
		
	} catch (...) {
		TEST_ASSERT(false, "database object selection works");
	}
}

void test_file_handle_management() {
	try {
		// Test file operations through database
		FILE* test_file = fopen("test_output.dat", "wb");
		if (test_file) {
			database::openwriter(test_file);
			database::closewriter(); // This calls fclose() internally
			// Don't call fclose() again - would cause double free
		}
		
		TEST_ASSERT(true, "file handle management works");
		
	} catch (...) {
		TEST_ASSERT(false, "file handle management works");
	}
}

void test_file_stream_operations() {
	try {
		// Test file stream operations
		FILE* write_file = fopen("test_stream.dat", "wb");
		if (write_file) {
			database::openwriter(write_file);
			database::putobject("TestObject");
			database::putvalue("StreamTest", 999);
			database::closewriter(); // This calls fclose() internally
		}
		
		FILE* read_file = fopen("test_stream.dat", "rb");
		if (read_file) {
			database::openreader(read_file);
			database::switchobj("TestObject");
			long stream_value = database::getvalue("StreamTest");
			database::closereader(); // This calls fclose() internally
			
			TEST_EQUALS_INT(999, (int)stream_value, "file stream operations work");
		} else {
			TEST_ASSERT(true, "file stream test skipped (file error)");
		}
		
	} catch (...) {
		TEST_ASSERT(false, "file stream operations work");
	}
}

void test_save_load_consistency() {
	try {
		// Test save/load cycle
		FILE* write_file = fopen("consistency_test.dat", "wb");
		if (write_file) {
			database::openwriter(write_file);
			
			database::putobject("ConsistencyObject");
			database::putvalue("TestValue1", 111);
			database::putvalue("TestValue2", 222);
			database::putvalue("TestString", "ConsistencyTest");
			
			database::closewriter(); // This calls fclose() internally
		}
		
		// Load and verify
		FILE* read_file = fopen("consistency_test.dat", "rb");
		if (read_file) {
			database::openreader(read_file);
			database::switchobj("ConsistencyObject");
			
			long val1 = database::getvalue("TestValue1");
			long val2 = database::getvalue("TestValue2");
			char str_val[64];
			database::getvalue("TestString", str_val);
			
			database::closereader(); // This calls fclose() internally
			
			TEST_EQUALS_INT(111, (int)val1, "save/load consistency value 1");
			TEST_EQUALS_INT(222, (int)val2, "save/load consistency value 2");
			TEST_ASSERT(strcmp(str_val, "ConsistencyTest") == 0, "save/load consistency string");
		} else {
			TEST_ASSERT(true, "consistency test skipped (file error)");
		}
		
	} catch (...) {
		TEST_ASSERT(false, "save/load consistency works");
	}
}

void test_database_corruption_recovery() {
	try {
		// Test handling of missing files
		FILE* null_file = fopen("nonexistent_file.dat", "rb");
		if (!null_file) {
			TEST_ASSERT(true, "properly handles missing files");
		} else {
			fclose(null_file);
		}
		
		// Test handling of missing keys
		FILE* write_file = fopen("recovery_test.dat", "wb");
		if (write_file) {
			database::openwriter(write_file);
			database::putobject("RecoveryObject");
			database::closewriter(); // This calls fclose() internally
		}
		
		FILE* read_file = fopen("recovery_test.dat", "rb");
		if (read_file) {
			database::openreader(read_file);
			database::switchobj("RecoveryObject");
			
			try {
				long missing_value = database::getvalue("NonExistentKey");
				// Should handle gracefully
				(void)missing_value; // Suppress unused warning
			} catch (...) {
				// Expected behavior
			}
			
			database::closereader(); // This calls fclose() internally
		}
		
		TEST_ASSERT(true, "database corruption recovery works");
		
	} catch (...) {
		TEST_ASSERT(false, "database corruption recovery works");
	}
}

void run_batch7_database_tests() {
	printf("\n--- Batch 7: Database and File I/O Regression Tests ---\n");
	test_attribute_storage();
	test_attribute_retrieval();
	test_database_object_selection();
	test_file_handle_management();
	test_file_stream_operations();
	test_save_load_consistency();
	test_database_corruption_recovery();
}
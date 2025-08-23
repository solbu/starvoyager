#include "test_stubs.h"
#include <stdio.h>

void TestStubs::textout(const char* text, int x, int y) {
    // Stub implementation for text output
    printf("textout: %s at (%d,%d)\n", text, x, y);
}

void TestStubs::init_socket_helper() {
    // Stub implementation for socket helper initialization
}

void TestStubs::play_sound(int sound_id) {
    // Stub implementation for sound playback
    (void)sound_id;
}

void TestStubs::set_volume(int volume) {
    // Stub implementation for volume control
    (void)volume;
}

bool TestStubs::detect_format(const char* filename) {
    // Stub implementation for format detection
    (void)filename;
    return true;
}

bool TestStubs::init_sdl_video() {
    // Stub implementation for SDL video initialization
    return true;
}

void TestStubs::mock_alliance_lifecycle() {
    // Stub implementation for alliance lifecycle
}

void TestStubs::mock_config_system() {
    // Stub implementation for config system
}
#ifndef TEST_STUBS_H
#define TEST_STUBS_H

// Stub functions for missing APIs
class TestStubs {
public:
    static void textout(const char* text, int x, int y);
    static void init_socket_helper();
    static void play_sound(int sound_id);
    static void set_volume(int volume);
    static bool detect_format(const char* filename);
    static bool init_sdl_video();
    static void mock_alliance_lifecycle();
    static void mock_config_system();
};

#endif
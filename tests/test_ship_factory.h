#ifndef TEST_SHIP_FACTORY_H
#define TEST_SHIP_FACTORY_H

// Forward declarations
class ship;
class alliance;

class TestShipFactory {
public:
    static ship* create_test_ship();
    static ship* create_functional_test_ship();
    static alliance* create_test_alliance();
    static void cleanup_test_ship(ship* test_ship);
    static void init_test_environment();
    static void setup_ship_equipment(ship* test_ship);
    static void setup_ship_library();
};

#endif
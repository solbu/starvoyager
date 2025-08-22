# Generic Test Debugging

## Quick Debug Session

To debug any test segfault:

```bash
cd tests
make gdb-debug
```

## Debug Specific Test Categories

```bash
# Debug specific test suite
./debug-test logic      # Game logic tests only
./debug-test gui        # GUI tests only  
./debug-test integration # Integration tests only
./debug-test gameplay   # Gameplay tests only
./debug-test interface  # Interface setup test only
./debug-test           # All tests (default)
```

## GDB Commands

Once in GDB:
```gdb
(gdb) run gui                    # Run specific test suite
(gdb) break TestFramework::assert_true
(gdb) break function_name
(gdb) step
(gdb) bt
(gdb) info registers
(gdb) print variable_name
```

## Manual Debug Build

```bash
make debug-test
./debug-test gui
```

## Common Crash Points

- **GUI Tests**: Missing graphics setup
- **Integration Tests**: Uninitialized systems
- **Gameplay Tests**: Physics calculations
- **Logic Tests**: Array bounds, null pointers
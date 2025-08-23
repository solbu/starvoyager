# Star Voyager Test Suite

Automated regression testing framework for Star Voyager to catch issues that manifest during gameplay and user interface interactions.

## Features

- **Game Logic Tests**: Core calculations, ship mechanics, alliances
- **GUI Tests**: Interface initialization, bounds checking, graphics
- **Integration Tests**: Database operations, client/server functionality
- **Headless Mode**: Run tests without GUI for CI/CD pipelines
- **Quick Mode**: Run only critical tests for fast feedback

## Building Tests

```bash
cd tests
make
```

**Note**: For debug test options, ensure `gdb` is installed:
```bash
# Debian/Ubuntu
sudo apt install gdb
```

## Running Tests

### Full Test Suite
```bash
make test
```

### Headless Mode (no GUI)
```bash
make test-headless
```

### Quick Tests Only
```bash
make test-quick
```

### Manual Execution
```bash
./starvoyager-tests [options]

Options:
  --headless  Run without GUI initialization
  --quick     Run only critical tests
  --help      Show help
```

## Test Categories

### Game Logic Tests
- Mathematical calculations (distance, angles)
- Ship system initialization
- Alliance system functionality
- Equipment system integrity

### GUI Tests
- Interface component initialization
- Screen bounds validation
- Graphics system startup
- Camera system setup

### Integration Tests
- Database file operations
- Network client/server initialization
- OS-specific functionality
- Game state consistency

## Adding New Tests

1. Add test functions to appropriate test file:
   - `test_game_logic.cc` - Core game mechanics
   - `test_gui.cc` - User interface components
   - `test_integration.cc` - System integration

2. Use test macros:
   ```cpp
   TEST_ASSERT(condition, "test description");
   TEST_EQUALS_INT(expected, actual, "test description");
   TEST_EQUALS_FLOAT(expected, actual, tolerance, "test description");
   ```

3. Add function call to appropriate `run_*_tests()` function

## CI/CD Integration

The test suite returns exit code 0 on success, 1 on failure, making it suitable for automated build systems:

```bash
# In your CI script
cd tests
make test-headless
if [ $? -ne 0 ]; then
    echo "Tests failed!"
    exit 1
fi
```

## Regression Testing Workflow

1. **Before Changes**: Run full test suite to establish baseline
2. **During Development**: Use quick tests for rapid feedback
3. **Before Commit**: Run full test suite to catch regressions
4. **CI Pipeline**: Automated headless testing on commits

## Common Issues

- **SDL Initialization Fails**: Tests automatically fall back to headless mode
- **Missing Data Files**: Some tests may fail if game data files are missing
- **Build Dependencies**: Ensure parent project builds successfully first

## Future Enhancements

- Mock SDL events for automated GUI interaction testing
- Performance benchmarking tests
- Memory leak detection
- Network protocol validation tests
- Save/load game state verification
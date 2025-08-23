PREFIX=$(DESTDIR)/usr
DATADIR=$(PREFIX)/share/games/starvoyager
NAME=starvoyager-tests
VERSION=0.5.0

CPPC=c++
CC=cc
UNAME := $(shell uname -m)
ifeq ($(UNAME), x86_64)
	LIBS:=`sdl-config --libs` -lSDL_net -lstdc++ -lm
else
	LIBS:=`sdl-config --libs` -lSDL_net -lstdc++
endif
CFLAGS:=`sdl-config --cflags` -Wall -ggdb3 -I..
ifneq (,$(findstring noopt,$(DEB_BUILD_OPTIONS)))
CFLAGS += -O0
else
CFLAGS += -O2
endif

# Automatic dependency generation
DEPDIR := .deps
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.d

.SUFFIXES: .c .cc
.PHONY: all clean test test-headless test-quick debug-interface gdb-debug check distclean

all: $(NAME)

# Test runner linking
$(NAME): test_runner.o test_framework.o test_sdl_scaffold.o test_ship_factory.o test_stubs.o test_game_logic.o test_gui.o test_integration.o test_gameplay.o test_interface_setup.o test_equipment_refactoring.o test_ship_properties.o test_function_renames.o test_batch1_core_structures.o test_batch2_equipment_alliance.o test_batch3_network.o test_batch4_graphics.o test_batch5_physics.o test_batch6_ai_logic.o test_batch7_database.o test_batch8_sound_error.o test_performance_benchmarks.o test_memory_management.o test_error_paths.o ../alliance.o ../calc.o ../camera.o ../database.o ../error.o ../equip.o ../graphic.o ../interface.o ../os.o ../server.o ../client.o ../ship.o ../sound.o ../ticker.o ../planet.o ../player.o ../presence.o ../frag.o ../sockhelper.o ../SDL_rotozoom.o ../SDL_gfxPrimitives.o ../SDL_gfxBlitFunc.o
	$(CC) -o $(NAME) $^ $(LIBS)

.cc.o:
	@mkdir -p $(DEPDIR)
	$(CPPC) $(DEPFLAGS) $(CFLAGS) -DPOSIX -DVERSION=\"${VERSION}\" -DDATADIR=\"${DATADIR}\" -c -o $@ $<

# Test targets
test: $(NAME)
	./$(NAME)

test-headless: $(NAME)
	./$(NAME) --headless

test-quick: $(NAME)
	./$(NAME) --quick

# Coverage testing
test-coverage: CFLAGS += --coverage
test-coverage: $(NAME)
	./$(NAME)
	gcov *.cc
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory coverage_html

test-regression: $(NAME)
	./$(NAME) --headless

# Debug test with all current test modules
debug-test: CFLAGS += -O0 -ggdb3
debug-test: test_runner.o test_framework.o test_sdl_scaffold.o test_ship_factory.o test_stubs.o test_game_logic.o test_gui.o test_integration.o test_gameplay.o test_interface_setup.o test_equipment_refactoring.o test_ship_properties.o test_function_renames.o test_batch1_core_structures.o test_batch2_equipment_alliance.o test_batch3_network.o test_batch4_graphics.o test_batch5_physics.o test_batch6_ai_logic.o test_batch7_database.o test_batch8_sound_error.o test_performance_benchmarks.o test_memory_management.o test_error_paths.o ../alliance.o ../calc.o ../camera.o ../database.o ../error.o ../equip.o ../graphic.o ../interface.o ../os.o ../server.o ../client.o ../ship.o ../sound.o ../ticker.o ../planet.o ../player.o ../presence.o ../frag.o ../sockhelper.o ../SDL_rotozoom.o ../SDL_gfxPrimitives.o ../SDL_gfxBlitFunc.o
	$(CC) -o debug-test $^ $(LIBS)

# GDB debug with malloc checking and backtrace on crash
gdb-debug: debug-test
	gdb -ex "set environment MALLOC_CHECK_=2" -ex "set environment MALLOC_PERTURB_=1" -ex "run" -ex "bt" -ex "quit" ./debug-test

# Interactive GDB debug session
gdb-interactive: debug-test
	gdb ./debug-test

# Clean
clean:
	rm -f *.o
	rm -f *.gcno *.gcda
	rm -f *~
	rm -f *.log
	rm -f *.dat
	rm -f $(NAME)
	rm -f debug-test

check: test

distclean: clean
	rm -rf $(DEPDIR)

# Ensure parent objects are built
../%.o: ../*.cc ../*.h
	$(MAKE) -C .. $*.o

# Include automatic dependencies
include $(wildcard $(DEPDIR)/*.d)
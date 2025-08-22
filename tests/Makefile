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
$(NAME): test_runner.o test_framework.o test_sdl_scaffold.o test_game_logic.o test_gui.o test_integration.o test_gameplay.o test_interface_setup.o test_equipment_refactoring.o test_ship_properties.o test_function_renames.o ../alliance.o ../calc.o ../camera.o ../database.o ../error.o ../equip.o ../graphic.o ../interface.o ../os.o ../server.o ../client.o ../ship.o ../sound.o ../ticker.o ../planet.o ../player.o ../presence.o ../frag.o ../sockhelper.o ../SDL_rotozoom.o ../SDL_gfxPrimitives.o ../SDL_gfxBlitFunc.o
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

# Generic debug test
debug-test: debug_test.o test_framework.o test_sdl_scaffold.o test_game_logic.o test_integration.o test_gameplay.o test_interface_setup.o test_equipment_refactoring.o test_ship_properties.o test_function_renames.o ../alliance.o ../calc.o ../camera.o ../database.o ../error.o ../equip.o ../graphic.o ../interface.o ../os.o ../server.o ../client.o ../ship.o ../sound.o ../ticker.o ../planet.o ../player.o ../presence.o ../frag.o ../sockhelper.o ../SDL_rotozoom.o ../SDL_gfxPrimitives.o ../SDL_gfxBlitFunc.o
	$(CC) -o debug-test $^ $(LIBS)

gdb-debug: debug-test
	gdb ./debug-test

# Clean
clean:
	rm -f *.o
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
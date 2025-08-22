PREFIX=$(DESTDIR)/usr
DATADIR=$(PREFIX)/share/games/starvoyager
DOCDIR=$(PREFIX)/share/doc/starvoyager
BINDIR=$(PREFIX)/games
NAME=starvoyager
VERSION=0.5.0

CPPC=c++
CC=cc
UNAME := $(shell uname -m)
ifeq ($(UNAME), x86_64)
	LIBS:=`sdl-config --libs` -lSDL_net -lstdc++ -lm
else
	LIBS:=`sdl-config --libs` -lSDL_net -lstdc++
endif
CFLAGS:=`sdl-config --cflags` -Wall -ggdb3
ifneq (,$(findstring noopt,$(DEB_BUILD_OPTIONS)))
CFLAGS += -O0
else
CFLAGS += -O2
endif
#CFLAGS:=`sdl-config --cflags` -ggdb3 -Wall -Werror -ansi -pedantic
PACKAGENAME=$(NAME)-$(VERSION)-`uname -m`-`uname|tr [A-Z] [a-z]`.bin

# Automatic dependency generation
DEPDIR := .deps
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.d

.SUFFIXES: .c .cc
.PHONY: all clean install install-data install-bin uninstall binary dist test test-headless test-quick check distclean

all: starvoyager

#Linking
starvoyager: alliance.o camera.o database.o error.o game.o interface.o presence.o ship.o sound.o ticker.o calc.o client.o equip.o frag.o graphic.o planet.o server.o sockhelper.o sv.o player.o os.o SDL_rotozoom.o SDL_gfxPrimitives.o SDL_gfxBlitFunc.o
	$(CC) -o $(NAME) $^ $(LIBS)

#Include dependencies
# More specific dependency rules would go here if needed

#Compiling SDL_gfx files without warnings
SDL_rotozoom.o: SDL_rotozoom.c
	$(CC) `sdl-config --cflags` -w -c -o SDL_rotozoom.o SDL_rotozoom.c

SDL_gfxPrimitives.o: SDL_gfxPrimitives.c
	$(CC) `sdl-config --cflags` -w -c -o SDL_gfxPrimitives.o SDL_gfxPrimitives.c

SDL_gfxBlitFunc.o: SDL_gfxBlitFunc.c
	$(CC) `sdl-config --cflags` -w -c -o SDL_gfxBlitFunc.o SDL_gfxBlitFunc.c

.cc.o:
	@mkdir -p $(DEPDIR)
	$(CPPC) $(DEPFLAGS) $(CFLAGS) -DPOSIX -DVERSION=\"${VERSION}\" -DDATADIR=\"${DATADIR}\" -c -o $@ $<

	
#Installing
install:  install-data install-bin


install-data: all
	test -n "$(DATADIR)" && test "$(DATADIR)" != "/" && test "$(DATADIR)" != "/usr"
	test -n "$(DOCDIR)" && test "$(DOCDIR)" != "/" && test "$(DOCDIR)" != "/usr"
	rm -rf $(DATADIR)
	rm -rf $(DOCDIR)
	mkdir -p $(DOCDIR) $(DATADIR)/gfx $(DATADIR)/snd
	cp data/gfx/* $(DATADIR)/gfx/
	cp data/snd/* $(DATADIR)/snd/
	cp data/*.svd $(DATADIR)/

install-bin: all
	mkdir -p $(BINDIR) $(DOCDIR)
	cp $(NAME) $(BINDIR)/
	cp README FAQ manual.html manual.txt $(DOCDIR)/
	chmod 755 $(BINDIR)/$(NAME)

#Uninstalling
uninstall:
	rm -r $(DATADIR)
	rm -r $(DOCDIR)
	rm $(BINDIR)/$(NAME)

#Clean
clean:
	rm -f *.o
	rm -f $(NAME)
	rm -f $(NAME)-*
	-$(MAKE) -C tests clean

check: test

distclean: clean
	rm -rf $(DEPDIR)

#Making a binary package
binary:
	cp binpackage.sh $(PACKAGENAME)
	tar czf - $(BINDIR)/$(NAME) $(DATADIR) $(DOCDIR) >>$(PACKAGENAME)

dist:
	git archive --prefix=$(NAME)-${VERSION}/ HEAD -o $(NAME)-${VERSION}.tar.gz

#Testing
test:
	./run_tests.sh

test-headless:
	./run_tests.sh --headless

test-quick:
	./run_tests.sh --quick

# Include automatic dependencies
include $(wildcard $(DEPDIR)/*.d)

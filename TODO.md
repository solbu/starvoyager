# TODO

## Immediate

* Try and add autotools (Makefile.am, configure.ac) so it compiles on any 32/64 bit system without having to resort to hacking the Makefile every time.
* Find out how to increase the screen size.
* Review Debian packages SDL_gfx as libsdl-gfx1.2 (runtime) and libsdl-gfx1.2-dev (development headers and static library) to replace local copies of SDL_Gfx files

## Mid Term

* Evaluate upgrading to SDL2 - might not be feasible
* Win32 and MacOS builds from above AutoTools
* Update version and changelog

## Long Term

* Missions (and make sure they're saved and loaded). Objects bound to ships and stuff that get polled (iscomplete) every so often
* Debris streamers from damaged ships - very cool. Where to put it?
* Change of 'go to warp' strategy?
* Sort out gettarget in reverse
* Hashing for player retrieval
* Configurable keys
* MOTD scheme for server
* Prettify the graphics - somebody did this years ago if I can find it
* New ships; Sovereign class?
* Spectator mode
* Free /all/ dynamic memory on exit for correctness' sake
* Graphics blitting efficiency would be good
* Improved visibility rules

## Security and Critical Issues

### Recommendations for Further Hardening

1. **Code Review**: Conduct thorough security review of remaining modules
2. **Static Analysis**: Run additional SAST tools to identify remaining issues
3. **Fuzzing**: Test network protocol handling with malformed inputs
4. **Dependency Updates**: Update SDL and other libraries to latest versions
5. **Compiler Hardening**: Enable additional compiler security flags (-fstack-protector, -D_FORTIFY_SOURCE=2)
6. Github Actions build pipeline for binary releases and src bundles
7. ~~Github code analysis tooling~~

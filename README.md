# Star Voyager

A Frontier/Elite-style space combat and exploration game set in the Star Trek universe, featuring 2D arcade-style gameplay with SDL graphics.

## Features

### Core Gameplay
- **Space Combat**: Real-time battles with phasers, disruptors, and photon torpedoes
- **Ship Management**: Control shields, energy, fuel, and hull integrity
- **Exploration**: Navigate through a procedurally populated universe
- **Trading**: Buy fuel, ammunition, and equipment from inhabited planets
- **Multiple Ship Types**: Various Federation, Klingon, and other alliance vessels
- **Warp Travel**: Sublight and warp speed navigation
- **Cloaking Technology**: Stealth capabilities for compatible ships

### Multiplayer Support
- **Network Play**: Up to 32 players in shared universe
- **Dedicated Server**: Standalone server mode (`-s` flag)
- **Player Persistence**: Save/load player progress with password protection
- **Real-time Chat**: In-game communication system

### Advanced Features
- **Alliance System**: Choose from multiple factions (Federation, Klingon, etc.)
- **AI Opponents**: Sophisticated enemy behavior and fleet tactics
- **Planetary Systems**: Inhabited worlds with trading and refueling
- **Equipment Upgrades**: Enhance your ship's capabilities
- **Damage System**: Realistic battle damage and repair mechanics
- **Sensor Systems**: Long-range scanners with zoom capabilities

## Installation

### Dependencies
```bash
# Debian/Ubuntu
sudo apt install libsdl2-dev libsdl-net1.2-dev libsdl1.2-compat-dev
```

### Build from Source
```bash
git clone <repository-url>
cd starvoyager
make
sudo make install
```

### Run the Game
```bash
/usr/games/starvoyager
```

## Usage

### Starting a Game
1. Run `starvoyager`
2. Press `1` for local game
3. Enter player name
4. Choose alliance (Federation, Klingon, etc.)
5. Set password when prompted

### Command Line Options
- `-v` - Print version and exit
- `-h` - Show help
- `-x` - Run in extra-large window
- `-f` - Fullscreen mode
- `-s` - Run as standalone server

### Multiplayer
1. Start server: `starvoyager -s`
2. Connect: Press `3` at main menu, enter server IP

## Controls

### Movement
- **Arrow Keys** - Accelerate and turn
- **Shift + Arrows** - Warp speed transition
- **Shift + Down** - Reverse thrust

### Combat
- **Space** - Fire energy weapons (phasers/disruptors)
- **Z** - Fire torpedoes

### Targeting
- **T** - Cycle through nearby ships
- **E** - Target enemy ships only
- **P** - Target planets
- **Shift + T/E/P** - Reverse cycle

### Interface
- **F1** - Ship status
- **F2** - Internal systems (shields, cloaking)
- **F3** - Scanner controls
- **F4** - Hail target
- **F5** - Chat (multiplayer)
- **F6** - Player information
- **F7** - Game options

### Display
- **-/+** - Zoom sensor display
- **/** - Zoom main view
- **Q** - Quit game

## Gameplay Guide

### Ship Systems
- **Shields** - Toggle on/off (drains energy, blocks transporters)
- **Energy** - Powers weapons, shields, and movement
- **Hull** - Ship integrity (repairs available at friendly planets)
- **Fuel** - Required for power generation

### Combat Tips
- Energy weapons auto-target selected enemy
- Torpedoes require line-of-sight and range
- Shields drain energy but provide protection
- Cloaking makes you harder to detect but uses power

### Economy
- Earn credits by destroying enemy vessels
- Purchase fuel, ammunition, and upgrades at planets
- Hail inhabited planets to access services
- Save progress by beaming down to allied planets

### Navigation
- Use sensors to navigate large distances
- Warp speed for interstellar travel
- Mass lock prevents warping near planets
- Target planets for navigation assistance

## Technical Information

### System Requirements
- SDL 1.2 or 2.0
- SDL_net library
- Linux/Unix (primary), Windows/macOS (theoretical)
- Minimum 600x400 display

### File Structure
- `data/gfx/` - Game graphics and sprites
- `data/snd/` - Sound effects
- `data/*.svd` - Game databases (ships, equipment, alliances)

### Network Protocol
- TCP-based multiplayer
- Optimized for modem connections
- Adaptive client framerate
- Bandwidth-efficient updates

## Development

### Version History
- **0.5.0** - Current version with Debian patches and build fixes
- **0.4.x** - Network improvements and bug fixes
- **0.3.x** - Multiplayer support added
- **0.2.x** - Sound effects and AI improvements
- **0.1.x** - Core gameplay implementation

### License
Licensed under LGPL - see LICENSE file for details.

### Contributing
Original author: Richard Thrippleton (ret28@cam.ac.uk)
Current maintainer: Johnny A. Solbu

## Troubleshooting

### Common Issues
- **Compilation errors**: Ensure all SDL dependencies are installed
- **Crash on startup**: Check data files are in correct location
- **Network connection fails**: Verify server is running and accessible
- **Performance issues**: Try `-x` flag for larger window, check framerate

### Debug Information
- Crash logs saved to `~/.starvoyager/exitlog`
- Use `-Wall -ggdb3` compile flags for debugging
- Report bugs with detailed system information

## Credits

**Original Author**: Richard Thrippleton  
**Current Maintainer**: Johnny A. Solbu  
**Engine**: SDL (Simple DirectMedia Layer)  
**Theme**: Star Trek Universe  
**Inspired by**: Elite, Frontier series

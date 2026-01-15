# A Jaqueta das Trevas

A 2D action game built in C using the Raylib library.

## About

"A Jaqueta das Trevas" (Portuguese for "The Dark Jacket") is a simple 2D action game featuring a player character that can move, jump, and combat enemies using a sword.

## Features

- Player movement and jumping with gravity physics
- Sword combat system
- Enemy with health and collision detection
- Debug overlay for development

## Controls

| Key | Action |
|-----|--------|
| LEFT/RIGHT | Move |
| UP / SPACE | Jump |
| F | Attack with sword |

## Requirements

- CMake 3.15+
- Raylib 4.0+
- C99 compatible compiler

## Building

```bash
mkdir build
cd build
cmake ..
make
```

## Running

After building, run the executable from the build directory:

```bash
./a-jaqueta-das-trevas
```

## Project Structure

```
a-jaqueta-das-trevas/
├── CMakeLists.txt
├── src/
│   ├── main.c        # Game loop and initialization
│   ├── player.c/h    # Player mechanics and sword
│   ├── enemy.c/h     # Enemy entity
│   ├── physics.c/h   # Physics simulation
│   ├── ground.c/h    # Terrain rendering
│   ├── debug.c/h     # Debug overlay
│   └── config.h      # Configuration constants
└── build/
```

## License

This project is open source.

# so_long

A simple 2D graphical game written in C using the MiniLibX library. This project is part of the 42 school curriculum and aims to explore event-driven programming, basic game logic, and graphical rendering with minimal dependencies.

---

## Overview

**so_long** is a small maze game where the player must navigate through a map, collect items, and reach the exit. The map is displayed in a graphical window, and the player can move using keyboard inputs.

---

## Features

- Render maps based on simple text files.
- Player movement using arrow keys or WASD.
- Collectibles that must be gathered before exiting.
- Exit becomes available once all collectibles are obtained.
- Enforces map constraints (walls, unique exit/start, closed borders).
- Basic animation and graphical rendering using MiniLibX.
- Error handling for invalid maps/files.

---

## Compilation & Usage

### **Requirements**

- GCC compiler
- MinilibX library (usually included in 42 projects)
- Unix-like environment (Linux or macOS)

### **Compile**

```sh
make
```

### **Run**

```sh
./so_long <map_file.ber>
```

- `<map_file.ber>`: Path to your map file. See "Map Format" below.

---

## Map Format

- The map should be a rectangular file with the extension `.ber`
- Allowed characters:
  - `1`: Wall
  - `0`: Empty space
  - `C`: Collectible
  - `E`: Exit
  - `P`: Player (only one allowed)
- The map must be surrounded by walls.
- Must contain exactly one `E` and one `P`, at least one `C`.

**Example:**
```
111111
1P0C01
100001
1C0E11
111111
```

---

## Controls

- Arrow keys / WASD: Move player
- ESC: Exit game

---

## Project Structure

- `src/` – Main source code files
- `includes/` – Header files
- `maps/` – Example map files
- `Makefile` – Build script

---

**Created by [jihad7aljubeh](https://github.com/jihad7aljubeh) for 42 school.**

# Cub3D

**Cub3D** is a 42 school project that introduces you to ray-casting, inspired by the world-famous 1992 game Wolfenstein 3D. 
This project allows you to explore ray-casting principles, graphic manipulation using `minilibx`, and mathematical concepts for rendering a 3D perspective from a 2D map.

## Project Overview

Your goal is to create a dynamic 3D representation of the inside of a maze from a first-person perspective.
- Read a `.cub` file containing the map layout and configurations (textures, colors).
- Use ray-casting to render the walls, applying the correct texture based on the wall's orientation (North, South, East, West).
- Color the floor and ceiling with RGB values parsed from the configuration.
- Implement player movement (W, A, S, D) and camera rotation (Left/Right arrows or mouse).
- Display a minimap to help navigate the maze.

## Getting Started

### Prerequisites
- GCC compiler
- GNU Make
- `minilibx` (included in the project for macOS)

### Compilation
To compile the project, run:
```bash
make
```

### Usage
Run the executable with a map file as an argument:
```bash
./cub3D assets/maps/basic.cub
```

### Map Configuration (`.cub` files)
A valid map file must contain:
- **Textures**: Paths to the textures for each direction.
  ```
  NO ./assets/textures/north.xpm
  SO ./assets/textures/south.xpm
  WE ./assets/textures/west.xpm
  EA ./assets/textures/east.xpm
  ```
- **Colors**: Floor (F) and Ceiling (C) colors in RGB format.
  ```
  F 220,100,0
  C 225,30,0
  ```
- **Map Layout**: Composed of `1` (walls), `0` (empty space), and `N`, `S`, `E`, or `W` for the player's spawn position and orientation.
  ```
  111111
  100001
  10N001
  111111
  ```

## Controls
- `W`, `A`, `S`, `D` : Move the character up, left, down, and right.
- `←`, `→` : Rotate the camera left and right.
- `ESC` or click on the red cross : Close the window and quit the game cleanly.

## Authors
- JNTHNN

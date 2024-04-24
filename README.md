# cub3D

The objective of this project is to create a 3D maze game where the player navigates through a maze using keyboard controls. It involves the use of Ray Casting to make the map appear in 3D. 

I collaborated on this project with <a href="https://github.com/Larakh88">
 Lara Elkhoury
</a>.


![Screenshot from 2024-04-25 01-55-49](https://github.com/Y2Kgunner/cub3d/assets/84834112/7e78a2f7-0e17-4e8f-96ac-fad6c6181157)

## Key Features

- Utilize the MiniLibX graphical library for window management, colors, and textures
- Create a 3D maze environment with textured walls and colorful floor/ceiling
- Implement keyboard controls (W, A, S, D, left, and right arrows) for movement and arrow keys for view rotation
- Ensure smooth window management with clean program exit on user actions
- Parse a scene description file in the `.cub` format to configure the game environment
- Validate the map structure and handle errors gracefully
- Implement wall collisions and a minimap system as bonus features

## Knowledge Gained

- Ray casting for rendering 3D scenes from 2D maps
- Graphic design principles and techniques
- Graphical rendering and texture mapping in a 3D environment
- Event handling and keyboard input processing
- File parsing and data validation for scene configuration
- Algorithmic optimization for smooth window management and gameplay
- Error handling and debugging strategies for robust program execution

## Usage

To compile the project, ensure you have MiniLibX installed and use the provided Makefile:

```sh
make
```

Run your program with a map file as a parameter:

```sh
./cub3D maps/map1.cub
```

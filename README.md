# Pacman Game 
A simple Pacman game built using C and SDL2 libraries .

---
## Features

- Player movement using arrow keys
- Ghost enemies
- Collectible dots
- Basic collision detection
- Simple map system
- Sound effects for eating and death
- SDL2 based graphics rendering


## Project Structure

- src/ → Source code (.c files)
- include/ → Header files (.h files)
- assets/ → Images and sound files

---

## Libraries Used

SDL2 → Window, input, rendering  
SDL2_image → Image loading (PNG)  
SDL2_mixer → Sound effects and music  

---

## SDL2 Setup (Windows)

Download SDL2 libraries from:
https://github.com/libsdl-org/SDL/releases  
https://github.com/libsdl-org/SDL_image/releases  
https://github.com/libsdl-org/SDL_mixer/releases  

Extract and:
- Add include and lib folders to compiler
- Copy SDL2.dll files into project folder

---

## SDL2 Setup (Linux)

sudo apt install libsdl2-dev libsdl2-image-dev libsdl2-mixer-dev

---

## Build (Linux)

gcc src/*.c -o pacman -lSDL2 -lSDL2_image -lSDL2_mixer

---

## Run (Linux)

./pacman

---

## Build (Windows)

gcc src/*.c -o pacman.exe -lSDL2 -lSDL2_image -lSDL2_mixer

---

## Run (Windows)

Run pacman.exe

---


## Controls

WASD Keys → Move Pacman   

---

## Assets

pacman.png  
ghost.png  
dot.png  
wall.png  
eat.wav  
death.wav

#ifndef GAME_H   //header guard used to prevent multiple inclusions
#define GAME_H
#include <SDL2/SDL_mixer.h>  //sound effect and music handle
#include <SDL2/SDL.h>  //keyboard mouse window screen handling
#include <SDL2/SDL_image.h>  //load images

// Game states (macros)
#define GAME_RUNNING 1   //game is running
#define GAME_OVER 0   //game over state

// Map size (update if different)
#define MAP_WIDTH 20
#define TILE_SIZE 32   //Map width in pixels = 20 × 32 = 640 pixels

// extern is used to share SDL objects like the window and renderer across multiple source files.
extern SDL_Window* window;
extern SDL_Renderer* renderer;  //renderer is a pointer to a SDL_Renderer
extern SDL_Texture* pacmanTexture;
extern SDL_Texture* wallTexture;
extern SDL_Texture* dotTexture;
extern SDL_Texture* ghostTexture;

extern Mix_Chunk* eatSound;


// Function declarations
void init_game();
void game_loop();
void render_game(int score);

#endif  //end of header guard


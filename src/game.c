#include "game.h"
#include "map.h"
#include "player.h"
#include "ghost.h"
#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>


int game_state = GAME_RUNNING; //start game as running

// SDL variables
SDL_Window* window = NULL; //null means it points to nothing
SDL_Renderer* renderer = NULL;
SDL_Texture* pacmanTexture = NULL;
SDL_Texture* wallTexture = NULL;
SDL_Texture* dotTexture = NULL;
SDL_Texture* ghostTexture = NULL;
Mix_Chunk* eatSound = NULL;
Mix_Chunk* deathSound = NULL;


#define TILE_SIZE 32

// Initialize game and SDL
void init_game()
{
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);   //1 mono speaker 2 stereo //44100 frequency //2048 buffer size

eatSound = Mix_LoadWAV("eat.wav");
deathSound = Mix_LoadWAV("death.wav");

if (!eatSound || !deathSound)
    printf("Sound load error\n");

    // Your original initialization
    init_map();
    init_player();
    init_ghost();
    init_ghost1();

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL_Init failed: %s\n", SDL_GetError());
        exit(1);
    }

    // Create window
    window = SDL_CreateWindow("Pacman",
                              SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              MAP_WIDTH * TILE_SIZE, MAP_HEIGHT * TILE_SIZE,
                              SDL_WINDOW_SHOWN);
    if (!window) {
        printf("Window creation failed: %s\n", SDL_GetError());
        SDL_Quit();
        exit(1);
    }

    // Create renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("Renderer creation failed: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        exit(1);
    }

    // Load images
    pacmanTexture = SDL_CreateTextureFromSurface(renderer, IMG_Load("pacman.png"));
    wallTexture   = SDL_CreateTextureFromSurface(renderer, IMG_Load("wall.png"));
    dotTexture    = SDL_CreateTextureFromSurface(renderer, IMG_Load("dot.png"));
    ghostTexture  = SDL_CreateTextureFromSurface(renderer, IMG_Load("ghost.png"));
}

// Draw everything on screen
void render_game(int score)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);  //set bg color to black
    SDL_RenderClear(renderer);   //clear screen with black

SDL_Rect rect; //.x left .y top .w width .h height
for (int y = 0; y < MAP_HEIGHT; y++)
{
    for (int x = 0; x < MAP_WIDTH; x++)
    {
        // Draw walls full size
        if (map[y][x] == 'W')  //check if tile is wall
        {
            rect.x = x * TILE_SIZE;   //convert tile coords to pixel coords
            rect.y = y * TILE_SIZE;
            rect.w = TILE_SIZE;
            rect.h = TILE_SIZE;  //full tile size
            SDL_RenderCopy(renderer, wallTexture, NULL, &rect);  //null means entire texture
        }
        // Draw dots smaller and centered
        else if (map[y][x] == 'D')
        {
            int dotSize = TILE_SIZE / 4; // 8 pixels if TILE_SIZE = 32
            rect.x = x * TILE_SIZE + TILE_SIZE/2 - dotSize/2;
            rect.y = y * TILE_SIZE + TILE_SIZE/2 - dotSize/2;
            rect.w = dotSize;
            rect.h = dotSize;
            SDL_RenderCopy(renderer, dotTexture, NULL, &rect);
        }
    }
}


    // Draw Pacman
    SDL_Rect pacmanRect = { player.x*TILE_SIZE, player.y*TILE_SIZE, TILE_SIZE, TILE_SIZE };
    SDL_RenderCopy(renderer, pacmanTexture, NULL, &pacmanRect);

    // Draw ghosts
    SDL_Rect ghostRect = { ghost.x*TILE_SIZE, ghost.y*TILE_SIZE, TILE_SIZE, TILE_SIZE };
    SDL_Rect ghost1Rect = { ghost1.x*TILE_SIZE, ghost1.y*TILE_SIZE, TILE_SIZE, TILE_SIZE };
    SDL_RenderCopy(renderer, ghostTexture, NULL, &ghostRect);
    SDL_RenderCopy(renderer, ghostTexture, NULL, &ghost1Rect);

    SDL_RenderPresent(renderer);  //update screen with rendering performed
}


// Main game loop
void game_loop()
{
    int score = 0;  //player score
    SDL_Event event;  //event variable to handle input
    bool running = true;

    while (running && game_state == GAME_RUNNING)
    {
        // Handle keyboard input
     char input = 0;  //input will store the key pressed 0 means no key pressed

while (SDL_PollEvent(&event)) {  //check if any event happened
    if (event.type == SDL_QUIT) 
        running = 0;

    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {  //event.key.keysym.sym gives the key pressed
            case SDLK_UP:
            case SDLK_w: input = 'w'; break;

            case SDLK_DOWN:
            case SDLK_s: input = 's'; break;

            case SDLK_LEFT:
            case SDLK_a: input = 'a'; break;

            case SDLK_RIGHT:
            case SDLK_d: input = 'd'; break;
        }
    }
}

if (input)
    move_player(input);


        // Move ghosts
        move_ghost();
        move_ghost1();

        // Eat dots
     if (map[player.y][player.x] == 'D')
{
    map[player.y][player.x] = ' '; // mark dot as eaten
    player.score += 1;             // update player score
}


        // Check collisions with ghosts
        if ((player.x == ghost.x && player.y == ghost.y) ||  //if pacman collides with any ghost game over.
            (player.x == ghost1.x && player.y == ghost1.y)) {
                    Mix_PlayChannel(-1, deathSound, 0);
    SDL_Delay(1500); // let sound finish
            game_state = GAME_OVER;
        }

        // Draw everything
        render_game(score);

        SDL_Delay(100); // slow down the game (10 frames per second)
    }

    printf("Game Over!\n");
    printf("Your final score is %d\n", player.score);

    // Clean up SDL
    Mix_FreeChunk(eatSound);
Mix_FreeChunk(deathSound);
Mix_CloseAudio();

    SDL_DestroyTexture(pacmanTexture);
    SDL_DestroyTexture(wallTexture);
    SDL_DestroyTexture(dotTexture);
    SDL_DestroyTexture(ghostTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}


#include "player.h"

struct Player player; // define the actual global player

#include "map.h"
#include <SDL2/SDL_mixer.h>
extern Mix_Chunk* eatSound; // for sound
void init_player()
{
    player.x = 1;
    player.y = 1;
    player.score = 0;
}


void move_player(char input)
{
    int dx = 0, dy = 0;

    if (input == 'w') dy = -1;
    else if (input == 's') dy = 1;
    else if (input == 'a') dx = -1;
    else if (input == 'd') dx = 1;
    else return;

    int newX = player.x + dx;
    int newY = player.y + dy;

    // bounds check
    if (newX < 0 || newX >= MAP_WIDTH || newY < 0 || newY >= MAP_HEIGHT)
        return;

    // wall check
    if (map[newY][newX] == 'W')
        return;

    // move player
    player.x = newX;
    player.y = newY;

    // eat dot
    if (map[newY][newX] == 'D') {
        map[newY][newX] = ' ';
        player.score += 10;
        if (eatSound)
            Mix_PlayChannel(-1, eatSound, 0);
    }
}

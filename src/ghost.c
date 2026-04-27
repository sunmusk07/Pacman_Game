#include "ghost.h"
#include "map.h" 
#include <stdlib.h>

struct Ghost ghost;
struct Ghost ghost1;

// Initialize first ghost
void init_ghost()
{
    ghost.x = 35;
    ghost.y = 4;
}

// Initialize second ghost
void init_ghost1()
{
    ghost1.x = 20;
    ghost1.y = 14;
}

// Move first ghost randomly
void move_ghost()
{
    int dir = rand() % 4;
    int nextX = ghost.x;
    int nextY = ghost.y;

    if (dir == 0) nextX++;
    else if (dir == 1) nextX--;
    else if (dir == 2) nextY++;
    else if (dir == 3) nextY--;

    if (nextX > 0 && nextX < MAP_WIDTH-1 &&
        nextY > 0 && nextY < MAP_HEIGHT-1 &&
        map[nextY][nextX] != 'W')
    {
        ghost.x = nextX;
        ghost.y = nextY;
    }
}

void move_ghost1()
{
    int dir = rand() % 4;
    int nextX = ghost1.x;
    int nextY = ghost1.y;

    if (dir == 0) nextX++;
    else if (dir == 1) nextX--;
    else if (dir == 2) nextY++;
    else if (dir == 3) nextY--;

    if (nextX > 0 && nextX < MAP_WIDTH-1 &&
        nextY > 0 && nextY < MAP_HEIGHT-1 &&
        map[nextY][nextX] != 'W')
    {
        ghost1.x = nextX;
        ghost1.y = nextY;
    }
}

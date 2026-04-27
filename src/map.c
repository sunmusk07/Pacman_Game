#include "map.h"

// Map types:
// 'W' = Wall
// 'D' = Dot
// ' ' = Empty
char map[MAP_HEIGHT][MAP_WIDTH];

void init_map()
{
    for (int y = 0; y < MAP_HEIGHT; y++)
    {
        for (int x = 0; x < MAP_WIDTH; x++)
        {
            // Outer walls
            if (y == 0 || y == MAP_HEIGHT-1 || x == 0 || x == MAP_WIDTH-1)
                map[y][x] = 'W';
            else
                map[y][x] = 'D';

            // Custom walls
            if ((y == 1 && x >= 15 && x <= 25) ||
                (y == 3 && x >= 10 && x <= 20) ||
                (y == 3 && x >= 30) ||
                (y == 3 && x <= 5) ||
                (y == 5 && x >= 4 && x <= 13) ||
                (y == 5 && x >= 16 && x <= 35) ||
                (y == 7 && x <= 6) ||
                (y == 7 && x >= 15 && x <= 22) ||
                (y == 7 && x >= 30) ||
                (y == 9 && x >= 4 && x <= 18) ||
                (y == 9 && x >= 25 && x <= 36) ||
                (y == 11 && x >= 2 && x <= 10) ||
                (y == 11 && x >= 20 && x <= 25) ||
                (y == 11 && x >= 33) ||
                (y == 13 && x <= 5) ||
                (y == 13 && x >= 15 && x <= 20) ||
                (y == 13 && x >= 30 && x <= 35) ||
                (y == 15 && x >= 11 && x <= 32) ||
                (y == 17 && x <= 13) ||
                (y == 17 && x >= 30) ||
                (y == 19 && x >= 6) ||
                (y == 21 && x >= 3) ||
                (y == 23 && x >= 1))
            {
                map[y][x] = 'W';
            }
        }
    }

    // Make sure player spawn is empty
    map[1][1] = ' ';
}

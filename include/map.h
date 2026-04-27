#ifndef MAP_H
#define MAP_H

#define MAP_WIDTH 40
#define MAP_HEIGHT 20

// The map array stores walls '#' and dots '.'
extern char map[MAP_HEIGHT][MAP_WIDTH];

// Functions
void init_map();

#endif


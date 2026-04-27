#ifndef PLAYER_H
#define PLAYER_H

struct Player
{
    int x;
    int y;
    int score;
};

extern struct Player player;

void init_player();
void move_player(char input);

#endif
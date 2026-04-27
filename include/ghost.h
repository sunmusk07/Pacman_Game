#ifndef GHOST_H
#define GHOST_H


struct Ghost
{
    int x;
    int y;
};



extern struct Ghost ghost;
extern struct Ghost ghost1;

void init_ghost();
void move_ghost();
void init_ghost1();
void move_ghost1();

#endif



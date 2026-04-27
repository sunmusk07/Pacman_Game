 //“Pacman clone made in C language along with SDL2 Library . game is started using init_game(). init game set up sdl2 create window (pixel ) and setup renderer and required resources are loaded. game_loop() handles user input  update game logic and render game untill it exits from terminal
//
#include "game.h"

int main()
{
    init_game();
    game_loop();
    return 0;
}

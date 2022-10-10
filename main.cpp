#include "include/Instance/Game.h"
#include "include/Instance/Path.h"

int main()
{
    Game* game = new Game(1920,1080); // initiate game with resolution 1920x1080
    game->run();
    return 0;
}
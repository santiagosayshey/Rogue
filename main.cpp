#include "Game.h"
#include "Gameplay.h"

int main()
{
    
    Game game(480,480);
    Gameplay g(game);
    game.run();
    

    return 0;
}
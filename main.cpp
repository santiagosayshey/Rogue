#include "Include/Instance/Game.h"

#include <iostream>
#include <fstream>
#include <string>

int main()
{


    // initiate game with resolution 1920x1080
    Game* game = new Game(1920,1080);

    // start the game loop
    game->run();

    game->setTotalPlayTime(game->getCurrentPlayTime().getElapsedTime().asSeconds() + game->getTotalPlayTime());

    std::cout << game->getTotalPlayTime() << std::endl;
    std::cout << game->getFastestRunTime() << std::endl;

    std::ofstream writeTotalPlayTime  ("TotalPlayTime.txt");
    std::ofstream writeFastestRunTime ("FastestRunTime.txt");
    
    writeTotalPlayTime << std::to_string(game->getTotalPlayTime());
    writeFastestRunTime << std::to_string(game->getFastestRunTime());

    return 0;
}



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

    // write stats 
    game->setTotalPlayTime(game->getCurrentPlayTime().getElapsedTime().asSeconds() + game->getTotalPlayTime());

    std::ofstream writeTotalPlayTime  ("Statistics/total.txt");
    std::ofstream writeFastestRunTime ("Statistics/speed.txt");
    
    writeTotalPlayTime << std::to_string(game->getTotalPlayTime());
    writeFastestRunTime << std::to_string(game->getFastestRunTime());

    std::ofstream writeTotalWins  ("Statistics/wins.txt");
    std::ofstream writeTotalLosses ("Statistics/losses.txt");

    writeTotalWins << std::to_string(game->getTotalWins());
    writeTotalLosses << std::to_string(game->getTotalLosses());

    std::cout << game->getTotalPlayTime() << std::endl;
    std::cout << game->getFastestRunTime() << std::endl;

    std::cout << game->getTotalWins() << std::endl;
    std::cout << game->getTotalLosses() << std::endl;


    return 0;
}



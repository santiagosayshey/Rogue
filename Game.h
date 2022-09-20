#ifndef GAME_H
#define GAME_H

#pragma once

#include "SFML/Graphics.hpp"
#include "GameState.h"


class Game
{
public:
    Game();
    Game(int width, int height, GameState* initial);
    ~Game();

    void run();
    void setState(GameState* newState);


private:
    sf::RenderWindow* window;
    GameState* currentState;

};

#endif
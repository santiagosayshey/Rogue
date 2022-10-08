#ifndef GAME_H
#define GAME_H

#pragma once

#include "SFML/Graphics.hpp"
#include "../State/State.h"
#include "../State/MenuState.h"
#include "../Entity/Player.h"
#include "Path.h"

class Game
{
public:
    Game(int width, int height);
    ~Game();

    void run();
    void setState(State* newState);

    Path* p = new Path;


private:
    sf::RenderWindow* window;
    State* currentState;
    

    Player* player;
};

#endif
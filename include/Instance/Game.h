#ifndef GAME_H
#define GAME_H

#pragma once

#include "SFML/Graphics.hpp"
#include "../State/State.h"
#include "../State/MenuState.h"

class Game
{
public:
    Game(int width, int height);
    ~Game();

    void run();
    void setState(State* newState);


private:
    sf::RenderWindow* window;
    State* currentState;

    sf::Vector2i* p_idle;
    sf::Vector2i* p_attack1;
    sf::Vector2i* p_die;

};

#endif
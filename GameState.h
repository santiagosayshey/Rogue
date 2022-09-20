#ifndef GAMESTATE_H
#define GAMESTATE_H

#pragma once

#include "SFML/Graphics.hpp"

class GameState
{
public:
    virtual void update(sf::RenderWindow* window) = 0;
    virtual void render(sf::RenderWindow* window) = 0;


private:

};

#endif
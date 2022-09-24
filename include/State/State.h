#ifndef State_H
#define State_H

#pragma once

#include "SFML/Graphics.hpp"

// delcare game class as to not have circular dependancy
class Game;
class State
{
public:
    State(Game* game);
    virtual void update(sf::RenderWindow* window) = 0;
    virtual void render(sf::RenderWindow* window) = 0;


protected:
    Game* game;

};

#endif
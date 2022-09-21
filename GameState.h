#ifndef GAMESTATE_H
#define GAMESTATE_H

#pragma once

#include "SFML/Graphics.hpp"

class Game;
class GameState
{
public:
    GameState(Game* game);
    virtual void update(sf::RenderWindow* window) = 0;
    virtual void render(sf::RenderWindow* window) = 0;


protected:
    Game* game;

};

#endif
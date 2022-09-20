#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#pragma once

#include "Game.h"
#include "SFML/Graphics.hpp"

class Gameplay
{
public:
    Gameplay(Game game);
    ~Gameplay();

    void update(sf::RenderWindow* window);
    void render(sf::RenderWindow* window);


private:
    Game game;
    sf::Event event;
    sf::Clock clock;
    float dt;

};

#endif
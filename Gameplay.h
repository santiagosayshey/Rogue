#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#pragma once

#include "GameState.h"

class Gameplay : public GameState
{
public:
    Gameplay(Game* game);
    ~Gameplay();

    void update(sf::RenderWindow* window);
    void render(sf::RenderWindow* window);


private:
    sf::Event event;
    sf::Clock clock;
    float dt;

};

#endif
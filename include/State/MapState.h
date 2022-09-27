#ifndef MAPSTATE_H
#define MAPSTATE_H

#pragma once

#include "State.h"

class MapState : public State
{
public:
    MapState(Game* game, Player* player);
    ~MapState();

    void update(sf::RenderWindow* window);
    void render(sf::RenderWindow* window);

private:
    sf::Texture bgTex;
    sf::Sprite bgSpr;

    sf::Event event;

};

#endif
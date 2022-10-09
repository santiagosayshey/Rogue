#ifndef MAPSTATE_H
#define MAPSTATE_H

#pragma once

#include "State.h"
#include "../Drawable/Sprite.h"

class MapState : public State
{
public:
    MapState(Game* game, Player* player);
    ~MapState();

    void update(sf::RenderWindow* window);
    void render(sf::RenderWindow* window);

private:
    Sprite* mapTemplate;

    Sprite* lvl;
    Sprite* lvlHover;
    Sprite* enemy;
    Sprite* enemyHover;


    bool hover1;

    bool sound1;

    sf::SoundBuffer sb;
    sf::Sound UI;

    sf::Event event;
};

#endif
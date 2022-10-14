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

    void updateLVL();

private:
    Sprite* mapTemplate;

    Sprite* lvl;
    Sprite* lvlHover;
    Sprite* enemy;
    Sprite* enemyHover;
    
    Sprite* lvl2;
    Sprite* lvl2Hover;
    Sprite* enemy2;
    Sprite* enemyHover2;

    Sprite* lvl3;
    Sprite* lvl3Hover;
    Sprite* enemy3;
    Sprite* enemyHover3;

    bool hover1=false;
    bool hover2=false;
    bool hover3=false;

    bool sound1;
    bool sound2;
    bool sound3;

    sf::SoundBuffer sb;
    sf::Sound UI;

    sf::Event event;

    int currentLVL=1;
};

#endif
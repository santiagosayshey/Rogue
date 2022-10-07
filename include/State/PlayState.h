#ifndef PlayState_H
#define PlayState_H

#pragma once

#include "State.h"
#include "../Entity/Enemy.h"
#include "../Drawable/Button.h"
#include "../Drawable/Sprite.h"

class PlayState : public State
{
public:
    PlayState(Game* game, Player* player);
    ~PlayState();

    void update(sf::RenderWindow* window);
    void render(sf::RenderWindow* window);


private:
    sf::Event event;
    sf::Clock clock;

    Enemy* enemy;
    Button* attack;
    Button* attackP;

    Sprite* wiz;
    Sprite* wizhealth;

    Button* health;
    Button* healthShadow;
    Button* armour;

    bool playerDead = false;
    bool enemyDead = false;

    Sprite* sEnemy;
};

#endif
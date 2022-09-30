#ifndef PlayState_H
#define PlayState_H

#pragma once

#include "State.h"
#include "../Entity/Enemy.h"
#include "../Drawable/Button.h"
#include "../Drawable/Character.h"

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

    bool playerDead = false;
    bool enemyDead = false;

    Character* sEnemy;
};

#endif
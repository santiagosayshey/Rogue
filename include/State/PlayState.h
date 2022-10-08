#ifndef PlayState_H
#define PlayState_H

#pragma once

#include "State.h"
#include "../Entity/Enemy.h"
#include "../Drawable/Text.h"
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
    Text* attack;
    Text* attackP;

    Sprite* wiz;
    Sprite* wizhealth;

    Text* health;
    Text* healthShadow;
    Text* armour;

    bool playerDead = false;
    bool enemyDead = false;

    Sprite* sEnemy;
};

#endif
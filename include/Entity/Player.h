#ifndef PLAYER_H
#define PLAYER_H

#pragma once

#include <iostream>

#include "Entity.h"
#include "Enemy.h"

class Player : public Entity
{
public:
    Player();
    ~Player();

    void updateExp(int exp);
    void updateLvl();
    
    int getExp();
    int getLvl();

    void attack(Enemy* enemy);

private:
    int exp=0;
    int lvl=1;
};

#endif
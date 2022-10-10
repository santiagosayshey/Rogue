#ifndef PLAYER_H
#define PLAYER_H

#pragma once

#include <iostream>

#include "Entity.h"
#include "Enemy.h"

class Player : public Entity
{
public:
    // default constructor and destructor
    Player();
    ~Player();

    // update experience 
    void updateExp(int exp);

    // update player level
    void updateLvl();
    
    // return experience
    int getExp();

    // return player level
    int getLvl();

private:
    // initiate experience as 0
    int exp=0;

    // initiate player level as 1
    int lvl=1;
};

#endif
#ifndef PLAYER_H
#define PLAYER_H

#pragma once

#include <iostream>

#include "Entity.h"

class Player : public Entity
{
public:
    // default constructor and destructor
    Player();
    ~Player();

private:
    int highscore;
    int highscoreBuffer;

};

#endif
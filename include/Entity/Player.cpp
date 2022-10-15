#include "Player.h"
#include <iostream>

Player::Player()
{
}

Player::~Player(){}

void Player::updateExp(int exp)
{
    // set init values as parameters
    this->exp = exp;
}

void Player::updateLvl()
{
    // increase level by 1 if experience exceeds 100
    if (getExp() > 99) {
        lvl++;

        // update experience to value of 0
        updateExp(0);
    }
}

int Player::getExp()
{
    // return experience value
    return this->exp;
}

int Player::getLvl()
{
    // return level
    return this->lvl;
}
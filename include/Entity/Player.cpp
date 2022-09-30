#include "Player.h"
#include <iostream>

Player::Player()
{

}

Player::~Player()
{

}

void Player::updateExp(int exp)
{
    this->exp = exp;
}

void Player::updateLvl()
{
    if (getExp() > 99) {
        lvl++;
        updateExp(0);
    }
}

int Player::getExp()
{
    return this->exp;
}

int Player::getLvl()
{
    return this->lvl;
}
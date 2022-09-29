#include "Player.h"

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

void Player::attack(Enemy* enemy)
{
    switch(role) {
        case 1:
            sprite->updateAnimation(7,0);
        case 2:
            sprite->updateAnimation(7,0);
        case 3:
            sprite->updateAnimation(7,0);
    }

    
    
}

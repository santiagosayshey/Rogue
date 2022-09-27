#include "Player.h"

Player::Player()
{

}

Player::~Player()
{

}

void Player::chooseRole(int role)
{
    switch (role) {
        case 1:
            updateHealth(50);
            updateArmour(0);
            updateAttack(30);
            updateAccuracy(90);
            updateEvasion(50);
            break;
        case 2:
            updateHealth(75);
            updateArmour(40);
            updateAttack(20);
            updateAccuracy(60);
            updateEvasion(5);
            break;
        case 3:
            updateHealth(75);
            updateArmour(20);
            updateAttack(5);
            updateAccuracy(80);
            updateEvasion(30);
            break;
    }
    std::cout <<
    health << std::endl <<
    armour << std::endl <<
    attack << std::endl <<
    exp << std::endl <<
    lvl << std::endl <<
    accuracy << std::endl <<
    evasion << std::endl;
}

void Player::updateHealth(int health)
{
    this->health = health;
}

void Player::updateArmour(int armour)
{
    this->armour = armour;
}

void Player::updateAttack(int attack)
{
    this->attack = attack;
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

void Player::updateAccuracy(int accuracy)
{
    this->accuracy = accuracy;
}

void Player::updateEvasion(int evasion)
{
    this->evasion = evasion;
}

int Player::getHealth()
{
    return this->health;
}

int Player::getArmour()
{
    return this->armour;    
}

int Player::getAttack()
{
    return this->attack;
}

int Player::getExp()
{
    return this->exp;
}

int Player::getLvl()
{
    return this->lvl;
}

int Player::getAccuracy()
{
    return this->accuracy;
}

int Player::getEvasion()
{
    return this->evasion;
}
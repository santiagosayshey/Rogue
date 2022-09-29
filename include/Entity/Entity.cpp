#include "Entity.h"

void Entity::chooseRole(int role)
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
}

void Entity::setChararacter(Character* sprite)
{
    this->sprite = sprite;
}

void Entity::updateHealth(int health)
{
    this->health = health;
}

void Entity::updateArmour(int armour)
{
    this->armour = armour;
}

void Entity::updateAttack(int attack)
{
    this->attack = attack;
}

void Entity::updateAccuracy(int accuracy)
{
    this->accuracy = accuracy;
}

void Entity::updateEvasion(int evasion)
{
    this->evasion = evasion;
}


int Entity::getHealth()
{
    return this->health;
}

int Entity::getArmour()
{
    return this->armour;    
}

int Entity::getAttack()
{
    return this->attack;
}

int Entity::getAccuracy()
{
    return this->accuracy;
}

int Entity::getEvasion()
{
    return this->evasion;
}
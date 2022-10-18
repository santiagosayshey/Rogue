#include "Entity.h"

#include <iostream>

Entity::~Entity()
{
    delete sprite;
    delete gui;
}

float Entity::setHealth(float health)
{
    this->health = health;
    return getHealth(); 
}

void Entity::setArmour(float armour)
{
    this->armour = armour; 
}

void Entity::setPower(float power)
{
    this->power = power; 
}

DynamicSprite* Entity::getSprite()
{
    return this->sprite; 
}

float Entity::getHealth()
{
    return this->health; 
}

float Entity::getArmour()
{
    return this->armour; 
}

float Entity::getPower()
{
    return this->power; 
}

void Entity::setCharacter(DynamicSprite* sprite, int ID)
{
    this->sprite = sprite;
    this->ID = ID; 
}

int Entity::getID()
{
    return ID;
}

void Entity::setPowerBuffer(int power)
{
    powerBuffer = power;
}

std::string Entity::attack(Entity* entity)
{
    // set health value
    if ( entity->getHealth() - getPower() > 0 )
    {
        entity->setHealth(entity->getHealth() - getPower()); 
    }
    else
    {
        entity->setHealth(0);
    }

    return "null";
}

float Entity::getPowerBuffer()
{
    return powerBuffer;
}

void Entity::incrementAction()
{
    currentAction++;
}

std::string Entity::getFirstMove()
{
    return firstMove;
}

void Entity::setGUI(std::string type)
{
    gui = new Sprite(type,0,0,60,21,8);
}

Sprite* Entity::getGUI()
{
    return gui;
}



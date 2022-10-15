#include "Entity.h"

#include <iostream>






float Entity::updateHealth(float health)
{
    // update character health variable
    this->health = health;
    return getHealth(); 
}

void Entity::updateArmour(float armour)
{
    // update character armour variable
    this->armour = armour; 
}

void Entity::updatePower(float power)
{
    // update character power variable
    this->power = power; 
}

DynamicSprite* Entity::getSprite()
{
    // return character sprite
    return this->sprite; 
}

float Entity::getHealth()
{
    // return character health
    return this->health; 
}

float Entity::getArmour()
{
    // return character armour 
    return this->armour; 
}

float Entity::getPower()
{
    // return character power
    return this->power; 
}

void Entity::setCharacter(DynamicSprite* sprite, int character)
{
    // set character sprite
    this->sprite = sprite;

    // set character
    this->character = character; 
}


bool Entity::update(sf::RenderWindow* window)
{
    // disable animation repeat, play idle animation
    return sprite->animation(false,false); 
}   

void Entity::draw(sf::RenderWindow* window)
{
    // draw sprite in the render window
    sprite->draw(window);
}

int Entity::returnChar()
{
    return character;
}

void Entity::setOGPower(int power)
{
    originalPower = power;
}

std::string Entity::attack(Entity* entity)
{
    // update health value
    if ( entity->getHealth() - getPower() > 0 )
    {
        entity->updateHealth(entity->getHealth() - getPower()); 
    }
    else
    {
        entity->updateHealth(0);
    }

    return "null";
}

float Entity::getOGPower()
{
    return originalPower;
}

void Entity::incrementAction()
{
    currentAction++;
    std::cout << currentAction << std::endl;
}

std::string Entity::getFirstMove()
{
    return firstMove;
}

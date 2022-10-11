#include "Entity.h"

#include <iostream>






int Entity::updateHealth(int health)
{
    // update character health variable
    this->health = health;
    return getHealth(); 
}

void Entity::updateArmour(int armour)
{
    // update character armour variable
    this->armour = armour; 
}

void Entity::updatePower(int power)
{
    // update character power variable
    this->power = power; 
}

DynamicSprite* Entity::getSprite()
{
    // return character sprite
    return this->sprite; 
}

int Entity::getHealth()
{
    // return character health
    return this->health; 
}

int Entity::getArmour()
{
    // return character armour 
    return this->armour; 
}

int Entity::getPower()
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

void Entity::attack(Entity* entity)
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
}
#include "Entity.h"

#include <iostream>






void Entity::updateHealth(int health)
{
    // update character health variable
    this->health = health; 
}

void Entity::updateArmour(int armour)
{
    // update character armour variable
    this->armour = armour; 
}

void Entity::updatePower(int Power)
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
    return sprite->animation(false); 
}   

void Entity::draw(sf::RenderWindow* window)
{
    // draw sprite in the render window
    sprite->draw(window);
}

void Entity::attack(Entity* entity)
{
    switch (character) {
        // chooses which animation within the sprite sheet to play
        case 1:
            sprite->updateAnimation(7,3);
            break;
        case 2:           
            sprite->updateAnimation(7,3);
            break;
        case 3:
            sprite->updateAnimation(7,3);
            break;
        case 4:
            sprite->updateAnimation(8,2);
            break;
    }

    // output health value
    std::cout << entity->getHealth() << std::endl; 

    // update health value
    entity->updateHealth(entity->getHealth() - getPower()); 

    // output final health value 
    std::cout << entity->getHealth() << std::endl; 
}
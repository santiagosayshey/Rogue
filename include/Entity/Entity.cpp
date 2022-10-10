#include "Entity.h"

#include <iostream>






void Entity::updateHealth(int health)
{
    this->health = health; // update character health variable
}

void Entity::updateArmour(int armour)
{
    this->armour = armour; // update character armour variable
}

void Entity::updatePower(int Power)
{
    this->power = power; // update character power variable
}


Sprite* Entity::getSprite()
{
    return this->sprite; // return character sprite
}

int Entity::getHealth()
{
    return this->health; // return character health
}

int Entity::getArmour()
{
    return this->armour; // return character armour 
}

int Entity::getPower()
{
    return this->power; // return character power
}

void Entity::setCharacter(Sprite* sprite, int character)
{
    this->sprite = sprite; // set character sprite
    this->character = character; // set character
}


bool Entity::update(sf::RenderWindow* window)
{

    return sprite->animation(false); // disable animation repeat
}   

void Entity::draw(sf::RenderWindow* window)
{
    sprite->draw(window);
}

void Entity::attack(Entity* entity)
{
    switch (character) {
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

    std::cout << entity->getHealth() << std::endl; // output health value
    entity->updateHealth(entity->getHealth() - getPower()); // update health value
    std::cout << entity->getHealth() << std::endl; // output health 

}
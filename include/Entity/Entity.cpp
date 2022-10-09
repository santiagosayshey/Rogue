#include "Entity.h"

#include <iostream>






void Entity::updateHealth(int health)
{
    this->health = health;
}

void Entity::updateArmour(int armour)
{
    this->armour = armour;
}

void Entity::updatePower(int Power)
{
    this->power = power;
}


Sprite* Entity::getSprite()
{
    return this->sprite;
}

int Entity::getHealth()
{
    return this->health;
}

int Entity::getArmour()
{
    return this->armour;    
}

int Entity::getPower()
{
    return this->power;
}

void Entity::setCharacter(Sprite* sprite, int character)
{
    this->sprite = sprite;
    this->character = character;
}


bool Entity::update(sf::RenderWindow* window)
{

    return sprite->animation(false);
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

    std::cout << entity->getHealth() << std::endl;
    entity->updateHealth(entity->getHealth() - getPower());
    std::cout << entity->getHealth() << std::endl;

}
#include "Entity.h"

#include <iostream>

void Entity::chooseRole(int role)
{
    this->role = role;
    switch (role) {
        case 1:
            updateHealth(50);
            updateArmour(0);
            updateDamage(30);
            updateAccuracy(90);
            updateEvasion(50);
            break;
        case 2:
            updateHealth(75);
            updateArmour(40);
            updateDamage(20);
            updateAccuracy(60);
            updateEvasion(5);
            break;
        case 3:
            updateHealth(75);
            updateArmour(20);
            updateDamage(5);
            updateAccuracy(80);
            updateEvasion(30);
            break;
    }
}

void Entity::setChararacter(Sprite* sprite)
{
    this->sprite = sprite;
}

void Entity::updateRole(int role)
{
    this->role = role;
}

void Entity::updateHealth(int health)
{
    this->health = health;
}

void Entity::updateArmour(int armour)
{
    this->armour = armour;
}

void Entity::updateDamage(int damage)
{
    this->damage = damage;
}

void Entity::updateAccuracy(int accuracy)
{
    this->accuracy = accuracy;
}

void Entity::updateEvasion(int evasion)
{
    this->evasion = evasion;
}

int Entity::getRole()
{
    return this->role;
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

int Entity::getDamage()
{
    return this->damage;
}

int Entity::getAccuracy()
{
    return this->accuracy;
}

int Entity::getEvasion()
{
    return this->evasion;
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
    switch (role) {
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
    entity->updateHealth(entity->getHealth() - getDamage());
    std::cout << entity->getHealth() << std::endl;

}

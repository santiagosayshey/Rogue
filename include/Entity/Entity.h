#ifndef ENTITY_H
#define ENTITY_H

#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

#include "../Drawable/Sprite.h"

class Entity
{
public:
    void updateHealth(int health);
    void updateArmour(int armour);
    void updatePower(int Power);

    int getHealth();
    int getArmour();
    int getPower();

    void setCharacter(Sprite* sprite, int character);

    Sprite* getSprite();

    void attack(Entity* entity);

    bool update(sf::RenderWindow* window);
    void draw(sf::RenderWindow* window);

protected:
    Sprite* sprite;

    int health;
    int armour;
    int power;

    int character;

    

};

#endif
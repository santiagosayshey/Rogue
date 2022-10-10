#ifndef ENTITY_H
#define ENTITY_H

#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

#include "../Drawable/Sprite.h"
#include "../Drawable/DynamicSprite.h"

class Entity
{
public:
    // update individual stats of character
    void updateHealth(int health);
    void updateArmour(int armour);
    void updatePower(int Power);

    // return individual stats of character
    int getHealth();
    int getArmour();
    int getPower();

    // set player's character, with 'sprite' and 'character' integer as parameters
    void setCharacter(DynamicSprite* sprite, int character);

    // return sprite 
    DynamicSprite* getSprite();

    // attacks opponent
    void attack(Entity* entity);

    // update the render window
    bool update(sf::RenderWindow* window);
    void draw(sf::RenderWindow* window);

protected:
    // pointer to a sprite
    DynamicSprite* sprite;

    // stats of character
    int health;
    int armour;
    int power;

    // character integer used to identify which sprite
    int character;
};

#endif
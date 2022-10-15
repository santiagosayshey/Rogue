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
    float updateHealth(float health);
    void updateArmour(float armour);
    void updatePower(float Power);

    // return individual stats of character
    float getHealth();
    float getArmour();
    float getPower();

    // set player's character, with 'sprite' and 'character' integer as parameters
    void setCharacter(DynamicSprite* sprite, int character);

    // return sprite 
    DynamicSprite* getSprite();

    // attacks another entity
    virtual std::string attack(Entity* entity);

    // update and draw the render window
    bool update(sf::RenderWindow* window);
    void draw(sf::RenderWindow* window);

    // return the type of character chosen
    int returnChar();

    void setOGPower(int power);

    // return original power
    float getOGPower();

    void incrementAction();

    std::string getFirstMove();

protected:
    // pointer to a sprite
    DynamicSprite* sprite;

    // stats of character
    float health;
    float armour;
    float power;

    // character integer used to identify which sprite
    int character;

    float originalPower;

    int currentAction=1;

    std::string firstMove;
};

#endif
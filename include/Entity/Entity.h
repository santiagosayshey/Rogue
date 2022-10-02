#ifndef ENTITY_H
#define ENTITY_H

#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

#include "../Drawable/Sprite.h"

class Entity
{
public:
    void chooseRole(int role);
     
    void setChararacter(Sprite* sprite);

    void updateRole(int role);
    void updateHealth(int health);
    void updateArmour(int armour);
    void updateDamage(int damage);
    void updateAccuracy(int accuracy);
    void updateEvasion(int evasion);

    int getRole();

    Sprite* getSprite();

    int getHealth();
    int getArmour();
    int getDamage();
    int getAccuracy();
    int getEvasion();

    void attack(Entity* entity);

    bool update(sf::RenderWindow* window);
    void draw(sf::RenderWindow* window);

protected:
    Sprite* sprite;

    int role;

    int health;
    int armour;
    int damage;
    int accuracy;
    int evasion;
    int strength;
    int weakness;
    int neutral;

    bool dead;

};

#endif
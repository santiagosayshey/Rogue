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
    // set entity variables

        // stats
        float setHealth(float health);
        void setArmour(float armour);
        void setPower(float Power);
        void setPowerBuffer(int power);
        int getID();
        std::string getFirstMove();

        //sprites
        void setCharacter(DynamicSprite* sprite, int ID);
        void setGUI(std::string type);

    // get entity variables

        // stats
        float getHealth();
        float getArmour();
        float getPower();
        float getPowerBuffer();

        // sprites
        DynamicSprite* getSprite();
        Sprite* getGUI();
        
    // behaviour
    
        // attack another entity
        virtual std::string attack(Entity* entity);
    
        // increment the behaviour array
        void incrementAction();    

protected:

    // entity character model
    DynamicSprite* sprite;
    // GUI sprite
    Sprite* gui;

    // stats
    float health;
    float armour;
    float power;
    float powerBuffer;
    int ID;
    int currentAction=1;
    std::string firstMove;

    
};

#endif
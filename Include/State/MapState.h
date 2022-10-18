#ifndef MAPSTATE_H
#define MAPSTATE_H

#pragma once

#include "State.h"
#include "../Drawable/Sprite.h"
#include "../Drawable/Text.h"

class MapState : public State
{
public:
    // pass the game instance to allow the map state to change the game state
    MapState(Game* game, Player* player);

    // deconstructor
    ~MapState();

     // menu instance of update and render
    void update(sf::RenderWindow* window);
    void render(sf::RenderWindow* window);

    // increment the current level
    void incrementLVL();

    // set the level to anything, mostly used to reset back to 0
    void setLVL(int lvl);

private:
    // events needed for event manager within update
    sf::Event event;

    // splash screen
    Sprite* mapTemplate;

    // levels - lvl, enemy and transparent versions for collision
    Sprite* lvl;
    Sprite* lvlHover;
    Sprite* enemy;
    Sprite* enemyHover;
    
    Sprite* lvl2;
    Sprite* lvl2Hover;
    Sprite* enemy2;
    Sprite* enemyHover2;

    Sprite* lvl3;
    Sprite* lvl3Hover;
    Sprite* enemy3;
    Sprite* enemyHover3;

    Sprite* lvl4;
    Sprite* lvl4Hover;
    Sprite* boss;
    Sprite* bossHover;

    // booleans to tell if the mouse is colliding with each level
    bool hover1=false;
    bool hover2=false;
    bool hover3=false;
    bool hover4=false;

    // integer to represent the current level and limit the player clicks
    int currentLVL=1;
    
    // prompt, white not needed since on brown background
    Text* b_prompt;
};

#endif
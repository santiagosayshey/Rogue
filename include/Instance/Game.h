#ifndef GAME_H
#define GAME_H

#pragma once

#include "SFML/Graphics.hpp"
#include "../State/State.h"
#include "../State/MenuState.h"
#include "../State/MapState.h"
#include "../Entity/Player.h"
#include "../Entity/Golem.h"
#include "../Entity/Viking.h"
#include "../Entity/Pilgrim.h"
#include "../Entity/Brute.h"
#include "Path.h"

class Game
{
public:
    // constructor - init width and height used to render window
    Game(int width, int height); 

    // default destructor
    ~Game(); 

    // starts the game by initialising the game loop
    void run();

    // create the enemy array
    // will eventually be random
    void initEnemies();

    // sets current game state
    void setState(State* newState);  

    // creates a path to access audio and visual files
    Path* p = new Path;

    // map pointer
    MapState* map;

    // initiate hover, which will be used to access audio file "e_hover" 
    sf::SoundBuffer hover;

    // return enemy
    Entity* returnEnemy();

    // update the current enemy
    void updateCurrentEnemy();

    // reset enemies in case of player death
    void resetEnemy();



private:
    // create a pointer to window
    sf::RenderWindow* window;

    // create a pointer to currentState
    State* currentState;

    // create a pointer to player
    Player* player;

    // create an array of enemies that the play state will iterate through
    Entity* enemyArr[4];

    // current enemy
    int currentEnemy;

    Entity* golem;
    Entity* viking;
    Entity* pilgrim;
    Entity* brute;


};

#endif
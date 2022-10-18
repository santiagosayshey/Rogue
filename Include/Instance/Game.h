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
    // constructor - set the resolution of the game
    // create instances of path, player, enemies, etc
    Game(int width, int height); 

    // default destructor
    ~Game(); 

    // instance managers

        // starts the game by initialising the game loop
        void run();

        // sets current game state
        void setState(State* newState);  

    // enemies

        // initialise enemies
        void initEnemies();

        // return cenemy
        Entity* returnEnemy();

        // set new enemy by passing a pre determined ID
        void setEnemy(int n);

        // increment the enemy array to change levels
        void incrementEnemy();

        // reset enemies in case of player death
        void resetEnemy();

        // return the current enemy for sake of player win / death
        int getCurrentEnemy();

    // states / structures

        // set a new map
        void setMap(MapState* map);

        // return the map to change levels
        MapState* getMap();

        // return the path to access sprites / sounds
        Path* getPath();

private:
    // create a pointer to window
    sf::RenderWindow* window;

    // create a pointer to currentState
    State* currentState;

    // create a pointer to player
    Player* player = new Player();

    // pointer to path structure
    Path* path = new Path();

    // map instance pointer - overriden on new game
    MapState* map;

    // create an array of enemies that the play state will iterate through
    Entity* enemyArr[4];

    // current enemy
    int currentEnemy = 0;

    // predetermined enemies that will be randomised on initilsation
    Entity* golem;
    Entity* viking;
    Entity* pilgrim;
    Entity* brute;
};

#endif
#ifndef State_H
#define State_H

#pragma once

#include "SFML/Graphics.hpp"

// forward declaration of game and player to avoid circular dependancy
class Game;
class Player;


class State
{
public:

    /* store the game and player inside the state class 
    as both will be carried through the entire scope */
    State(Game* game, Player* player);

    // gather any drawable updates together within a single state
    virtual void update(sf::RenderWindow* window) = 0; 

    // render the gathered drawables in the frame
    // clear the previous window, draw the new objects and display it in the render window
    virtual void render(sf::RenderWindow* window) = 0;


protected:

    // declare a pointer to the game instance
    Game* game;

    // declare a pointer to the player instance
    Player* player;

};

#endif
#ifndef DRAWABLE_H
#define DRAWABLE_H

#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

class Game;

class Drawable
{
public:
    // initialise virtual abstract functions checkCollision, update, and draw
    virtual bool checkCollision(sf::RenderWindow* window) = 0;
    virtual void update(sf::RenderWindow* window) = 0;
    virtual void draw(sf::RenderWindow* window) = 0;

private:

};

#endif
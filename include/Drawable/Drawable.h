#ifndef DRAWABLE_H
#define DRAWABLE_H

#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

class Game;

class Drawable
{
public:
    virtual bool checkCollision(sf::RenderWindow* window) = 0;
    virtual void update(sf::RenderWindow* window, Game* game) = 0;
    virtual void draw(sf::RenderWindow* window) = 0;

private:

};

#endif
#ifndef DRAWABLE_H
#define DRAWABLE_H

#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

class Game;

class Drawable
{
public:
    /* pass the renderwindow to the drawable so that it can draw itself
    in the current frame */
    virtual void draw(sf::RenderWindow* window)=0;
private:

};

#endif
#ifndef SPRITE_H
#define SPRITE_H

#pragma once
#include "Drawable.h"

class Sprite : public Drawable
{
public:
    // constructor - set sprite visual style
    Sprite(std::string texture, int x, int y, int width, int height, float scale);

    // default destrcutor
    ~Sprite();
    
    // pass the render window to the sprite so that it can draw itself
    void draw(sf::RenderWindow* window);

    // check whether the current sprite is colliding with another 'drawable'
    bool checkCollision(sf::RenderWindow* window);

    // move the sprite to a new position in the frame
    void setPosition(int x, int y);

    // return the bounds of the current sprite
    int getX();
    int getY();

    // flip the sprite on its vertical axis to mirror it
    void flip();

protected:
    // sfml drawables to be drawn in render window
    sf::Texture* texture;
    sf::Sprite* sprite;
    
    // position / bounds of the sprite / mouse for button clicking
    sf::Vector2f mouse;
    sf::FloatRect bounds;

    // size of the sprite
    int height;
    int width;

    // position of the sprite
    int x;
    int y;

};


#endif
#ifndef SPRITE_H
#define SPRITE_H

#pragma once
#include "Drawable.h"

class Sprite : public Drawable
{
public:
    // constuctor - init size, scale and position. Set chosen sf::sprite
    Sprite(std::string texture, int x, int y, int width, int height, float scale);

    // default destrcutor
    ~Sprite();

    
    // pass the render window to the sprite so that it can update itself
    void update(sf::RenderWindow* window);
    
    // update the current animation values to be used in animation()
    void updateAnimation(int numFrames, int row);

    // move the sprite to a new position in the render window
    // instantly moves the sprite
    // position defined by parameters x, y
    void setPos(int x, int y);

    // dynamically move the sprite to a new position in the render window defined by parameter d
    // slowly move the sprite to simulate movement
    void move(int d);

    // flip the sprite on its vertical axis "mirroring it"
    void flip();

    // check whether the current sprite is colliding with another 'drawable'
    bool checkCollision(sf::RenderWindow* window);

    // update the current texture rectangle of the current sprite sheet based
    // number of frames and current row defined by updateAnimation
    bool animation(bool repeat);

    // pass the render window to the sprite so that it can draw itself
    void draw(sf::RenderWindow* window);


    // return the bounds of the current sprite
    int getX();
    int getY();


protected:

    // sfml drawables to be drawn in render window
    sf::Texture* texture;
    sf::Sprite* sprite;


    // clock used to update animation()
    sf::Clock clock;
    

    // position / bounds of the sprite / mouse for button clicking
    sf::Vector2f mouse;
    sf::FloatRect bounds;

    // values used to define animation()
    int numFrames;
    int currentFrame;
    int row;

    // size of the sprite
    int height;
    int width;

    // position of the sprite
    int x;
    int y;

};


#endif
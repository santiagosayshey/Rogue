#ifndef DYNAMICSPRITE_H
#define DYNAMICSPRITE_H

#pragma once
#include "Sprite.h"

class DynamicSprite : public Sprite
{
public:
    // constructor - sets same visual style as parent
    DynamicSprite(std::string texture, int x, int y, int width, int height, float scale);
    
    // destructor
    ~DynamicSprite();

    // update the current animation values to be used in animation()
    void updateAnimation(int numFrames, int row);

    // update the current texture rectangle of the sprite
    /* iterate through a number of frames in a row of the sprite sheet
    to simulate movement */
    bool animation(bool repeat, bool death);

private:
    // values used to define animation()
    int numFrames;
    int currentFrame;
    int row;

    // clock used to update animation()
    sf::Clock clock;
};

#endif
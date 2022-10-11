#ifndef DYNAMICSPRITE_H
#define DYNAMICSPRITE_H

#pragma once
#include "Sprite.h"

class DynamicSprite : public Sprite
{
public:
    // constructor
    DynamicSprite(std::string texture, int x, int y, int width, int height, float scale);
    ~DynamicSprite();

    // update the current animation values to be used in animation()
    void updateAnimation(int numFrames, int row);

    // update the current texture rectangle of the current sprite sheet based
    // number of frames and current row defined by updateAnimation
    bool animation(bool repeat, bool death);

    // return the sf sprite
    sf::Sprite* getSFSprite();

private:
    // values used to define animation()
    int numFrames;
    int currentFrame;
    int row;
};

#endif
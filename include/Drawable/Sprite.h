#ifndef SPRITE_H
#define SPRITE_H

#pragma once
#include "Drawable.h"

class Sprite : public Drawable
{
public:
    Sprite(std::string texture, int x, int y, int width, int height, float scale);
    ~Sprite();

    
    void update(sf::RenderWindow* window);
    void updateAnimation(int numFrames, int row);

    void setPos(int x, int y);
    void move(int d);
    void flip();
    bool checkCollision(sf::RenderWindow* window);

    bool animation(bool repeat);
    void draw(sf::RenderWindow* window);

    int getX();
    int getY();


protected:
    sf::Texture* texture;
    sf::Sprite* sprite;

    sf::Clock clock;
    
    sf::Vector2f mouse;
    sf::FloatRect bounds;

    int numFrames;
    int currentFrame;
    int row;

    int height;
    int width;

    int x;
    int y;

};

#endif
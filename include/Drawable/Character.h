#ifndef CHARACTER_H
#define CHARACTER_H

#pragma once
#include "Drawable.h"

class Character : public Drawable
{
public:
    Character(std::string texture, int x, int y, int size);
    ~Character();

    
    void update(sf::RenderWindow* window);
    void updateAnimation(int numFrames, int row);

    void setPos(int x, int y);
    void flip();
    bool checkCollision(sf::RenderWindow* window);

    bool animation(bool repeat);
    void draw(sf::RenderWindow* window);


protected:
    sf::Texture* texture;
    sf::Sprite* sprite;

    sf::Clock clock;
    
    sf::Vector2f mouse;
    sf::FloatRect bounds;

    int numFrames;
    int currentFrame;
    int row;

    int size;

};

#endif
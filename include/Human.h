#ifndef HUMAN_H
#define HUMAN_H

#pragma once
#include "Entity.h"

class Human : public Entity
{
public:
    Human(std::string texture);
    ~Human();

    virtual bool checkCollision(sf::RenderWindow* window) = 0;
    virtual void update(sf::RenderWindow* window, Game* game) = 0;
    void draw(sf::RenderWindow* window);

protected:
    sf::Vector2f mouse;
    sf::FloatRect bounds;

    sf::Texture* texture;
    sf::Sprite* sprite;

};

#endif
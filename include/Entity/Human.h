#ifndef HUMAN_H
#define HUMAN_H

#pragma once
#include "../Entity/Entity.h"

class Human : public Entity
{
public:
    Human(std::string texture, int x, int y);
    ~Human();

    
    void update(sf::RenderWindow* window, Game* game);
    void updateSprite(int numFrames, int row);

    void setPos(int x, int y);
    bool checkCollision(sf::RenderWindow* window);

    void animation(bool repeat);
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

};

#endif
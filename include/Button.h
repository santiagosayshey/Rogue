#ifndef Button_H
#define Button_H

#pragma once
#include "Entity.h"

class Button : public Entity
{
public:
    Button();
    ~Button();

    bool checkCollision(sf::RenderWindow* window);

    void update(sf::RenderWindow* window, Game* game);
    void draw(sf::RenderWindow* window);


protected:
    sf::Vector2f mouse;
    sf::FloatRect bounds;
    
    sf::Text text;
    sf::Font font;
};

#endif
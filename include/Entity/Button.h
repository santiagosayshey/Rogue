#ifndef Button_H
#define Button_H

#pragma once
#include "Entity.h"

class Button : public Entity
{
public:
    Button(std::string f, int s, sf::Color c, sf::Text::Style style, std::string type, int x, int y, int state);
    ~Button();

    bool checkCollision(sf::RenderWindow* window);
    void update(sf::RenderWindow* window, Game* game);
    void draw(sf::RenderWindow* window);


private:
    sf::Vector2f mouse;
    sf::FloatRect bounds;
    
    sf::Text text;
    sf::Font font;
    int state;
};

#endif
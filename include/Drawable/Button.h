#ifndef Button_H
#define Button_H

#pragma once
#include "Drawable.h"

class Button : public Drawable
{
public:
    Button(std::string f, int s, sf::Color c, sf::Text::Style style, std::string type, int x, int y);
    ~Button();

    bool checkCollision(sf::RenderWindow* window);
    void update(sf::RenderWindow* window);
    void draw(sf::RenderWindow* window);


private:
    sf::Vector2f mouse;
    sf::FloatRect bounds;
    
    sf::Text text;
    sf::Font font;
};

#endif
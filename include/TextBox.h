#ifndef TEXTBOX_H
#define TEXTBOX_H

#pragma once

#include "SFML/Graphics.hpp"
#include <string>

class Game;

class TextBox
{
public:
    TextBox();
    ~TextBox();

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
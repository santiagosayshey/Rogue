#ifndef TEXTBOX_H
#define TEXTBOX_H

#pragma once

#include "SFML/Graphics.hpp"
#include <string>

class Game;

class TextBox
{
public:
    TextBox(int s, sf::Color c, std::string string, int x, int y);
    ~TextBox();

    bool checkCollision(sf::RenderWindow* window);

    void update(sf::RenderWindow* window, Game* game, State);
    void draw(sf::RenderWindow* window);


private:
    sf::Vector2f mouse;
    sf::FloatRect bounds;
    
    sf::Text text;
    sf::Font font;
    sf::Color c;
};

#endif
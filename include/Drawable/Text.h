#ifndef Text_H
#define Text_H

#pragma once
#include "Drawable.h"

class Text : public Drawable
{
public:
    Text(std::string f, int s, sf::Color c, sf::Text::Style style, std::string type, int x, int y);
    ~Text();

    bool checkCollision(sf::RenderWindow* window);
    void update(sf::RenderWindow* window);
    void updateText(std::string s);
    void draw(sf::RenderWindow* window);
    int getX();
    int getY();
    void setPos(int x, int y);


private:
    sf::Vector2f mouse;
    sf::FloatRect bounds;
    
    sf::Text text;
    sf::Font font;

    int x;
    int y;

};

#endif
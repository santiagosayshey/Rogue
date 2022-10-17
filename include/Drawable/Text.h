#ifndef Text_H
#define Text_H

#pragma once
#include "Drawable.h"

class Text : public Drawable
{
public:
    // set text parameters to change visual style in constructor
    Text(std::string f, int s, sf::Color c, sf::Text::Style style, std::string type, int x, int y);

    // default destructor
    ~Text();

    // pass the render window to check for collision
    bool checkCollision(sf::RenderWindow* window);

    // pass the render window to be updated
    void update(sf::RenderWindow* window);

    // update the text to be displayed
    void updateText(std::string s);

    // pass the render window to display text
    void draw(sf::RenderWindow* window);

    // return x position of text
    int getX();

    // return y position of text
    int getY();

    // move the text to a new position in the render window
    // position defined by parameters x, y
    void setPos(int x, int y);


private:
    // position / bounds of the text / mouse for button clicking
    sf::Vector2f mouse;
    sf::FloatRect bounds;
    
    // text to be displayed in render window
    sf::Text text;
    sf::Font font;

    // position of text
    int x;
    int y;

};

#endif
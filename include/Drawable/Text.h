#ifndef Text_H
#define Text_H

#pragma once
#include "Drawable.h"

class Text : public Drawable
{
public:
    // constructor - set text visual style
    Text(std::string f, int s, sf::Color c, sf::Text::Style style, std::string type, int x, int y);

    // default destructor
    ~Text();

    // update the text string during the update cycle
    void updateText(std::string s);

    // pass the render window to display text
    void draw(sf::RenderWindow* window);

    // return x origin of sprite
    int getX();

    // return y origin of text
    int getY();

    // place the text in a new position in the render window instantly
    void setPos(int x, int y);


private:
    // text to be displayed in render window
    sf::Text text;
    sf::Font font;

    // position of text
    int x;
    int y;

};

#endif
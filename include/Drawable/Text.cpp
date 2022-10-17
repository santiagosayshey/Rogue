#include "Text.h"
#include <iostream>

Text::Text(std::string f, int s, sf::Color c, sf::Text::Style style, std::string type, int x, int y)
{ 
    // take x,y values and store as current position
    this->x = x;
    this->y = y;

    // set font of text
    font.loadFromFile(f);
    text.setFont(font);

    // set position of text
    text.setPosition(x,y);

    // set text size
    text.setCharacterSize(s);

    // set colour of text
    text.setFillColor(c);

    // set text style
    text.setStyle(style);

    // set text string
    setText(type);
}

Text::~Text(){}


void Text::draw(sf::RenderWindow* window)
{
    window->draw(text);
}

void Text::setText(std::string s)
{
    text.setString(s);
}

void Text::setPosition(int x, int y)
{
    text.setPosition(x, y);
}


int Text::getX()
{
    return x;
}

int Text::getY()
{
    return y;
}



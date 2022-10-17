#include "Text.h"
#include <iostream>

Text::Text(std::string f, int s, sf::Color c, sf::Text::Style style, std::string type, int x, int y)
{ 
    // set init values as parameters
    this->x = x;
    this->y = y;
    // set font of text
    // seg faults if fonts and texts are pointers????
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

    // set text type
    text.setString(type);
}

Text::~Text(){}

bool Text::checkCollision(sf::RenderWindow* window)
{
    // find the bounds of the mouse
    sf::Vector2f mouse = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
    
    // find the bounds of the text
    sf::FloatRect bounds = text.getGlobalBounds();
    // std::cout << "Check collision successful" << std::endl;

    // return a boolean that defines whether the bounds of the text contains the bounds of the mouse
    return bounds.contains(mouse);
}

void Text::update(sf::RenderWindow* window) // this needs to go in event manager
{ 
/*  if (!checkCollision(window))  {
        // set colour to black if collision does not occur
        text.setFillColor(sf::Color::Black);
    }
    else {
        // set colour to blue if collision occurs
        text.setFillColor(sf::Color::Blue);
    } */
}

void Text::updateText(std::string s)
{
    // update text displayed in the render window
    text.setString(s);
    // std::cout << "Text updated" << std::endl;
}

void Text::draw(sf::RenderWindow* window)
{
    // draw text in the render window
    window->draw(text);
    // std::cout << "Text drawn" << std::endl;
}

int Text::getX()
{
    // return x position of text
    return x;
}

int Text::getY()
{
    // return y position of text
    return y;
}


void Text::setPos(int x, int y)
{
    text.setPosition(x, y);
    // std::cout << "Text position set" << std::endl;
}

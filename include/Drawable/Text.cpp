#include "Text.h"
#include <iostream>

Text::Text(std::string f, int s, sf::Color c, sf::Text::Style style, std::string type, int x, int y)
{ 
    this->x = x;
    this->y = y;
    // seg faults if fonts and texts are pointers????
    font.loadFromFile(f);
    text.setFont(font);
    text.setPosition(x,y);
    text.setCharacterSize(s);
    text.setFillColor(c);
    text.setStyle(style);
    text.setString(type);
}

Text::~Text()
{ }

bool Text::checkCollision(sf::RenderWindow* window)
{
    sf::Vector2f mouse = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
    sf::FloatRect bounds = text.getGlobalBounds();

    
    return bounds.contains(mouse);
}

void Text::update(sf::RenderWindow* window) // this needs to go in event manager
{ 
/*     if (!checkCollision(window))  {
        text.setFillColor(sf::Color::Black);
    }
    else {
        text.setFillColor(sf::Color::Blue);
    } */
}

void Text::updateText(std::string s)
{
   
    text.setString(s + " / 75");
}

void Text::draw(sf::RenderWindow* window)
{
    window->draw(text);
}

int Text::getX()
{
    return x;
}

int Text::getY()
{
    return y;
}


void Text::setPos(int x, int y)
{
    text.setPosition(x, y);
}

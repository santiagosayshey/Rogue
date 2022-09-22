#include "TextBox.h"
#include "Game.h"

TextBox::TextBox()
{ }

TextBox::~TextBox()
{ }

bool TextBox::checkCollision(sf::RenderWindow* window)
{
    sf::Vector2f mouse = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
    sf::FloatRect bounds = text.getGlobalBounds();

    return bounds.contains(mouse);
}


void TextBox::update(sf::RenderWindow* window, Game* game)
{ }

void TextBox::draw(sf::RenderWindow* window)
{
    window->draw(text);
}





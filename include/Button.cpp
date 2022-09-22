#include "Button.h"
#include "Game.h"

Button::Button()
{ }

Button::~Button()
{ }

bool Button::checkCollision(sf::RenderWindow* window)
{
    sf::Vector2f mouse = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
    sf::FloatRect bounds = text.getGlobalBounds();

    return bounds.contains(mouse);
}


void Button::update(sf::RenderWindow* window, Game* game)
{ }

void Button::draw(sf::RenderWindow* window)
{
    window->draw(text);
}





#include "Button.h"
#include "Game.h"
#include "PlayState.h"

Button::Button(std::string f, int s, sf::Color c, sf::Text::Style style, std::string type, int x, int y, int state)
{ 
    // seg faults if fonts and texts are pointers????
    font.loadFromFile(f);
    text.setFont(font);
    text.setCharacterSize(s);
    text.setFillColor(c);
    text.setStyle(sf::Text::Bold);
    text.setString(type);
    text.setPosition(x,y);
    // how to pass an abstract type as a parameter??
    this->state = state;
}

Button::~Button()
{ }

bool Button::checkCollision(sf::RenderWindow* window)
{
    sf::Vector2f mouse = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
    sf::FloatRect bounds = text.getGlobalBounds();

    return bounds.contains(mouse);
}


void Button::update(sf::RenderWindow* window, Game* game)
{ 
    if (!checkCollision(window))  {
        text.setFillColor(sf::Color::Black);
    }
    else {
        text.setFillColor(sf::Color::Blue);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            switch (state) {
                case 1: 
                    game->setState(new PlayState(game));
                    break;
/*                 case 2:
                    game->setState(new OptionsState(game));
                    break; */
                case 3: 
                    window->close();
                    break;
            }
    }
}

void Button::draw(sf::RenderWindow* window)
{
    window->draw(text);
}





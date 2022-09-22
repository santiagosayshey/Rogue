#include "TextBox.h"
#include "Game.h"
#include "PlayState.h"

TextBox::TextBox(int s, sf::Color c, std::string string, int x, int y)
{
    // seg faults if fonts and texts are pointers????
    font.loadFromFile("assets/font/upheavtt.ttf");
    text.setFont(font);
    text.setCharacterSize(s);
    text.setFillColor(c);
    text.setStyle(sf::Text::Bold);
    text.setString(string);
    text.setPosition(x,y);

    this->c = c;
}

TextBox::~TextBox()
{ }

bool TextBox::checkCollision(sf::RenderWindow* window)
{
    sf::Vector2f mouse = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
    sf::FloatRect bounds = text.getGlobalBounds();

    return bounds.contains(mouse);
}


void TextBox::update(sf::RenderWindow* window, Game* game, State)
{
        if (!checkCollision(window))  {
            text.setFillColor(sf::Color::Black);
        }
        else {
            text.setFillColor(sf::Color::Blue);
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                game->setState(new PlayState(game));
            }
        }
}

void TextBox::draw(sf::RenderWindow* window)
{
    window->draw(text);
}





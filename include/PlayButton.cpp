#include "PlayButton.h"
#include "Game.h"
#include "PlayState.h"

PlayButton::PlayButton(int s, sf::Color c, std::string string, int x, int y)
{
    // seg faults if fonts and texts are pointers????
    font.loadFromFile("assets/font/upheavtt.ttf");
    text.setFont(font);
    text.setCharacterSize(s);
    text.setFillColor(c);
    text.setStyle(sf::Text::Bold);
    text.setString(string);
    text.setPosition(x,y);
}

PlayButton::~PlayButton()
{

}
void PlayButton::update(sf::RenderWindow* window, Game* game) {

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